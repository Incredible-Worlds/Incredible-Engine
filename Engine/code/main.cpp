#include <IncEngine.hpp>

int main(int argc, char** argv) {

	ie::BaseFoo::CreateWin window;
	ie::BaseFoo::Button button(50, 50);
	ie::BaseFoo::Button button1(80, 49);
	ie::BaseFoo::Button button2(0, 13);
	ie::BaseFoo::Button button3(250, 260);

	ie::BaseFoo::CreateTexture* texturearr[10]{};

	texturearr[0] = &button;
	texturearr[1] = &button1;
	texturearr[2] = &button2;
	texturearr[3] = &button3;

	if (ie::AdditionalFoo::IE_CheckError(window) != 0
		|| button.SetTexture("../Engine/texture.bmp", window) != 0
		|| button1.SetTexture("../Engine/texture.bmp", window) != 0
		|| button2.SetTexture("../Engine/texture.bmp", window) != 0
		|| button3.SetTexture("../Engine/texture.bmp", window) != 0) return 5;

	while (true) {
		if (ie::AdditionalFoo::IE_WinInteract(window, texturearr) == 1) break;
		ie::AdditionalFoo::IE_DrawTextures(window, texturearr);
	}

	return 0;
}