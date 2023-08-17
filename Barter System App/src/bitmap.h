#include <bits/stdc++.h>
using namespace std;

// Classes
class User
{
	string name;
	string leastProfitableItem;
	string mostProfitableItem;
	vector<pair<string, pair<int, int>>> items;

public:
	string getName()
	{
		return name;
	}
	void setName(string s)
	{
		name = s;
	}
	string getLeastProfitableItem()
	{
		return leastProfitableItem;
	}
	void setLeastProfitableItem(string s)
	{
		leastProfitableItem = s;
	}
	string getMostProfitableItem()
	{
		return mostProfitableItem;
	}
	void setMostProfitableItem(string s)
	{
		mostProfitableItem = s;
	}
	vector<pair<string, pair<int, int>>> getItems()
	{
		return items;
	};
	void setItem(vector<pair<string, pair<int, int>>> item)
	{
		items = item;
	};
};

class BarterSystemApp
{

	map<string, User> users;

public:
	int enterNewUser(string name, vector<pair<string, pair<int, int>>> &userItems);

	int bestTradeOption(string person1, int index, string person2);

	vector<string> listUsers();

	vector<string> listItemsOfUser(string user);

	string usersMostProfitableItem(string user);

	string usersLeastProfitableItem(string user);
};