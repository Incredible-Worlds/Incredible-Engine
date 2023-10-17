#include <IncEngine.hpp>

#include <Windows.h>

int main(int argc, char** argv) {

	ie::BaseFoo::CreateWin window;
	ie::BaseFoo::CreateButton button;
	button.SetTexture("texture.bmp", window);

	if (ie::AdditionalFoo::IE_CheckError(window) != 0) return 5;

	while (true) {
		SDL_RenderCopy(window.GetRender(), button.GetTexture(), button.GetRect(), NULL);

	}

	return 0;
}