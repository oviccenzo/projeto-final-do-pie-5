#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// CONSTANTES
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

struct Placar
{
    int playerLeft, playerRight;
};

struct Player {
    float x, y;
    int w, h;
    float speed;
};

struct Ball {
    float x, y;
    int size;
    float velX, velY;
};

void DesenharPlacar(SDL_Renderer* renderer, TTF_Font* font, char who, Placar* placar)
{
    SDL_Color color = {255, 255, 255, 255};

    const char* c_str;
    int x;

    if(who=='L')
    {
        std::string str = std::to_string(placar->playerLeft); 
        c_str = str.c_str(); 
    }
    else if(who=='R')
    {
        std::string str = std::to_string(placar->playerRight); 
        c_str = str.c_str(); 
    }
    else
    {
        c_str = "|";
    }

    SDL_Surface* surface = TTF_RenderText_Solid(font, c_str, color);

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    if(who=='L')
    {
        x = SCREEN_WIDTH/2 - surface->w - 20;
    }
    else if(who=='R')
    {
        x = SCREEN_WIDTH/2 + 20;
    }
    else
    {
        x = (SCREEN_WIDTH-surface->w)/2;
    }

    SDL_Rect rect = {
        x,
        20,
        surface->w,
        surface->h
    };

    SDL_RenderCopy(renderer, texture, nullptr, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

int main()
{
    // INICIALIZANDO ESTRUTURA
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window* window = SDL_CreateWindow(
        "Pong",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        0
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    TTF_Font* font = TTF_OpenFont("assets/PixeloidMono.ttf", 24);

    Player playerBase = {
        20,(SCREEN_HEIGHT-100)/2,
        20,100,
        400
    };

    Player playerLeft = playerBase;
    Player playerRight = playerBase;
    playerRight.x = SCREEN_WIDTH-playerRight.w-playerBase.x;

    Ball ballBase ={
        (SCREEN_WIDTH-16)/2, (SCREEN_HEIGHT-16)/2,
        16,
        300, 300
    };

    Ball ball = ballBase;

    Placar placar = {0,0};

    bool running = true;
    Uint32 lastTick = SDL_GetTicks();

    while(running)
    {
        Uint32 currentTick = SDL_GetTicks();
        float deltaTime = (currentTick - lastTick) / 1000.0f;
        lastTick = currentTick;

        SDL_Event event;

        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                running = false;
        }

        const Uint8* keys = SDL_GetKeyboardState(nullptr);

        // Jogador esquerdo
        if(keys[SDL_SCANCODE_W])
            playerLeft.y -= playerLeft.speed * deltaTime;

        if(keys[SDL_SCANCODE_S])
            playerLeft.y += playerLeft.speed * deltaTime;

        if(playerLeft.y < 0)
            playerLeft.y = 0;

        if(playerLeft.y > SCREEN_HEIGHT - playerLeft.h)
            playerLeft.y = SCREEN_HEIGHT - playerLeft.h;

        // Jogador direito
        if(keys[SDL_SCANCODE_UP])
            playerRight.y -= playerRight.speed * deltaTime;

        if(keys[SDL_SCANCODE_DOWN])
            playerRight.y += playerRight.speed * deltaTime;

        if(playerRight.y < 0)
            playerRight.y = 0;

        if(playerRight.y > SCREEN_HEIGHT - playerRight.h)
            playerRight.y = SCREEN_HEIGHT - playerRight.h;

        // Movimento da bola
        ball.x += ball.velX * deltaTime;
        ball.y += ball.velY * deltaTime;

        // Colisão com teto e chão
        if(ball.y <= 0)
        {
            ball.y = 0;
            ball.velY *= -1;
        }

        if(ball.y >= SCREEN_HEIGHT - ball.size)
        {
            ball.y = SCREEN_HEIGHT - ball.size;
            ball.velY *= -1;
        }

        // Colisão com o jogador da esquerda
        if(ball.x <= playerLeft.x + playerLeft.w)
        {
            if(ball.y + ball.size >= playerLeft.y && ball.y <= playerLeft.y + playerLeft.h)
            {
                ball.x = playerLeft.x + playerLeft.w + 1;
                ball.velX *= -1;
            }
            else {
                placar.playerRight++;
                ball.x = ballBase.x;
                ball.y = ballBase.y;
                ball.velX *= -1;
            }
        }

        // Colisão com o jogador da direita
        if(ball.x >= playerRight.x - ball.size)
        {
            if(ball.y + ball.size >= playerRight.y && ball.y <= playerRight.y + playerRight.h)
            {
                ball.x = playerRight.x - ball.size - 1;
                ball.velX *= -1;
            }
            else {
                placar.playerLeft++;
                ball.x = ballBase.x;
                ball.y = ballBase.y;
                ball.velX *= -1;
            }
        }

        // Desenhar
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Rect rectLeft = {
            (int)playerLeft.x,
            (int)playerLeft.y,
            playerLeft.w,
            playerLeft.h
        };

        SDL_Rect rectRight = {
            (int)playerRight.x,
            (int)playerRight.y,
            playerRight.w,
            playerRight.h
        };

        SDL_Rect RectBall = {
            (int)ball.x,
            (int)ball.y,
            ball.size,
            ball.size
        };

        

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_RenderFillRect(renderer, &rectLeft);
        SDL_RenderFillRect(renderer, &rectRight);
        SDL_RenderFillRect(renderer, &RectBall);
        DesenharPlacar(renderer, font, '|', &placar);
        DesenharPlacar(renderer, font, 'R', &placar);
        DesenharPlacar(renderer, font, 'L', &placar);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    SDL_Quit();

    return 0;
}