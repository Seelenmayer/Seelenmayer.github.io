/**
 * @file Controller.h
 * @brief This header contains the prototypes necessary for generating particles and altering their behaviour.
 * @author Clayton Seelenmayer
 * @date Dec 1st 2018
 */

#ifndef PARTICLE_H
#define PARTICLE_H

//Includes
#include "Main.h"
using namespace std;

//Prototypes
class Emitter;
class Particle;

//Properties
struct EmitterProperties{
	vector3 Position;
	vector3 Colour;
	float   Size;
	int     SpawnCount;
};

struct ParticleProperties{
	vector3 Position;
	vector3 StartColour;
	vector3 Colour;
	vector3 DeathColour;
	float   Size;
	vector3 Velocity;
	float   LifeSpan;
	float   StartTime;
	float   EndTime;
};

//Emitter Object
class Emitter{

	private:
		EmitterProperties Properties;
		int SpawnCount;

	public:
		Emitter(){}
		Emitter(EmitterProperties P){Properties = P;}
		~Emitter(){}
		EmitterProperties getProperties(){return Properties;}
		void setProperties(EmitterProperties P){Properties = P;}
		vector<Particle> Populate();
};

//Particle Object
class Particle{

	private:
		ParticleProperties Properties;
		float Lerp(float Point1, float Point2, float t);

	public:
		Particle(){}
		Particle(ParticleProperties P){Properties = P;}
		~Particle(){}
		ParticleProperties getProperties(){return Properties;}
		void setProperties(ParticleProperties P){Properties = P;}
		vector3 GenerateVelocity(vector3 Center);
		void Age();
};

#endif