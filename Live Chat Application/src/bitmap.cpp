#include "..\src\bitmap.h"

/*
This function creates a new User object based on the entered username and password
If the username already exists then return "Username taken",
If the username or password are empty fields then return "Enter Valid Data",
If everything is correct then return "User Created",
*/
string LiveChatApplication::signup(string userName, string password)
{
	if (users.find(userName) != users.end())
	{
		return "Username taken";
	}
	if (userName == "" || password == "")
	{
		return "Enter Valid Data";
	}
	User newUser;
	newUser.signup(userName, password);
	users[userName] = newUser;
	return "User Created";
};

/*
This function adds logins a user based on the username and password entered,
If username doen'st exits then return "Signup First",
If the user is already logged in then return "Already loggedIn",
If the user entered wrong password then return "Wrong Password",
If everything is correct then return "Logged In",
*/
string LiveChatApplication::login(string userName, string password)
{
	if (users.find(userName) != users.end())
	{
		if (users[userName].isLoggedIn())
		{
			return "Already loggedIn";
		}

		users[userName].login(password);
		if (users[userName].isLoggedIn())
		{
			return "Logged In";
		}
		else
		{
			return "Wrong Password";
		}
	}
	else
	{
		return "Signup First";
	}
};

/*
This function creates a Socket Object according to the entered usernames,
Creates a Socket object and Returns true only if:
	Both users are logged in
	Both user have socketId parameters == 0 (are not part of any other socket with someone else)
otherwise don't create Socket object and returns false
*/
string LiveChatApplication::createSocket(string userName1, string userName2)
{
	auto user1 = users.find(userName1);
	auto user2 = users.find(userName2);
	if (user1->second.isLoggedIn() && user2->second.isLoggedIn())
	{
		if (user1->second.getSocketId() == 0 && user2->second.getSocketId() == 0)
		{
			Socket newSocket;
			newSocket.userName1 = userName1;
			newSocket.userName2 = userName2;
			int socketId = newSocket.getSocketId();
			user1->second.setSocketId(socketId);
			user2->second.setSocketId(socketId);
			sockets[socketId] = newSocket;
			return "Created!";
		}
		else
		{
			return "Not Created!";
		}
	}
	else
	{
		return "Not Created!";
	}
};

/*
This function takes input user1name, user1Password, forUser2Message, user1name,
It return "Credential Issues" if:
	Both Users are not logged in
	Password is wrong
It returns "Common Socket Not Defined" if:
	User1 is not connected to any socket actually
	User2 is not in the same socket with user1
It returns "Message delivered" otherwise,
*/
string LiveChatApplication::chatWith(string userName1, string password, string msg, string userName2)
{
	auto user1 = users.find(userName1);
	auto user2 = users.find(userName2);
	if (user1->second.isLoggedIn() && user2->second.isLoggedIn() && user1->second.checkPass(password))
	{
		if (user1->second.getSocketId() != 0 && (user1->second.getSocketId() == user2->second.getSocketId()))
		{
			int socketId = user1->second.getSocketId();
			auto socket = sockets.find(socketId);
			if (socket->second.userName1 == userName1)
			{
				socket->second.textUser2(msg);
			}
			else
			{
				socket->second.textUser1(msg);
			}
			return "Message delivered";
		}
		else
		{
			return "Common Socket Not Defined";
		}
	}
	else
	{
		return "Credential Issues";
	}
};

/*
This function is used to get the all the messages that user 1 have recieved in the current socket,
It returns {"Credential Issues"} if:
	User is not logged in
	Password is incorrect,
It returns {"No Socket Found"} if:
	User is not part of any socket currently,
If everything is correct then return the list of chats in same order as they entered
*/
vector<string> LiveChatApplication::getMyCurrentChats(string userName, string password)
{
	auto user = users[userName];
	if (user.isLoggedIn() && user.checkPass(password))
	{
		int socketId = user.getSocketId();
		if (socketId != 0)
		{
			auto socket = sockets[socketId];
			if (socket.userName1 == userName)
			{
				if (socket.getUserChat1().size() == 0)
					return {"No Chats"};
				else
					return socket.getUserChat1();
			}
			else
			{
				if (socket.getUserChat2().size() == 0)
					return {"No Chats"};
				else
					return socket.getUserChat2();
			}
		}
		else
		{
			return {"No Socket Found"};
		}
	}
	else
	{
		return {"Credential Issues"};
	}
};

/*
This function drops any socket that a User may have
It returns "Credential Issues" if:
	User has not logged in
	Password is incorrect
It returns "No Socket Found" if:
	User is not part of any socket
It returns "Socket Dropped" otherwise,

Note: handle all other changes it may cause
*/
string LiveChatApplication::dropCurrentSocket(string userName, string password)
{
	auto user1 = users.find(userName);
	if (user1->second.isLoggedIn() && user1->second.checkPass(password))
	{
		if (user1->second.getSocketId() != 0)
		{
			auto socket = sockets.find(user1->second.getSocketId());
			string userName2;
			if (socket->second.userName1 == userName)
			{
				userName2 = socket->second.userName2;
			}
			else
			{
				userName2 = socket->second.userName1;
			}
			sockets.erase(socket->second.getSocketId());

			auto user2 = users.find(userName2);
			user1->second.setSocketId(0);
			user2->second.setSocketId(0);
			return "Socket Dropped";
		}
		else
		{
			return "No Socket Found";
		}
	}
	else
	{
		return "Credential Issues";
	}
};

/*
This function logs out User,
It returns "Credential Issues" if:
	user is already logged out,
	password is incorrect,
It returns "Logged Out" otherwise

Note: Will Socket be affected?
*/
string LiveChatApplication::logout(string userName, string password)
{
	auto user1 = users.find(userName);
	if (user1->second.isLoggedIn() && user1->second.checkPass(password))
	{
		string drop = dropCurrentSocket(userName, password);
		user1->second.logout(password);
		return "Logged Out";
	}
	else
	{
		return "Credential Issues";
	}
};