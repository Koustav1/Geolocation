//#define _USE_MATH_DEFINES
#include <list>
#include <math.h>
#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

const static double EarthRadiusKm = 6372.8;

inline double DegreeToRadian(double angle)
{
	return M_PI * angle / 180.0;
}

class Coordinate
{
public:
	Coordinate(double latitude ,double longitude):myLatitude(latitude), myLongitude(longitude)
	{}

	double Latitude() const
	{
		return myLatitude;
	}

	double Longitude() const
	{
		return myLongitude;
	}

private:

	double myLatitude;
	double myLongitude;
};

double HaversineDistance(const Coordinate& p1, const Coordinate& p2)
{
	double latRad1 = DegreeToRadian(p1.Latitude());
	double latRad2 = DegreeToRadian(p2.Latitude());
	double lonRad1 = DegreeToRadian(p1.Longitude());
	double lonRad2 = DegreeToRadian(p2.Longitude());

	double diffLa = latRad2 - latRad1;
	double doffLo = lonRad2 - lonRad1;

	double computation = asin(sqrt(sin(diffLa / 2) * sin(diffLa / 2) + cos(latRad1) * cos(latRad2) * sin(doffLo / 2) * sin(doffLo / 2)));
	return 2 * EarthRadiusKm * computation;
}

unsigned int RandomNumberGenerator()
{
    	return 1 + (rand() % 10);
}


int main()
{
	  Coordinate c1(50.827847, 12.921370);
	  list<double> list1;
	  list<double> list2;

	  list1.assign(50,50.827847);
	  list2.assign(1,12.921370);

	  int counter = 1;
	  for (list<double>::iterator i=list1.begin(); i!=list1.end(); i++)
	  {
		  double lat = (*i + (RandomNumberGenerator() * 0.001));

		  for (list<double>::iterator j=list2.begin(); j!=list2.end(); j++)
		   	   {
			  	  double lon = (*j + (RandomNumberGenerator() * 0.001));
			  	  cout << counter++ << ". ";
			  	  Coordinate c2(lat, lon);
			  	  if (HaversineDistance(c1, c2) < 1)

			  		  cout << "The position is within Radius of 1 km. Distance = " << HaversineDistance(c1, c2) << endl;
			  	  else
			  		  cout << "This specific position is outside the radius of 1 km from our real position" << endl;
		    	}

	  }

	return 0;

}

