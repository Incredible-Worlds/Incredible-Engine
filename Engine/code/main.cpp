#include <IncEngine.hpp>

#include <Windows.h>

int main(int argc, char** argv) {

	ie::BaseFoo::CreateWin window;
	ie::BaseFoo::CreateButton button;
		
	if (ie::AdditionalFoo::IE_CheckError(window) != 0
		|| button.SetTexture("../Engine/texture.bmp", window) != 0) return 5;

	for (int i = 0; i < 50; i++) {
		SDL_RenderCopy(window.GetRender(), button.GetTexture(), NULL, button.GetRect());
		SDL_RenderPresent(window.GetRender());
		SDL_RenderClear(window.GetRender());
	}

	return 0;
}