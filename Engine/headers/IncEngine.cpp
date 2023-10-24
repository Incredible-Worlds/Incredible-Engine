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

    windowEvent.type = NULL;
}

IncredibleEngine::BaseFoo::CreateWin::CreateWin(int width, int height) {
    if (width <= 0 || height <= 0) { width = height = 400; }

    SDL_Init(SDL_INIT_EVERYTHING || SDL_INIT_AUDIO);
    window = SDL_CreateWindow("Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_ALLOW_HIGHDPI);
    surface = SDL_GetWindowSurface(window);

    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    windowEvent.type = NULL;

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

SDL_Event* IncredibleEngine::BaseFoo::CreateWin::GetEvent()
{
    return& windowEvent;
}

/// Main foo
///////////////////////////////////////////////////////////////////////////////////

IncredibleEngine::BaseFoo::CreateObject::CreateObject()
{
    texture = NULL;
    rect.x = 50; rect.y = 70;
    rect.w = 50; rect.h = 50;

    type = IE_BACKGROUND;
}

IncredibleEngine::BaseFoo::CreateObject::~CreateObject()
{
    std::cout << "Destructing texture" << std::endl;

    SDL_DestroyTexture(texture);
}

int IncredibleEngine::BaseFoo::CreateObject::SetTexture(std::string locality, CreateWin& CurrentWindow)
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

int IncredibleEngine::BaseFoo::CreateObject::SetTexture(SDL_Texture& temptexture, CreateWin& CurrentWindow)
{
    texture = &temptexture;
    return 0;
}

SDL_Texture* IncredibleEngine::BaseFoo::CreateObject::GetTexture()
{
    return texture;
}

SDL_Rect* IncredibleEngine::BaseFoo::CreateObject::GetRect()
{
    return &rect;
}

int IncredibleEngine::BaseFoo::CreateObject::GetType()
{
    return type;
}

IncredibleEngine::BaseFoo::Button::Button()
{
    x = 0;
    y = 0;
}

IncredibleEngine::BaseFoo::Button::Button(int posx, int posy) {
    rect.x = x = posx;
    rect.y = y = posy;
}

IncredibleEngine::BaseFoo::Button::Button(int posx, int posy, std::string locality, CreateWin& CurrentWindow) {
    rect.x = x = posx;
    rect.y = y = posy;

    SetTexture(locality, CurrentWindow);
}

IncredibleEngine::BaseFoo::Button::~Button() {
}

IncredibleEngine::BaseFoo::Player::Player() {
    hp = 100;
    damage = 10;
    absolutePosX = 0;
    absolutePosY = 0;
}

/// Some additioanl foo
///////////////////////////////////////////////////////////////////////////////////

int IncredibleEngine::AdditionalFoo::IE_CheckError(BaseFoo::CreateWin& CurrentWindow) {
    if (CurrentWindow.GetWindow() == NULL) return -1;
    return 0;
}

int IncredibleEngine::AdditionalFoo::IE_DrawTextures(BaseFoo::CreateWin& CurrentWindow, ie::BaseFoo::CreateObject** texturearr) {
    SDL_RenderClear(CurrentWindow.GetRender());

    for (int i = 0; i < 2; i++) {
        if (texturearr[i]->GetTexture() == NULL) return -1;
        SDL_RenderCopy(CurrentWindow.GetRender(), texturearr[i]->GetTexture(), NULL, texturearr[i]->GetRect());
    }
    SDL_RenderPresent(CurrentWindow.GetRender());
    return 0;
}

int IncredibleEngine::AdditionalFoo::IE_WinInteract(BaseFoo::CreateWin& CurrentWindow, ie::BaseFoo::CreateObject** texturearr) {
    if (SDL_PollEvent(CurrentWindow.GetEvent())) {
        if (CurrentWindow.GetEvent()->type == SDL_QUIT) {
            return 1;
        }
        
        switch (CurrentWindow.GetEvent()->key.keysym.sym) {
        case SDLK_d:
            for (int i = 0; i < 4; i++){
                if (texturearr[i]->GetType() == IE_BACKGROUND)
                texturearr[i]->GetRect()->x += 2;
            }
        default:
            break;
        }
    }

    return 0;
}

/// Docker foo

IncredibleEngine::TextureDocker::IE_Textures::IE_Textures(std::string locality, std::string inputName, TextureType inputType, ie::BaseFoo::CreateWin& CurrentWindow)
{
    SDL_Surface* temptexture = SDL_LoadBMP(locality.c_str());
    dockerTexture = SDL_CreateTextureFromSurface(CurrentWindow.GetRender(), temptexture);
    SDL_FreeSurface(temptexture);

    textureName = inputName;
    type = inputType;
}

SDL_Texture& IncredibleEngine::TextureDocker::IE_Textures::GetTexture()
{
    return* dockerTexture;
}
