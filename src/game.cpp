#include "game.h"
#include <iostream>
#include "SDL.h"

#define MIN_DIFFICULTY 0
#define MEDIUM_DIFFICULTY 1
#define MAX_DIFFICULTY 2

float GameSpeedLUT[3] = {0.07f, 0.1f, 0.2f};
float GameSpeedStepLUT[3] = {0.01f, 0.02f, 0.03f};

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::SetDifficultyFromUser()
{
  int difficulty;

  while(true)
  {
    std::cout << "Please introduce the desired difficulty (0 - Easy, 1 - Medium, 2 - Hard):";
    std::cin >> difficulty;
    std::cout << std::endl;

    if (difficulty < MIN_DIFFICULTY || difficulty > MAX_DIFFICULTY)
    {
      std::cout << "Please introduce difficulty 0 (Easy), 1 (Medium), 2 (Hard)!\n";
      std::cout << "Anything else introduced at this step is not valid.\n";
      std::cout << "Game will start after a valid difficulty is introduced!!!\n";
      continue;
    }
    else
    {
      difficulty_ = difficulty;
      if (MIN_DIFFICULTY == difficulty)
        std::cout << "Easy difficulty is set!\n";
      else if (MEDIUM_DIFFICULTY == difficulty)
        std::cout << "Medium difficulty is set!\n";
      else
        std::cout << "Hard difficulty is set!\n";

      float speed = GameSpeedLUT[difficulty];
      float speedStep = GameSpeedStepLUT[difficulty];
      snake.SetGameParams(speed, speedStep);
      break;
    }
  }
}

int Game::GetDifficulty() const
{
  return difficulty_;
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update(running);
    renderer.Render(snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update(bool &running_ref) {
  if (!snake.GetAliveState()) { running_ref = false; return;}

  snake.Update();

  int new_x = static_cast<int>(snake.GetHeadX());
  int new_y = static_cast<int>(snake.GetHeadY());

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.IncrementSnakeSpeed();
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }