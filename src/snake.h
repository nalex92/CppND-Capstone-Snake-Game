#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x_(grid_width / 2),
        head_y_(grid_height / 2) {}

  void Update();

  void SetGameParams(float &, float &);
  bool GetAliveState() const;
  float GetHeadX() const;
  float GetHeadY() const;

  void IncrementSnakeSpeed();

  void GrowBody();
  bool SnakeCell(int x, int y);

  Direction direction = Direction::kUp;

  int size{1};
  std::vector<SDL_Point> body;

 private:
  float speed_{0.08f};
  float speed_step_{0.02f};
  bool alive_{true};
  float head_x_;
  float head_y_;

  bool CheckMargins(SDL_Point &current_head_cell);
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif