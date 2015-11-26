#include "ParticleSource.h"
#include <cmath>
#define PI 3.14159265358979

void ParticleSource::newParticles(Particles& particles) {
	//initialize the particles
	for (int i = 0; i < m_numParticles; ++i) {
		Particle particle;
		particle.life = m_initialLife;

		double theta = 2 * PI * theta_distribution(generator1);
		double phi = m_angle / 180.0 * PI * phi_distribution(generator2);
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

void ParticleSource::onDraw()
{
	//DO NOTHING	
}

ParticleSource::~ParticleSource() {}