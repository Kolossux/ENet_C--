#include "FileLoader.h"

bool Write(const string& _path, const string& _text)
{
    ofstream _stream = ofstream(_path, ios_base::app);

    if (!_stream)
    {
        throw ("Error => invalid path : " + _path);
    }

    //TODO

    return false;
}

void FindValidWords(const string& _path, const string& _text, vector<string>& _words)
{
    ifstream _stream = ifstream();

    if (!_stream)
    {
        throw  ("Error => invalid path : " + _path);
    }

    string _word;
    while (_stream >> _word)
    {
        if (IsValidWord(_text, _word))
        {
            _words.push_back(_word);
        }
    }
}

bool Contains(const string& _word)
{
    //TODO 

    return false;
}

bool IsValidWord(const string& _text, const string& _word)
{
    //TODO 

    return false;
}

void Clear(const string& _string)
{
    //ofstream(_string);
}
