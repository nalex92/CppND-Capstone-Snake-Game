#include "snake.h"
#include <cmath>
#include <iostream>

// Check if the snake hits the margins of the window
// alive = 0 if snake hits the margin of the window
bool Snake::CheckMargins(SDL_Point &current_head_cell) {
  if ((current_head_cell.x > grid_width) || (current_head_cell.x < 0))
    alive_ = false;

  if ((current_head_cell.y > grid_height) || (current_head_cell.y < 0))
    alive_ = false;
  
  return alive_;
}

// Setters for snake members related to difficulty
void Snake::SetGameParams(float &speed_ref, float &speed_step_ref)
{
  speed_ = speed_ref;
  speed_step_ = speed_step_ref;
}

bool Snake::GetAliveState() const
{
  return alive_;
}

float Snake::GetHeadX() const
{
  return head_x_;
}

float Snake::GetHeadY() const
{
  return head_y_;
}

// Increments speed of the snake
void Snake::IncrementSnakeSpeed()
{
  speed_ += speed_step_;
}

void Snake::Update() {
  SDL_Point prev_cell{
      static_cast<int>(head_x_),
      static_cast<int>(head_y_)};  // We first capture the head's cell before updating.

  UpdateHead();

  SDL_Point current_cell{
      static_cast<int>(head_x_),
      static_cast<int>(head_y_)};  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell);
  }
}

void Snake::UpdateHead() {
  switch (direction) {
    case Direction::kUp:
      head_y_ -= speed_;
      break;

    case Direction::kDown:
      head_y_ += speed_;
      break;

    case Direction::kLeft:
      head_x_ -= speed_;
      break;

    case Direction::kRight:
      head_x_ += speed_;
      break;
  }
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else {
    growing = false;
    size++;
  }

  // Check if the snake has died.
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive_ = false;
    }
  }

  CheckMargins(current_head_cell);

}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
  if (x == static_cast<int>(head_x_) && y == static_cast<int>(head_y_)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}