#pragma once
#include<bits/stdc++.h>

using namespace std;

#include "Entity.hpp"
#include "RenderWindow.hpp"


class Player: public Entity
{
    public:
        Player(float srcX, float srcY, float srcW, float srcH, float desX, float desY, float desW, float desH, SDL_Texture* tex);
        float getHealthPoints();
        void setHealthPoints(float x);
        bool checkDeath();
        void setStateTexture(int x);
        SDL_Rect getHealthBar();
        SDL_Rect getHitBox();
        SDL_Rect getRenderBoxValues();
        void moveCharacter();
        void updateFrame(float x, float y);
        void updatePlayerMovement(vector<Entity> &Obstacles, float currentFrameTime, bool &gameRunning);
        bool outOfMap();

    private:

        float movementSpeed;
        bool movingLeft, movingRight, movingUp, movingDown, attacking;

        int frame;

        int frameDuration;

        int state;

        int textureState;

        float srcXFrames[20];

        float srcYFrames[4][4];

        int maxFrames[4];

        int movingDirection;
        int movingDirections;

        float healthPoints;

        SDL_Rect healthBar;

        float lastFrameTime;

};

Player setupPlayerTexture(RenderWindow& window);