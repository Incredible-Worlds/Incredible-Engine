#pragma once

#define ie IncredibleEngine

#include <SDL.h>
#include <SDL_mixer.h>

namespace IncredibleEngine {

	class CreateWindow {
	public:
		CreateWindow();
		~CreateWindow();
		SDL_Window* GetWindow();
	protected:

	private:
		SDL_Window* window;
	};

	int IE_CheckError(CreateWindow CurrectWindow);

}
