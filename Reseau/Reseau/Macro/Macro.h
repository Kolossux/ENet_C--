#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <enet/enet.h>
#include <functional>
#include <conio.h>

using namespace std;

#define BLACK "\x1B[38;5;232m"
#define DARK_GRAY "\x1B[38;5;237m"
#define GRAY "\x1B[38;5;244m"
#define LIGHT_GRAY "\x1B[38;5;249m"
#define WHITE "\x1B[38;5;255m"
#define DARK_RED "\x1B[38;5;124m"
#define RED "\x1B[38;5;196m"
#define DARK_ORANGE "\x1B[38;5;130m"
#define ORANGE "\x1B[38;5;208m"
#define DARK_YELLOW "\x1B[38;5;136m"
#define YELLOW "\x1B[38;5;226m"
#define LIME "\x1B[38;5;82m"
#define GREEN "\x1B[38;5;106m"
#define BLUE "\x1B[38;5;63m"
#define LIGHT_BLUE "\x1B[38;5;12m"
#define CYAN "\x1B[38;5;51m"
#define PINK "\x1B[38;5;219m"
#define MAGENTA "\x1B[38;5;199m"
#define PURPLE "\x1B[38;5;99m"
#define BROWN "\x1B[38;5;130m"

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif // DEBUG


void Display(const string& _text, const bool _endl = TRUE, const string _color = WHITE);
void ShowAddress(const string& _owner, const ENetAddress& _address, const bool _endl = true);