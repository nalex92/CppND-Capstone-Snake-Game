#ifndef STATISTICS_H
#define STATISTICS_H

#include "game.h"

class Statistics
{
public:
    void SetGamestatistics(const Game &game);
    void WriteGameStatistics();

private:
    int difficulty_;
    int score_;
    int size_;
};

#endif // STATISTICS_H