#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "statistics.h"

int main() {
  constexpr std::size_t kFramesPerSecond{70};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{42};
  constexpr std::size_t kGridHeight{42};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);

  Controller controller;

  Game game(kGridWidth, kGridHeight);
  game.SetDifficultyFromUser();
  game.Run(controller, renderer, kMsPerFrame);

  Statistics statistics;
  statistics.SetGamestatistics(game);
  statistics.WriteGameStatistics();
  
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}