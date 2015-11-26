#include "ParticleSource.h"
#include <cmath>
#define PI 3.14159265358979

void ParticleSource::newParticles(int num) {
	auto iter = cache.rbegin();
	Particles& particles = iter->second;
	//initialize the particles
	for (int i = 0; i < num; ++i) {
		Particle particle;
		particle.life = m_initialLife;

		double theta = 2 * PI * theta_distribution(generator1);
		double phi = m_angle / 180 * PI * phi_distribution(generator2);
		double speed = m_minSpeed + speed_distribution(generator3) * (m_maxSpeed - m_minSpeed);
		Vec3d velocity;
		if (abs(tan(phi)) < DBL_EPSILON) {
			velocity = Vec3d(0, 0, (phi < PI / 2) ? 1 : -1);
		}
		else {
			velocity = Vec3d(cos(theta), sin(theta), 1 / tan(phi));
			velocity.normalize();
		}
			
		particle.velocity = velocity * speed;

		particles.push_back(particle);
	}
}

void ParticleSource::propagate(float delta_t) {
	auto iter = cache.rbegin();
	Particles& old_particles = iter->second;
	Particles& new_particles = cache[iter->first + delta_t];
	//calculate the particles
	for (auto i = old_particles.begin(); i != old_particles.end(); ++i) {
		Particle newPar;
		Particle& old_particle = *i;
		newPar.life = old_particle.life - delta_t;

		//kill the ones that are dead
		if (newPar.life < 0) {
			continue;
		}

		//evolve
		newPar.position = old_particle.position + old_particle.velocity * delta_t;
		newPar.velocity = old_particle.velocity + (getController()->getMatrix * m_gravity) * delta_t;

		new_particles.push_back(newPar);
	}
}

void ParticleSource::onDraw()
{
	auto iter = cache.find(m_time);
	if (iter == cache.end()) return; //do nothing if this frame is not yet baken

	Particles& particles = iter->second;
	for (Particle & particle : particles) {
		glPushMatrix();
		glTranslated(particle.position[0], particle.position[1], particle.position[2]);
		drawSphere(0.1);
		glPopMatrix();
	}
}

ParticleSource::~ParticleSource() {}