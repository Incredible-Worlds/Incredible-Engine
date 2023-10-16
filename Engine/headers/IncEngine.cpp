#include "IncEngine.hpp"

IncredibleEngine::CreateWindow::CreateWindow() {
    SDL_Init(SDL_INIT_EVERYTHING || SDL_INIT_AUDIO);

    window = SDL_CreateWindow("Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400,
        400,
        SDL_WINDOW_ALLOW_HIGHDPI);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

IncredibleEngine::CreateWindow::~CreateWindow() {
    SDL_DestroyWindow(window);
}

SDL_Window* IncredibleEngine::CreateWindow::GetWindow() {
    return window;
}

int IncredibleEngine::IE_CheckError(CreateWindow CurretnWindow) {
    if (CurretnWindow.GetWindow() == NULL) {
        return -1;
    }

    return 0;
}

