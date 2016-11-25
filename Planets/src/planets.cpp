#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>

using namespace std;

static double * body_mass, * positionX, * nextPositionX, * positionY, * nextPositionY,
              * velocityX, * nextVelocityX, * velocityY, * nextVelocityY, accuracy;
static const double G = 1;

static int n_steps, n_bodies, pointsDisplayed = 100;

void calcGForce(int j, double & gForceX, double & gForceY){
    double Gi,Di2;
    gForceX = gForceY = 0;
    for(int i = 0; i < n_bodies; i++){
        if(i != j){
          // Square distance from the i bodie.
          Di2 = (positionX[j]-positionX[i])*(positionX[j]-positionX[i])
          + (positionY[j]-positionY[i])*(positionY[j]-positionY[i]);
          if(abs(Di2) > 0.1){
              // Module of the force from the i bodie.
              Gi = G*body_mass[j]*body_mass[i]/Di2;

              // X coordenate of the force from the i bodie.
              gForceX -= Gi*(positionX[j]-positionX[i])/sqrt(Di2);

              // Y coordenate of the force from the i bodie.
              gForceY -= Gi*(positionY[j]-positionY[i])/sqrt(Di2);
          }
          else{
              gForceX = gForceY = 0;
          }
        }
    }
}

int main(int argc, char const *argv[]) {

    if(argc < 2){
        cout << "This program need a file to work\n";
        return 1;
    }

    // Text file opened
    ifstream inputFile;
    inputFile.open(argv[1]);

    // Initialice this three variables with the file information

    char buffer[50];
    inputFile.getline(buffer,50,' ');
    n_steps = atoi(buffer);
    inputFile.getline(buffer,50,' ');
    accuracy = atof(buffer);
    inputFile.getline(buffer,50,'\n');
    n_bodies = atoi(buffer);

    // Initialice the important vectors.

    body_mass = new double [n_bodies];
    positionX = new double [n_bodies];
    nextPositionX = new double [n_bodies];
    positionY = new double [n_bodies];
    nextPositionY = new double [n_bodies];
    velocityX = new double [n_bodies];
    nextVelocityX = new double [n_bodies];
    velocityY = new double [n_bodies];
    nextVelocityY = new double [n_bodies];

    // Getting the information of the file of each body.

    for(int i = 0; i < n_bodies; i++){
        inputFile.getline(buffer,50,' ');
        body_mass[i] = atof(buffer);
        inputFile.getline(buffer,50,' ');
        positionX[i] = atof(buffer);
        inputFile.getline(buffer,50,' ');
        positionY[i] = atof(buffer);
        inputFile.getline(buffer,50,' ');
        velocityX[i] = atof(buffer);
        inputFile.getline(buffer,50,'\n');
        velocityY[i] = atof(buffer);
    }

    double forceX, forceY;

    cout << n_bodies << " " << n_steps <<endl;
    for(int i = 0; i < n_steps; i++){
        for(int j = 0; j < n_bodies; j++){
            calcGForce(j,forceX, forceY);
            // Calculing next position and display it.
            nextPositionX[j] = positionX[j] + accuracy*velocityX[j];
            nextPositionY[j] = positionY[j] + accuracy*velocityY[j];
            // Calculing next velocity.
            nextVelocityX[j] = velocityX[j] + accuracy*forceX/body_mass[j];
            nextVelocityY[j] = velocityY[j] + accuracy*forceY/body_mass[j];
        }

        // Calculing the next step and displaing the position.
        for(int j = 0; j < n_bodies; j++){
            positionX[j] = nextPositionX[j];
            positionY[j] = nextPositionY[j];
            velocityX[j] = nextVelocityX[j];
            velocityY[j] = nextVelocityY[j];
            if(i%pointsDisplayed == 0){
                cout << nextPositionX[j] << " " << nextPositionY[j];

                if(j == n_bodies -1){
                    cout << endl;
                }
                else{
                    cout << " ";
                }
            }

        }
    }

    // Deleting all the vectors We have used.

    delete body_mass;
    delete positionX ;
    delete nextPositionX ;
    delete positionY ;
    delete nextPositionY ;
    delete velocityX ;
    delete nextVelocityX ;
    delete velocityY ;
    delete nextPositionY ;

    // Closing the file.
    inputFile.close();

    return 0;
}
