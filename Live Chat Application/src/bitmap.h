#include <bits/stdc++.h>
using namespace std;

// Class1
class User
{
	bool isLogin = false;
	string password;
	int socketId = 0;
	string userName = "";

public:
	bool isLoggedIn()
	{
		return isLogin;
	}

	void signup(string name, string pass)
	{
		userName = name;
		password = pass;
	}

	void login(string pass)
	{
		if (pass == password)
		{
			isLogin = true;
		}
	}

	bool checkPass(string pass)
	{
		return (pass == password);
	}

	void logout(string pass)
	{
		if (pass == password)
		{
			isLogin = false;
		}
	}

	void setSocketId(int socket)
	{
		socketId = socket;
	}

	int getSocketId()
	{
		return socketId;
	}
};

// Class2
class Socket
{
	int socketId;

	vector<string> userChat1;
	vector<string> userChat2;

public:
	Socket()
	{
		srand(time(0));
		int lb = 100000, ub = 200000;
		int socketNum = (rand() % (ub - lb + 1)) + lb;
		socketId = socketNum;
	}

	string userName1;
	string userName2;

	int getSocketId()
	{
		return socketId;
	}
	void textUser1(string msg)
	{
		userChat1.push_back(msg);
	}
	void textUser2(string msg)
	{
		userChat2.push_back(msg);
	}
	vector<string> getUserChat1()
	{
		return userChat1;
	}
	vector<string> getUserChat2()
	{
		return userChat2;
	}
};

class LiveChatApplication
{
	map<string, User> users;
	map<int, Socket> sockets;

public:
	string login(string userName, string password);

	string signup(string userName, string password);

	string createSocket(string userName1, string userName2);

	string chatWith(string userName1, string password, string chat, string userName2);

	vector<string> getMyCurrentChats(string userName, string password);

	string dropCurrentSocket(string userName, string password);

	string logout(string userName, string password);
};
