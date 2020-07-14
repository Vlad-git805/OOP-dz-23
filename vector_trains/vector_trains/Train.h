#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Train
{
private:

	struct Time
	{
		short h, m, s;
	};

	int number;
	Time departureTime;
	string destination;

	//ofstream& operator<< (ofstream& of, const Railway& rl)
public:

	void Set_Time(short h, short  m, short s)
	{
		departureTime.h = h;
		departureTime.m = m;
		departureTime.s = s;
	}


	string Get_destination()
	{
		return  destination;
	}

	int Get_number()
	{
		return  number;
	}

	Train()
	{
		number = 0;
		departureTime.h = 0;
		departureTime.m = 0;
		departureTime.s = 0;
		destination = "no_destination";
	}

	Train(int number, short h, short m, short s, string destination)
	{
		this->number = number;
		this->departureTime.h = h;
		this->departureTime.m = m;
		this->departureTime.s = s;
		this->destination = destination;
	}

	void Show_info()const
	{
		cout << "Number: " << number << endl;
		cout << "DepartureTime.h: " << departureTime.h << endl;
		cout << "DepartureTime.m: " << departureTime.m << endl;
		cout << "DepartureTime.s: " << departureTime.s << endl;
		cout << "destination: " << destination << endl;
	}

	bool operator<(Train number)
	{
		if (this->departureTime.h != number.departureTime.h)
		{
			return (this->departureTime.h < number.departureTime.h);
		}

		if (this->departureTime.m != number.departureTime.m)
		{
			return(this->departureTime.m < number.departureTime.m);
		}

		if (this->departureTime.h != number.departureTime.h)
		{
			return(this->departureTime.h < number.departureTime.h);
		}

	}

	friend ofstream& operator<<(ofstream& of, const Train& tr);
	friend ifstream& operator>>(ifstream& ifs, Train& tr);
};

ofstream& operator<<(ofstream& of, const Train& tr)
{
	of << tr.number << endl;
	of << tr.departureTime.h << endl;
	of << tr.departureTime.m << endl;
	of << tr.departureTime.s << endl;
	of << tr.destination << endl;

	return of;
}

ifstream& operator>>(ifstream& fin, Train& tr)
{
	fin >> tr.number;
	fin >> tr.departureTime.h;
	fin >> tr.departureTime.m;
	fin >> tr.departureTime.s;
	fin >> tr.destination;

	return fin;
}

//ofstream& operator<<(ofstream& of, const Train& train)
//{
//	of << train.number << endl;
//	of << train.departureTime.h << endl;
//	of << train.departureTime.m << endl;
//	of << train.departureTime.s << endl;
//	of << train.destination << endl;
//
//	return of;
//}
//
//ifstream& operator>>(ifstream& fin, Train& train)
//{
//	fin >> train.number;
//	fin >> train.departureTime.h;
//	fin >> train.departureTime.m;
//	fin >> train.departureTime.s;
//	fin >> train.destination;
//
//	return fin;
//}
