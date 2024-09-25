#pragma once
#include "Debug.h"
#include <iostream>

void Debug::err(char* Msg) {
	std::cout << "\033[31m" << Msg << "\033[0m" << std::endl;
}

void Debug::success(char* Msg) {
	std::cout << "\033[32m" << Msg << "\033[0m" << std::endl;
}

void Debug::test(char* Msg) {
	std::cout << "\033[34m" << Msg << "\033[0m" << std::endl;
}
