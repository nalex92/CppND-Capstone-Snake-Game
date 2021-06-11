#include "statistics.h"
#include <iostream>
#include <fstream>

using namespace std;

void Statistics::SetGamestatistics(const Game &game)
{
    difficulty_ = game.GetDifficulty();
    size_ = game.GetSize();
    score_ = game.GetScore();
}

void Statistics::WriteGameStatistics()
{
    ofstream OutFileHandle;
    OutFileHandle.open("statistics.txt", std::ios_base::app);
    OutFileHandle << "Difficulty: " << difficulty_ << "\n";
    OutFileHandle << "Score: " << score_ << "\n";
    OutFileHandle << "Size: " << size_ << "\n\n";

    OutFileHandle.close();
}