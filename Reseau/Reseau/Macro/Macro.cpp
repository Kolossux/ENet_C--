#include "Macro.h"

void Display(const string& _text, const bool _endl, const string _color)
{
	cout << _color << _text << WHITE;
	if (_endl) cout << endl;
}

void ShowAddress(const string& _owner, const ENetAddress& _address,const bool _endl)
{
	Display(_owner + "(" , false, GREEN);
	Display(to_string(_address.host) + "::" + to_string(_address.port), false);
	Display(")" , _endl, GREEN);
}
