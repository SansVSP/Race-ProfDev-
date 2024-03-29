/*
	Based on the Race Simulator project from Codecademy
	This version has been altered to take user input for the the names of the drivers and the colours of the race cars
	Modified by Sancha van Spil
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Structures section
struct Race {
  int numberOfLaps;
  int currentLap;
  char* firstPlaceDriverName;
  char* firstPlaceRaceCarColor;
};
struct RaceCar{
  char* driverName;
  char* raceCarColor;
  int totalLapTime;
};
// Print functions section
void printIntro(){
  printf("Welcome to our main event digital race fans!\n I hope everybody has their snacks because we are about to begin!\n");
  printf("Who will be competing today?\n");
}
void printCountDown(){
  printf("Racers Ready! In...\n 5\n 4\n 3\n 2\n 1\n Race!\n");
}
void printFirstPlaceAfterLap(struct Race race){
  printf("After lap number %d\n", race.numberOfLaps);
  printf("First Place Is:%s in the %s race car!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
};
void printCongratulation(struct Race race){
  printf("Let's all congratulate %s in the %s race car for an amazing performance.\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
  printf("It truly was a great race and everybody have a goodnight!\n");
};
// Logic functions section
int calcTimeToCompleteLap(){
  int speed = (rand() % 3) + 1;
  int acceleration = (rand() % 3) + 1;
  int nerves = (rand() % 3) + 1;
  return speed + acceleration + nerves;
};
void updateRaceCar(struct RaceCar* raceCar){
  raceCar->totalLapTime = calcTimeToCompleteLap();
};
void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2){
  if(raceCar1->totalLapTime <= raceCar2->totalLapTime){
    race->firstPlaceDriverName = raceCar1->driverName;
    race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
  }
  else{
    race->firstPlaceDriverName = raceCar2->driverName;
    race->firstPlaceRaceCarColor = raceCar2->raceCarColor; 
  }
};

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2){
  struct Race race = {5,1,"",""};
  for(int i = race.numberOfLaps; i > 0; i--){
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
    race.numberOfLaps--;
  };
  printCongratulation(race);
};
int main() {
	char Racer1[40]; //Array to store driver's name
	char CarColor1[20]; //Array to store car colour
	char Racer2[40]; //Array to store driver's name
	char CarColor2[20]; //Array to store car colour
  srand(time(0)); 
  printIntro(); 
  
  fflush(stdin); //Clearing input to prevent problems with scanf
  fflush(stdout); //Clearing output to prevent problems with printf and scanf
  printf("Driver:\n");
  scanf("%[^\n]%*c", &Racer1); //Takes input for the driver's name

  printf("Racecar color:\n");
  scanf("%[^\n]%*c", &CarColor1); //Takes input for the colour of the car
	

  printf("Driver:\n");
  scanf("%[^\n]%*c", &Racer2); //Takes input for the driver's name
	

  printf("Racecar color:\n");
  scanf("%[^\n]%*c", &CarColor2); //Takes input for the colour of the car
	

  struct RaceCar raceCar1 = {Racer1, CarColor1, 0};
  struct RaceCar raceCar2 = {Racer2, CarColor2,0};
  printCountDown();
  startRace(&raceCar1, &raceCar2);
};
