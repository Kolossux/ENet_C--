#pragma once
#include "../../Macro/Macro.h"

bool Write(const string& _path, const string& _text);
void FindValidWords(const string& _path, const string& _text, vector<string>& _words);
bool Contains(const string& _word);
bool IsValidWord(const string& _text, const string& _word);
void Clear(const string& _string);
