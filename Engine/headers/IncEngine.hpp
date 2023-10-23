#pragma once

#define ie IncredibleEngine

#include <SDL.h>
#include <SDL_mixer.h>

#include <iostream>
#include <vector>
#include <Windows.h>

namespace IncredibleEngine {

	enum TextureType {
		IE_BACKGROUND,
		IE_GUI,
		IE_NPC
	};

	namespace BaseFoo {
		class CreateWin {
		public:
			CreateWin();
			CreateWin(int width, int height);
			~CreateWin();
			SDL_Window* GetWindow();
			SDL_Surface* GetSurface();
			SDL_Renderer* GetRender();
			SDL_Event* GetEvent();
		protected:

		private:
			SDL_Window* window;
			SDL_Surface* surface;
			SDL_Renderer* render;
			SDL_Event windowEvent;
		};


		class CreateTexture {
		public:
			CreateTexture();
			~CreateTexture();
			int SetTexture(std::string locality, CreateWin& CurrentWindow);
			virtual SDL_Texture* GetTexture();
			SDL_Rect* GetRect();
			int GetType();

		protected:
			SDL_Texture* texture;
			SDL_Rect rect;
			TextureType type;
		private:
		};

		class Button : public CreateTexture {
		public:
			Button();
			Button(int posx, int posy);
			~Button();
		private:
			short int x;
			short int y;
		};

		class Player : public CreateTexture {
		public:
			Player();
		private:
			short int hp;
			short int damage;
			int absolutePosX;
			int absolutePosY;
		};

		class Enemy : public CreateTexture {
		public:

		private:
			bool visible;
			short int hp;
			short int damage;
			int absolutePosX;
			int absolutePosY;
		};
	}
	
	namespace AdditionalFoo {
		// Return error code of window
		// 0 if all OK
		int IE_CheckError(BaseFoo::CreateWin& CurrentWindow);

		// Draw all game textures
		// Return -1 if any texture was not loaded
		int IE_DrawTextures(BaseFoo::CreateWin& CurrentWindow, ie::BaseFoo::CreateTexture** texturearr);

		// Processing all types of interacting with the game window
		int IE_WinInteract(BaseFoo::CreateWin& CurrentWindow, ie::BaseFoo::CreateTexture** texturearr);
	}
}
