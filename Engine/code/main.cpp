#include <IncEngine.hpp>

#include <Windows.h>

int main(int argc, char** argv) {

	ie::BaseFoo::CreateWin window;
	ie::BaseFoo::CreateButton button[1];

	if (ie::AdditionalFoo::IE_CheckError(window) != 0
		|| button[0].SetTexture("../Engine/texture.bmp", window) != 0) return 5;

	while (true) {
		ie::AdditionalFoo::IE_DrawTextures(window, button);
	}

	return 0;
}