#include "WormGame.h"
#include <iostream>

// Using std namespace for basic I/O
using namespace std;

// Global Variables for game appearance and grid
Color green = {173, 204, 96, 255};
Color darkGreen = {3, 51, 24, 255};
int cellSize = 30;
int cellCount = 25;
int offset = 75;

double lastUpdateTime = 0;

// Helper Functions
bool eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

bool ElementInDeque(Vector2 element, deque<Vector2> deque) {
    for (size_t i = 0; i < deque.size(); i++) {
        if (Vector2Equals(deque[i], element)) {
            return true;
        }
    }
    return false;
}

// --- WormGameSnake Class Implementation ---
WormGameSnake::WormGameSnake() : body({Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}}), direction({1, 0}), addSegment(false) {}

void WormGameSnake::Draw() {
    for (unsigned int i = 0; i < body.size(); i++) {
        float x = body[i].x;
        float y = body[i].y;
        Rectangle segment = {offset + x * cellSize, offset + y * cellSize, (float)cellSize, (float)cellSize};
        DrawRectangleRounded(segment, 0.5, 6, darkGreen);
    }
}

void WormGameSnake::Update() {
    body.push_front(Vector2Add(body[0], direction));
    if (!addSegment) {
        body.pop_back();
    } else {
        addSegment = false;
    }
}

void WormGameSnake::Reset() {
    body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    direction = {1, 0};
}

// --- WormGameFood Class Implementation ---
WormGameFood::WormGameFood() : position({0, 0}), texture({0}) {}
WormGameFood::~WormGameFood() {}

void WormGameFood::Load(deque<Vector2> snakeBody) {
    Image image = LoadImage(TextFormat("%s/Graphics/food.png", GetApplicationDirectory()));
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = GenerateRandomPos(snakeBody);
}

void WormGameFood::Unload() {
    UnloadTexture(texture);
}

void WormGameFood::Draw() {
    DrawTexture(texture, offset + position.x * cellSize, offset + position.y * cellSize, WHITE);
}

Vector2 WormGameFood::GenerateRandomCell() {
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return Vector2{x, y};
}

Vector2 WormGameFood::GenerateRandomPos(deque<Vector2> snakeBody) {
    Vector2 newPos = GenerateRandomCell();
    while (ElementInDeque(newPos, snakeBody)) {
        newPos = GenerateRandomCell();
    }
    return newPos;
}

// --- WormGameMain Class Implementation ---
WormGameMain::WormGameMain() : running(true), score(0) {}
WormGameMain::~WormGameMain() {}

void WormGameMain::Load() {
    InitAudioDevice();
    eatSound = LoadSound(TextFormat("%s/Sounds/eat.mp3", GetApplicationDirectory()));
    wallSound = LoadSound(TextFormat("%s/Sounds/wall.mp3", GetApplicationDirectory()));
    food.Load(snake.body);
}

void WormGameMain::Unload() {
    food.Unload();
    UnloadSound(eatSound);
    UnloadSound(wallSound);
    CloseAudioDevice();
}

void WormGameMain::Draw() {
    food.Draw();
    snake.Draw();
}

void WormGameMain::Update() {
    if (running) {
        snake.Update();
        CheckCollisionFood();
        CheckCollisionWithEdges();
        CheckCollisionWithTail();
    }
}

void WormGameMain::CheckCollisionFood() {
    if (Vector2Equals(snake.body[0], food.position)) {
        food.position = food.GenerateRandomPos(snake.body);
        snake.addSegment = true;
        score++;
        PlaySound(eatSound);
    }
}

void WormGameMain::CheckCollisionWithEdges() {
    if (snake.body[0].x == cellCount || snake.body[0].x == -1 ||
        snake.body[0].y == cellCount || snake.body[0].y == -1) {
        GameOver();
    }
}

void WormGameMain::CheckCollisionWithTail() {
    deque<Vector2> headlessBody = snake.body;
    headlessBody.pop_front();
    if (ElementInDeque(snake.body[0], headlessBody)) {
        GameOver();
    }
}

void WormGameMain::GameOver() {
    snake.Reset();
    food.position = food.GenerateRandomPos(snake.body);
    running = false;
    score = 0;
    PlaySound(wallSound);
}

// --- Main Game Entry Point ---
void playWormGame() {
    cout << "Starting the Worm Game..." << endl;
    InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount, "Worm Game");
    SetTargetFPS(60);

    WormGameMain game;
    game.Load();

    while (!WindowShouldClose()) {
        if (eventTriggered(0.2)) {
            game.Update();
        }

        if (IsKeyPressed(KEY_UP) && game.snake.direction.y != 1) {
            game.snake.direction = {0, -1};
            game.running = true;
        }
        if (IsKeyPressed(KEY_DOWN) && game.snake.direction.y != -1) {
            game.snake.direction = {0, 1};
            game.running = true;
        }
        if (IsKeyPressed(KEY_LEFT) && game.snake.direction.x != 1) {
            game.snake.direction = {-1, 0};
            game.running = true;
        }
        if (IsKeyPressed(KEY_RIGHT) && game.snake.direction.x != -1) {
            game.snake.direction = {1, 0};
            game.running = true;
        }
        if (IsKeyPressed(KEY_ESCAPE)) {
            // This will be caught by WindowShouldClose()
        }

        BeginDrawing();
        ClearBackground(green);
        DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5, (float)cellCount * cellSize + 10, (float)cellCount * cellSize + 10}, 5, darkGreen);
        DrawText("Score:", offset - 5, 20, 40, darkGreen);
        DrawText(TextFormat("%i", game.score), offset + 150, 20, 40, darkGreen);
        game.Draw();
        EndDrawing();
    }

    game.Unload();
    CloseWindow();
}