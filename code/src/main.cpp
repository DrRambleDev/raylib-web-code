#include <raylib.h>

#include <iostream>
#include <sstream>
#include <vector>

class Ball {
 public:
  Ball();
  void Update();
  void Draw();
  void moveOnKeys();
  void moveWithGravity(float gravity);

 private:
  int x;
  int y;
  int speedX;
  int speedY;
  int radius;
};

int count;

using std::stringstream;
using std::vector;

Ball::Ball() {
  x = 100;
  y = 100;
  speedX = 5;
  speedY = 5;
  radius = 15;
}

void Ball::Update() {
  x += speedX;
  y += speedY;

  if (x + radius >= GetScreenWidth() || x - radius <= 0) speedX *= -1;

  if (y + radius >= GetScreenHeight() || y - radius <= 0) speedY *= -1;
}

void Ball::moveOnKeys() {
  if (IsKeyDown(KEY_UP) == true) y -= speedY;
  if (IsKeyDown(KEY_DOWN) == true) y += speedY;
  if (IsKeyDown(KEY_LEFT) == true) x -= speedX;
  if (IsKeyDown(KEY_RIGHT) == true) x += speedX;
}

void Ball::Draw() { DrawCircle(x, y, radius, BLACK); }

void Ball::moveWithGravity(float gravity) {
  if (y + radius < GetScreenHeight() - gravity) {
    speedY -= gravity;
  }

  if (y + radius + speedY >= GetScreenHeight()) {
    speedY = -speedY;
    count++;
  }
  if (y + speedY - radius < 0) {
    speedY = -speedY;
  }
  if (x + speedX - radius < 0) {
    speedX = -speedX;
    speedX--;
  }
  if (x + radius + speedX >= GetScreenWidth()) {
    speedX = -speedX;
    speedX++;
  }

  // move
  x += speedX;
  y += speedY;
}

Ball ball = Ball();

int main(void) {
  InitWindow(300, 300, "Window");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLUE);
    ball.Draw();
    ball.moveWithGravity(-1.5);
    EndDrawing();
  }
  CloseWindow();
}
