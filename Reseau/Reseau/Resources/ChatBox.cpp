#include "ChatBox.h"
#include "../Network/Peer/PeerWrapper.h"

ChatBox::ChatBox()
{
	text = string();
}

void ChatBox::DisplayText(const string& _str) const
{
	Display(_str);
	Display("========");

}

void ChatBox::Open(string& _string, const vector<ENetPeer*>& _clients)
{
	_string = string();
	bool _wantToQuit = false;
	char _letter;

	Display("ChatBox");

	do
	{
		_letter = _getch();
		system("cls");


		//enter 
		if (_letter == '\r' || _letter == 27)
			_wantToQuit = true;

		//backspace
		if (_letter == '\b' && !_string.empty())
			_string.erase(_string.end() - 1);
		else
			_string.push_back(_letter);

		DisplayText(_string);

		if (_string == "/msg ")
		{
			string _new;
			size_t _stringSize = strlen(_string.c_str());

			for (int i = 5; i < _stringSize; i++)
				_new.push_back(_string[i]);
			size_t _newSize = strlen(_new.c_str());

			for (ENetPeer* _client : _clients)
			{
				string _clientName = (const char*)_client->data;
				size_t _clientNameSize = strlen(_clientName.c_str());

				for (int i = 0; i < _newSize; i++)
				{
					if (_clientName[i] == _new[i] && _clientNameSize > i)
					{
						if (i == _newSize - 1)
							Display(_clientName);
					}
					break;
				}
			}
		}

	} while (!_wantToQuit);
	system("cls");
}
