/**
 * @file Main.h
 * @brief This file contains the prototypes needed for 4x4 matric multiplication against 3x1 vectors.
 * @author Clayton Seelenmayer
 * @date Dec 1st 2018
 */

#ifndef MATRIX_H
#define MATRIX_H

class Matrix{

	private:

		//Variables
		float Data[16];
		float &operator[](int index){return Data[index];}

	public:

		//Functions
		Matrix(){
			for(int i=0 ; i<16 ; i++){
				if (i%5 == 0) 
					Data[i] = 1;
				else
					Data[i] = 0;
			}
		}
		~Matrix(){}
		float* getData(){return Data;}

		//Calculate Arbitrary Axis of Rotation
		void setRotationMatrix(float a, vector3 v){

			//Rotation of angle a about axis v on a collumn major matrix.
			float a1 = cos(a);
			float a2 = sin(a);

			Data[0]  = a1 + v.X() * v.X() * (1-a1);
			Data[1]  = v.Y() * v.X() * (1-a1) + v.Z() * a2;
			Data[2]  = v.Z() * v.X() * (1-a1) - v.Y() * a2;
			Data[3]  = 0;

			Data[4]  = v.X() * v.Y() * (1-a1) - v.Z() * a2;
			Data[5]  = a1 + v.Y() * v.Y() * (1-a1);
			Data[6]  = v.Z() * v.Y() * (1-a1) + v.X() * a2;
			Data[7]  = 0;

			Data[8]  = v.X() * v.Z() * (1-a1) + v.Y() * a2;
			Data[9]  = v.Y() * v.Z() * (1-a1) - v.X() * a2;
			Data[10] = a1 + v.Z() * v.Z() * (1-a1);
			Data[11] = 0;

			Data[12] = 0;
			Data[13] = 0;
			Data[14] = 0;
			Data[15] = 1;
		}

		//Vector Multiply
		vector3 VectorMultiply(Matrix m, vector3 v){
			float Vector[4] = {v.X(), v.Y(), v.Z(), 0.0f};
			for (int i=0 ; i<3 ; i++){
				for (int j=0 ; j<3 ; j++){
					Vector[i] += m[i*j] * v[j];
				}
			}
			vector3 ResultingVector = {Vector[0], Vector[1], Vector[2]};
			return ResultingVector;
		}

		//Matrix Multiply
		void MatrixMultiply(Matrix m1, Matrix m2){
			for (int i=0 ; i<4 ; i++){
				for (int j=0 ; j<4 ; j++){
					float Sum = 0;
					for (int k=0 ; k<4 ; k++){
						Sum += m1[i*4+k] * m2[k*4+j];
					}
					Data[i*4+j] = Sum;
				}
			}
		}
};

#endif