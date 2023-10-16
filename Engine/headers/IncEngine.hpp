#pragma once

#define ie IncredibleEngine

#include <SDL.h>
#include <SDL_mixer.h>

#ifndef _WIN32
#include <Windows.h>
#else
#include <conio.h>
#endif // !


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