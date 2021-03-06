#include <iostream>
#include <time.h>
#include <ctime>
#include <string.h>
#include <list>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class person { // class used to store geograpical location and infection status, used 
public:
	double _latitude = 0.0;
	double _longitude = 0.0;
	bool infected = 0;
	person() {
	}
	person(double latitude, double longitude) {
		_latitude = latitude;
		_longitude = longitude;
	}

};

class MyString
{
public:
	string _s;

	MyString(string s)
	{
		_s = s;
	}
	operator double();
};

MyString::operator double()
{
	int a = 0;
	char c = '0';
	int sum = 0;
	bool neg = false;
	int start = 0;
	if (_s[0] == '-') {
		neg = true;
		start = 1;
	}
	for (int i = start; i < _s.length(); i++) {
		c = _s[i];
		a = c - '0';
		a = a * pow(10, _s.length() - i - 1);
		sum = sum + a;
	}
	if (neg) {
		sum = sum * -1;
	}

	return sum;
}

vector<string> split(string str) { // this function receives comma separated data in a string, splits it up, and places the data into a vector for easy use
	vector<string> nar;
	string a;
	int last = 0;
	for (int k = 0; k < str.length(); k++) {
		if (str[k] == ',') {
			if (last != 0) {
				string a = str.substr(last + 1, (k - last - 1));
				nar.push_back(a);
				last = k;
			}
			else {
				string a = str.substr(last, (k - last));
				nar.push_back(a);
				last = k;
			}
		}
		else if (k == str.length() - 1) {
			string a = str.substr(last + 1, (k - last));
			nar.push_back(a);
		}
	}
	return nar;
};

string rnd_AN_str() { //This function returns a 64 character Alpha-Numeric random code, to be used for contact tracing to creat random, unique codes to represent when contact is made
	const char valid_char[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	string key;

	for (int i = 0; i < 64; i++) {
		key.push_back(valid_char[rand() % 62]);
	}
	return key;
}

void ReadCoordsFromFile(list <person> storage) { //this function takes a file, reads the data, places the data into the object and stores the object
	ifstream myfile;
	string line;
	string q;
	person p;
	string NameOfFile;
	cout << "Enter a text file to read" << endl;
	cin >> NameOfFile;
	myfile.open(NameOfFile);
	if (!myfile) {
		cout << "Unable to open file or invalid data" << endl;
		myfile.close();
		exit(1);
	}
	getline(myfile, line);
	vector <double> vec = { 0.0, 0.0 ,0 }; //lattitude, longitude, infected
	p._latitude= stod(split(line)[0]);
	p._longitude = stod(split(line)[1]);
	p.infected = stod(split(line)[2]);
	storage.push_back(p);
}

void WriteCoordsToFile(string NameOfFile, list <person> storage) { //writes the first value in storage to the file and deletes it from storage
	ofstream myfile;
	string line;
	string q;
	cout << "Enter a text file to write to" << endl;
	cin >> NameOfFile;
	myfile.open(NameOfFile);
	if (!myfile) {
		cout << "Unable to open file or invalid data" << endl;
		myfile.close();
		exit(1);
	}
	myfile << (storage.front())._latitude << ", " << (storage.front())._longitude << (storage.front()).infected << endl;
	storage.pop_front();
}

int main() {
	srand(time(0));
	
	list <person> storage;
	storage.push_back(person(235.334, 453345.2323));

	cout << (storage.front())._latitude;
	//person p1 = new person(0.0, 0.0);

	ReadCoordsFromFile( storage);

}