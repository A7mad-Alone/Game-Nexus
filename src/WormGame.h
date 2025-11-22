#ifndef WORMGAME_H
#define WORMGAME_H

#include <deque>
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include <bits/stdc++.h>

class WormGameSnake {
public:
    std::deque<Vector2> body;
    Vector2 direction;
    bool addSegment;

    WormGameSnake();
    void Draw();
    void Update();
    void Reset();
};

class WormGameFood {
public:
    Vector2 position;
    Texture2D texture;

    WormGameFood();
    ~WormGameFood();
    void Load(std::deque<Vector2> snakeBody);
    void Unload();
    void Draw();
    Vector2 GenerateRandomCell();
    Vector2 GenerateRandomPos(std::deque<Vector2> snakeBody);
};

class WormGameMain {
public:
    WormGameSnake snake;
    WormGameFood food;
    bool running;
    int score;
    Sound eatSound;
    Sound wallSound;

    WormGameMain();
    ~WormGameMain();

    void Load();
    void Unload();
    void Draw();
    void Update();
    void CheckCollisionFood();
    void CheckCollisionWithEdges();
    void CheckCollisionWithTail();
    void GameOver();
};

bool eventTriggered(double interval);
bool ElementInDeque(Vector2 element, std::deque<Vector2> deque);
void playWormGame();

#endif // WORMGAME_H
