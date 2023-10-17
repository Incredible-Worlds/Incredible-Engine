#include "IncEngine.hpp"

IncredibleEngine::BaseFoo::CreateWin::CreateWin() {
    SDL_Init(SDL_INIT_EVERYTHING || SDL_INIT_AUDIO);

    window = SDL_CreateWindow("Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        400,
        400,
        SDL_WINDOW_ALLOW_HIGHDPI);

    surface = SDL_GetWindowSurface(window);

    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

IncredibleEngine::BaseFoo::CreateWin::~CreateWin() {

    std::cout << "Destructing window" << std::endl;

    SDL_DestroyWindow(window);
    render = NULL;
    surface = NULL;
}

SDL_Window* IncredibleEngine::BaseFoo::CreateWin::GetWindow() {
    return window;
}

SDL_Surface* IncredibleEngine::BaseFoo::CreateWin::GetSurface() {
    return surface;
}

SDL_Renderer* IncredibleEngine::BaseFoo::CreateWin::GetRender() {
    return render;
}

//////////////////////////////////////////////////////////////////////////////////////

IncredibleEngine::BaseFoo::CreateTexture::CreateTexture()
{
    texture = NULL;
    rect.x = 0; rect.y = 0;
}

IncredibleEngine::BaseFoo::CreateTexture::~CreateTexture()
{
    std::cout << "Destructing texture" << std::endl;

    SDL_DestroyTexture(texture);
}

int IncredibleEngine::BaseFoo::CreateTexture::SetTexture(std::string locality, CreateWin& CurrentWindow)
{
    SDL_Surface* temptexture = SDL_LoadBMP(locality.c_str());
    texture = SDL_CreateTextureFromSurface(CurrentWindow.GetRender(), temptexture);
    SDL_FreeSurface(temptexture);
    if (texture == NULL)
    {
        return -1;
    }

    return 0;
}

SDL_Texture* IncredibleEngine::BaseFoo::CreateTexture::GetTexture()
{
    return texture;
}

SDL_Rect* IncredibleEngine::BaseFoo::CreateTexture::GetRect()
{
    return &rect;
}

int IncredibleEngine::AdditionalFoo::IE_CheckError(BaseFoo::CreateWin& CurretnWindow) {
    if (CurretnWindow.GetWindow() == NULL) {
        return -1;
    }

    return 0;
}

IncredibleEngine::BaseFoo::CreateButton::CreateButton()
{
    x = new int;
    x = 0;
    y = new int;
    y = 0;
}

IncredibleEngine::BaseFoo::CreateButton::~CreateButton()
{
    delete(x);
    delete(y);
}
