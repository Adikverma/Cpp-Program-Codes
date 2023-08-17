#include "../src/bitmap.h";

// Function Input : This Method of Polynomial Class takes input as a string
// Function Desc : 1.Sets the object to default using setDefault
//                 2.Sets the string Input to the regularEquation(private) variable
//                 3.Sets the variable(private) value of Polynomial Class
// Function Returns : This function returns the regularEquation back
string Polynomial::setEquation(string str)
{
	this->setDefault();
	this->regularEquation = str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			this->variable = str[i];
			break;
		}
	}
	return this->regularEquation;
}

// Function Input : This Function does not take any inputs
// Function Desc : 1. Sets the reducedEquation(private) variable
// Function Returns : This Function retuns the reducedEquation string value
string Polynomial::reduceEqn()
{
	string eqn = this->regularEquation;
	char var = this->variable;
	map<int, int> mp;

	int sign = 1, coefficient = 0, power = 0;
	char variable = '*';
	int n = eqn.size();
	for (int i = 0; i < n;)
	{
		if (eqn[i] == '-' || eqn[i] == '+')
		{
			if (coefficient != 0 && i != 0)
			{
				mp[power] += sign * coefficient;
				coefficient = 0;
			}
			variable = '*';
			sign = (eqn[i] == '+') ? 1 : -1;
			i++;
		}
		else if (eqn[i] == this->variable)
		{
			variable = eqn[i];
			i++;
		}
		else
		{
			int j = i, num = 0;
			while ((j < n) && (eqn[j] >= '0' && eqn[j] <= '9'))
			{
				if (num == 0)
				{
					num += eqn[j] - '0';
				}
				else
				{
					num *= 10;
					num += eqn[j] - '0';
				}

				j++;
			}
			if (j != n)
			{
				if (variable == '*')
				{
					if (eqn[j] == this->variable)
					{
						coefficient = num;
					}
					else
					{
						power = 0;
						coefficient = num;
					}
				}
				else
				{
					power = num;
				}
			}
			else
			{
				if (variable == '*')
				{
					mp[0] += sign * num;
				}
				else
				{
					mp[num] += sign * coefficient;
				}
			}
			i = j;
		}
	}

	// Stringify the map to equation
	string equation = "";
	for (auto i = mp.rbegin(); i != mp.rend(); i++)
	{

		string coefficient, variable, power, addition;
		if (i->second == 0)
		{
			continue;
		}
		addition = (i->second >= 1) ? "+" : "-";
		coefficient = (i->second == 1 || i->second == -1) ? "" : to_string(abs(i->second));

		if (i->first != 0)
		{
			variable = var;
			power = (i->first == 1) ? "" : to_string(i->first);
		}
		if (equation.size() == 0 && addition == "+")
		{
			addition = "";
		}
		equation += addition + coefficient + variable + power;
	}
	this->reducedEquation = equation;
	return this->reducedEquation;
};

// Function Input : This function takes String as input
// Function Desc : 1.This function sets the object to default
//                 2.This function just adds the given equation to the previous regularEquation
// Function Returns : This function return the modified regularEquation string
string Polynomial::addTermsToEquation(string str)
{
	string newregularEquation = this->regularEquation;
	this->setDefault();
	this->regularEquation = newregularEquation + str;
	return this->regularEquation;
};

// Function Input : This function does not takes any input
// Function Desc : This function calculates the degree of a Polynomial equation
// Function Returns : 1.If the reducedEquation is defined then it returns the degree using reduced Equation
//                    2.If the reducedEquation is not defined then it returns the degree using the regularEquation
int Polynomial::getDegree()
{
	string toCheck;
	if (this->reducedEquation == "")
	{
		toCheck = this->regularEquation;
	}
	else
	{
		toCheck = this->reducedEquation;
	}
	int degree = 0, n = toCheck.length();
	for (int i = 0; i < n; i++)
	{
		if (toCheck[i] == this->variable)
		{
			int j = i + 1, num = 0;
			while ((j < n) && (toCheck[j] >= '0' && toCheck[j] <= '9'))
			{
				if (num == 0)
				{
					num += toCheck[j] - '0';
				}
				else
				{
					num *= 10;
					num += toCheck[j] - '0';
				}

				j++;
			}
			degree = max(degree, num);
			degree = max(degree, 1);
			i = j - 1;
		}
	}
	this->degree = degree;
	return degree;
};

// Function Input : This function does not takes any inputs
// Funtion Desc : This function is to calculate the total number of terms a Polynomial equation has
//  Function Returns : 1.If the reducedEquation is defined then it returns the Number of Terms using reduced Equation
//                     2.If the reducedEquation is not defined then it returns the Number of Terms using the regularEquation
int Polynomial::numberOfTerms()
{
	string toCheck;
	if (this->reducedEquation == "")
	{
		toCheck = this->regularEquation;
	}
	else
	{
		toCheck = this->reducedEquation;
	}
	int count = 0;

	for (int i = 0; i < toCheck.length(); i++)
	{
		if (toCheck[i] == '+' || toCheck[i] == '-')
		{
			count++;
		}
		if (i == 0 && toCheck[0] == '-')
			count--;
	}
	return count + 1;
};