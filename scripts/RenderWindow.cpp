#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

using namespace std;

#include "RenderWindow.hpp"
#include "Entity.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
:window(NULL), renderer(NULL)
{
  window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

  if (window == NULL)
      SDL_Log("Window failed to initialize");

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL)
        SDL_Log("Failed to load texture");

    return texture;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity)
{
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dest;
    dest.x = p_entity.getX();
    dest.y = p_entity.getY();
    dest.w = p_entity.getCurrentFrame().w * 2;
    dest.h = p_entity.getCurrentFrame().h * 2;

    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dest);
}

void RenderWindow::display()
{
     SDL_RenderPresent(renderer);
}