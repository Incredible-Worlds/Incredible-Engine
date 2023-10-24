#include <IncEngine.hpp>

int main(int argc, char** argv) {

	ie::BaseFoo::CreateWin window;

	ie::TextureDocker::IE_Textures buttonDocker("../Engine/texture.bmp", "button", IE_BACKGROUND, window);


	ie::BaseFoo::Button button(50, 50); button.SetTexture(buttonDocker.GetTexture(), window);
	ie::BaseFoo::Button button1(100, 100); button1.SetTexture(buttonDocker.GetTexture(), window);
	ie::BaseFoo::Button button2(170, 200); button2.SetTexture(buttonDocker.GetTexture(), window);

	ie::BaseFoo::CreateObject* texturearr[10]{};

	texturearr[0] = &button;
	texturearr[1] = &button1;
	texturearr[1] = &button2;

	if (ie::AdditionalFoo::IE_CheckError(window) != 0) return 5;

	while (true) {
		if (ie::AdditionalFoo::IE_WinInteract(window, texturearr) == 1) break;
		ie::AdditionalFoo::IE_DrawTextures(window, texturearr);
	}

	return 0;
}