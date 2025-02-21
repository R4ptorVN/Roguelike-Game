#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Player.hpp"

int main(int argc, char* args [])
{

    if (SDL_Init(SDL_INIT_VIDEO))
        SDL_Log("Failed to initialize SDL2");
    if (!(IMG_Init(IMG_INIT_PNG)))
        SDL_Log("Failed to initialize SDL2_image");

    RenderWindow window("GAME v1.0", 1280, 720);

    SDL_Texture* grassTexture = window.loadTexture("resources/grass.png");
    SDL_Texture* girlWalk = window.loadTexture("resources/GirlWalk.png");
    SDL_Texture* girlIdle = window.loadTexture("resources/GirlIdle.png");
    SDL_Texture* rock1Texture = window.loadTexture("resources/Rock1.png");
    SDL_Texture* rock2Texture = window.loadTexture("resources/Rock2.png");
    SDL_Texture* rock3Texture = window.loadTexture("resources/Rock3.png");

    int movementSpeed = 5;
    const int frameDistance = 128;

    Entity background(0, 0, 1280, 720, 0, 0, 1280 * 1.2, 720 * 1.2, grassTexture);
    Entity rock1(0, 0, 32, 32, 300, 300, 32 * 5, 32 * 5, rock1Texture);
    Entity rock2(0, 0, 37, 33, 800, 200, 37 * 3, 33 * 3, rock2Texture);
    Entity rock3(0, 0, 25, 26, 700, 550, 25 * 5, 26 * 5, rock3Texture);
    Entity rock4(0, 0, 37, 33, 175, 100, 37 * 3, 33 * 3, rock2Texture);

    rock4.setFlip(SDL_FLIP_HORIZONTAL);

    vector<Entity> Obstacles;
    Obstacles.push_back(rock1);
    Obstacles.push_back(rock2);
    Obstacles.push_back(rock3);
    Obstacles.push_back(rock4);

    vector<SDL_Texture*> mainCharacterAnimations;
    mainCharacterAnimations.push_back(girlIdle);
    mainCharacterAnimations.push_back(girlWalk);
    Player mainCharacter(42, 55, 41, 75, 550, 250, 41, 75, mainCharacterAnimations);



    bool gameRunning = true;

    SDL_Event event;

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
            mainCharacter.updateMovement(event, Obstacles);
        }
        window.clear();
        window.render(background);
        for (Entity& object : Obstacles)
            window.render(object);
        window.render(mainCharacter);
        window.display();
    }
    window.cleanUp();
    SDL_Quit();
    return 0;
}
