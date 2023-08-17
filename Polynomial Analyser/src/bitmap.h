#include <bits/stdc++.h>
using namespace std;

// Class
class Polynomial
{
	string regularEquation;
	string reducedEquation;
	char variable;
	int degree;

public:
	// sets the Object to default values
	void setDefault()
	{
		regularEquation = "";
		reducedEquation = "";
		variable = 'x';
		degree = 0;
	}

	string setEquation(string str);
	string reduceEqn();
	string addTermsToEquation(string str);
	int getDegree();
	int numberOfTerms();
};
