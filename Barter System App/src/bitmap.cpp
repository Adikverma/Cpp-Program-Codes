#include "bitmap.h"

// He/she can look for the best trade option with another user according to weigths
// He/she can look for details of his items like : itemList, userList, getMostProfitableItem, getLeastProfitableItem
// Class : BarterSytemUser
// 		Public Members:
// 		string name;
// 		string leastProfitableItem;
// 		string mostProfitableItem;
// 		vector<pair<string, pair<int, int>>> items;

//---------------------------------------------------------------------------------------------------------------------//

// Function : Enter New User
// Input: String = UserName of user
//       ItemList = list of items ( names, profit, weight)

// Updation of the New User:
//     Username
//     Number Of users
//     Most Profitable Item to trade for this user
//     Least Profitable Item to trade for this user

// Output: Number of users
int BarterSystemApp::enterNewUser(string username, vector<pair<string, pair<int, int>>> &userItems)
{
	User user;
	user.setName(username);

	int minimum = INT_MAX, maximum = INT_MIN;
	string minimumPrf = "", maximumPrf = "";
	for (auto i : userItems)
	{
		if ((i.second).first / ((i.second).second * 1.0) < minimum)
		{
			minimum = (i.second).first / ((i.second).second * 1.0);
			user.setMostProfitableItem(i.first);
		}

		if ((i.second).first / ((i.second).second * 1.0) > maximum)
		{
			maximum = (i.second).first / ((i.second).second * 1.0);
			user.setLeastProfitableItem(i.first);
		}
	}
	user.setItem(userItems);
	users[username] = user;

	return users.size();
};

//---------------------------------------------------------------------------------------------------------------------//

// Binary knapsack for the bestTradeOption
int binaryKnapSack(int W, vector<int> &wt, vector<int> &val, int n)
{
	// Base Case
	if (n == 0 || W == 0)
		return 0;

	if (wt[n - 1] > W)
	{
		return binaryKnapSack(W, wt, val, n - 1);
	}
	else
	{
		return max(val[n - 1] + binaryKnapSack(W - wt[n - 1], wt, val, n - 1),
				   binaryKnapSack(W, wt, val, n - 1));
	}
}

// Function : Best Barter Trade Between Two users
//  Input : Person1 username, Item Index User1 wants to trade, User2 username
//  A Barter System works on the principle of weights and trading happens according to weights
//  Find the Maximum Possible Sum of Profits of Items from User2 for User1{maximize}
//  Weight userItem1 >= Sum of Weights of Items of User2
// Note: int index : 1 based indexing
int BarterSystemApp::bestTradeOption(string person1, int index, string person2)
{
	auto user1 = users[person1].getItems();
	int weightItem1 = (user1[index - 1].second).second;
	auto user2 = users[person2];
	vector<int> wt, val;
	for (auto i : user2.getItems())
	{
		val.push_back((i.second).first);
		wt.push_back((i.second).second);
	}
	return binaryKnapSack(weightItem1, wt, val, wt.size());
};

//---------------------------------------------------------------------------------------------------------------------//

// Function : List all the UserNames that are registered on the app
// Note: Names should be in Alphabetical
vector<string> BarterSystemApp::listUsers()
{
	vector<string> usersList;
	for (auto i : users)
	{
		usersList.push_back(i.first);
	}
	return usersList;
};

//---------------------------------------------------------------------------------------------------------------------//

// Function : List all the items of the User
// Note: Item Names should be in the same order as they were entered
vector<string> BarterSystemApp::listItemsOfUser(string username)
{
	vector<string> itemList;
	auto user = users[username];
	auto items = user.getItems();
	for (auto i : items)
	{
		itemList.push_back(i.first);
	}
	return itemList;
};

//---------------------------------------------------------------------------------------------------------------------//

// Function : List the item of user that has most profit/weight ratio
string BarterSystemApp::usersMostProfitableItem(string username)
{
	return (users[username]).getMostProfitableItem();
};

//---------------------------------------------------------------------------------------------------------------------//

// Function : List the item of user that has least profit/weight ratio
string BarterSystemApp::usersLeastProfitableItem(string username)
{
	return (users[username]).getLeastProfitableItem();
};