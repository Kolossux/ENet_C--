#include "ChatBox.h"

ChatBox::ChatBox()
{
	text = string();
}

void ChatBox::DisplayText(const string& _str) const
{
	Display(_str);
	Display("========");


	//TODO draw Auto Completion;
}

void ChatBox::GetFindPath() const
{
}

void ChatBox::Open(string& _string)
{
	_string = string();
	bool _wantToQuit = false;
	char _letter;

	Display("ChatBox");

	do 
	{
		_letter = _getch();
		system("cls");

		if (_letter == '\r' || _letter == 27)
			_wantToQuit = true;

		if (_letter == '\b' && !_string.empty())
			_string.erase(_string.end()-1);
		else
			_string.push_back(_letter);

		DisplayText(_string);

	} while (!_wantToQuit);
	system("cls");
}
