#pragma once

#define ie IncredibleEngine

#include <SDL.h>
#include <SDL_mixer.h>

#include <iostream>

namespace IncredibleEngine {

	namespace BaseFoo {
		class CreateWin {
		public:
			CreateWin();
			~CreateWin();
			SDL_Window* GetWindow();
			SDL_Surface* GetSurface();
			SDL_Renderer* GetRender();
		protected:

		private:
			SDL_Window* window;
			SDL_Surface* surface;
			SDL_Renderer* render;
		};


		class CreateTexture {
		public:
			CreateTexture();
			~CreateTexture();
			int SetTexture(std::string locality, CreateWin& CurrentWindow);
			virtual SDL_Texture* GetTexture();
			SDL_Rect* GetRect();

		protected:
			SDL_Texture* texture;
			SDL_Rect rect;
		private:
		};

		class CreateButton : public CreateTexture {
		public:
			CreateButton();
			~CreateButton();
		private:
			int* x;
			int* y;
		};
	}
	
	namespace AdditionalFoo {
		int IE_CheckError(BaseFoo::CreateWin& CurrectWindow);

		int IE_DrowTextures();
	}
}
