#include <IncEngine.hpp>
#include <iostream>

using namespace ie;

int main(int argc, char** argv) {

	CreateWindow window;
	
	if (IE_CheckError(window) != 0) return 5;

	return 0;
}