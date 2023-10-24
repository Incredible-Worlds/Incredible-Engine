#pragma once

#define ie IncredibleEngine

#include <SDL.h>
#include <SDL_mixer.h>

#include <iostream>
#include <vector>
#include <Windows.h>

enum TextureType {
	IE_BACKGROUND,
	IE_GUI,
	IE_NPC
};

namespace IncredibleEngine {

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


		class CreateObject {
		public:
			CreateObject();
			~CreateObject();
			int SetTexture(std::string locality, CreateWin& CurrentWindow);
			int SetTexture(SDL_Texture& temptexture, CreateWin& CurrentWindow);
			virtual SDL_Texture* GetTexture();
			SDL_Rect* GetRect();
			int GetType();

		protected:
			SDL_Texture* texture;
			SDL_Rect rect;
			TextureType type;
		private:
		};

		class Button : public CreateObject {
		public:
			Button();
			Button(int posx, int posy);
			Button(int posx, int posy, std::string locality, CreateWin& CurrentWndow);
			~Button();
		private:
			short int x;
			short int y;
		};

		class Player : public CreateObject {
		public:
			Player();
		private:
			short int hp;
			short int damage;
			int absolutePosX;
			int absolutePosY;
		};

		class Enemy : public CreateObject {
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
		int IE_DrawTextures(BaseFoo::CreateWin& CurrentWindow, ie::BaseFoo::CreateObject** texturearr);

		// Processing all types of interacting with the game window
		int IE_WinInteract(BaseFoo::CreateWin& CurrentWindow, ie::BaseFoo::CreateObject** texturearr);
	}

	namespace TextureDocker {
		class IE_Textures {
		public:
			IE_Textures(std::string locality, std::string inputName, TextureType inputType, ie::BaseFoo::CreateWin& CurrentWindow);
			SDL_Texture& GetTexture();
		private:
			std::string textureName;
			TextureType type;
			SDL_Texture* dockerTexture;
		};
	}
}


