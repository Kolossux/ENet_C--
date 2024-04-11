#pragma once
#include "../Macro/Macro.h"

class ChatBox
{
	string text;
public:
	static ChatBox& GetInstance()
	{
		static ChatBox _instance;
		return _instance;
	}
public:
	ChatBox();
private:
	void DisplayText(const string& _message) const;
	void GetFindPath() const;
public:
	void Open(string& _message);
};

