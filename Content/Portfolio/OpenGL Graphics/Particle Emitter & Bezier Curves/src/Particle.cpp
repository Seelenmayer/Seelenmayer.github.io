/**
 * @file Controller.h
 * @brief This header contains the implementations needed for generating particles.
 * @author Clayton Seelenmayer
 * @date Dec 1st 2018
 */

//Includes
#include "Particle.h"



//Populate Particles
vector<Particle> Emitter::Populate(){

	//Create Particles
	Particle Temp;
	vector<Particle> ParticleList;
	for (int i=0 ; i<this->Properties.SpawnCount ; i++){

		//Initialize Properties
		ParticleProperties Prop;
		Prop.Position    = this->Properties.Position;
		Prop.StartColour = {1.0f, 0.0f, 1.0f};
		Prop.DeathColour = {0.0f, 0.0f, 1.0f};
		Prop.Size        = 3.0f;

		//Direction Property
		Prop.Velocity  = Temp.GenerateVelocity(Prop.Position);

		//Lifespan Property
		Prop.LifeSpan  = 5.0f;
		Prop.StartTime = Time;
		Prop.EndTime   = Prop.StartTime + Prop.LifeSpan;

		//Assign Properties
		Temp.setProperties(Prop);
		ParticleList.push_back(Temp);
	}
	return ParticleList;
}



//Generate Particle Velocity
vector3 Particle::GenerateVelocity(vector3 Center){

	//Calculate Random Velocity
	float X = (float) (rand()) / (float) (RAND_MAX) - 0.5f;
	float Y = (float) (rand()) / (float) (RAND_MAX) - 0.5f;
	float Z = 0.0f;//(float) (rand()) / (float) (RAND_MAX) - 0.5f;
	vector3 Velocity = {X, Y, Z};

	//Clamp To Circle
	float Radius = 0.5f; 
	float Distance = sqrt(X*X + Y*Y);
	if (Distance > Radius){
		vector3 OriginToPoint = Velocity - Center;
		OriginToPoint *= Radius / Distance;
		Velocity = Center + OriginToPoint;
	}

	return Velocity;
}



//Age Particles
void Particle::Age(){

	//Get Particle Properties
	ParticleProperties Prop = this->Properties;

	//Elapsed Time
	float TimeScale = (Time - Prop.StartTime)/Prop.LifeSpan;

	//Linearly Interpolate Colour Components
	float X1 = Lerp(Prop.StartColour.X(), Prop.DeathColour.X(), TimeScale);
	float Y1 = Lerp(Prop.StartColour.Y(), Prop.DeathColour.Y(), TimeScale);
	float Z1 = Lerp(Prop.StartColour.Z(), Prop.DeathColour.Z(), TimeScale);

	//Assign Colours
	Prop.Colour.X(X1);
	Prop.Colour.Y(Y1);
	Prop.Colour.Z(Z1);
	this->Properties = Prop;
}



//Linear Interpolation Function
float Particle::Lerp(float Point1, float Point2, float t){

	//Interpolated Point Between 2 Control Points
	float InterpolatedPoint = Point1 + (Point2 - Point1) * t;
	return InterpolatedPoint;
}
