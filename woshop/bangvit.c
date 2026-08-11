#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    int x, y;
    int w, h;
    int speed;
    int alive;
} Duck;

Duck duck;
int score = 0;

void resetDuck() {
    duck.x = -80;
    duck.y = rand() % 400 + 50;
    duck.w = 80;
    duck.h = 60;
    duck.speed = rand() % 5 + 3;
    duck.alive = 1;
}

int main(int argc, char *argv[]) {

    srand(time(NULL));

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL Init Error\n");
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Duck Hunt",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        0
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
                                                SDL_RENDERER_ACCELERATED);

    resetDuck();

    int running = 1;
    SDL_Event event;

    while (running) {

        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT)
                running = 0;

            if (event.type == SDL_MOUSEBUTTONDOWN) {

                int mx = event.button.x;
                int my = event.button.y;

                if (duck.alive &&
                    mx >= duck.x &&
                    mx <= duck.x + duck.w &&
                    my >= duck.y &&
                    my <= duck.y + duck.h) {

                    score++;
                    printf("Hit! Score = %d\n", score);

                    duck.alive = 0;
                }
            }
        }

        if (duck.alive) {
            duck.x += duck.speed;

            if (duck.x > WIDTH)
                resetDuck();
        } else {
            resetDuck();
        }

        SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
        SDL_RenderClear(renderer);

        if (duck.alive) {

            SDL_Rect body = {
                duck.x,
                duck.y,
                duck.w,
                duck.h
            };

            SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
            SDL_RenderFillRect(renderer, &body);

            SDL_Rect wing = {
                duck.x + 15,
                duck.y - 10,
                30,
                20
            };

            SDL_SetRenderDrawColor(renderer, 255, 150, 0, 255);
            SDL_RenderFillRect(renderer, &wing);
        }

        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}