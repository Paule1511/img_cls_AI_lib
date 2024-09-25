#pragma once
#include "Debug.h"
#include <iostream>
#include <string>

void Debug::err(std::string Msg) {
	std::cout << "\033[31m" << Msg << "\033[0m" << std::endl;
}

void Debug::success(std::string Msg) {
	std::cout << "\033[32m" << Msg << "\033[0m" << std::endl;
}

void Debug::test(std::string Msg) {
	std::cout << "\033[34m" << Msg << "\033[0m" << std::endl;
}
