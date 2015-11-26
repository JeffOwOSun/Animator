#include "ParticleSource.h"
#include <cmath>
#define PI 3.14159265358979

void ParticleSource::newParticles(Particles& particles) {
	//initialize the particles
	for (int i = 0; i < m_numParticles; ++i) {
		Particle particle;
		Mat4d mtx = getTransMatrix();
		particle.life = m_initialLife;
		particle.position = mtx * particle.position;
		double theta = 2 * PI * theta_distribution(generator);
		double phi = m_angle / 180.0 * PI * phi_distribution(generator);
		double speed = m_minSpeed + speed_distribution(generator) * (m_maxSpeed - m_minSpeed);
		Vec3d velocity;
		if (abs(tan(phi)) < DBL_EPSILON) {
			velocity = Vec3d(0, 0, (phi < PI / 2) ? 1 : -1);
		}
		else {
			velocity = Vec3d(cos(theta), sin(theta), 1 / tan(phi));
			velocity.normalize();
		}
		
		particle.velocity = (mtx * velocity - particle.position) * speed;

		particles.push_back(particle);
	}
}

void ParticleSource::onDraw()
{
	//DO NOTHING	
}

ParticleSource::~ParticleSource() {}