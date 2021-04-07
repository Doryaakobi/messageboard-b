#include "doctest.h"
#include "Board.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace ariel;

const int max_message = 100;
const int max_rows = 500;
const int max_column = 500;
const int test = 100;

string gen_random()
{
    const int ascii_s = 26;
    const int ascii_e = 126;

    string randString;
    int message_length = rand() % max_message;
    for (int i = 0; i < message_length; ++i)
        randString += rand()%(ascii_e-ascii_s)+ascii_s;

    return randString;
}

TEST_CASE("Test 1 Post & Read")
{
    Board board;
    srand((unsigned)time(0));
    Direction orientation;

    for (uint i = 0; i < test; i++)
    {
        uint rand_row = rand() % max_rows;
        uint rand_col = rand() % max_column;
        string rand_message = gen_random();
        if ((rand() % 2+1) == 0)
            {
                orientation = Direction::Horizontal;
            }
        else
        {
            orientation = Direction::Vertical;
        }
        CHECK_NOTHROW(board.post(rand_row, rand_col, orientation, rand_message));
        CHECK(board.read(rand_row, rand_col, orientation, rand_message.size()) == rand_message);
    }
}

TEST_CASE("Test 2 Overlap messages")
{
    Board board;
    board.post(0, 0, Direction::Horizontal, "Dor311557425");
    CHECK(board.read(0, 0, Direction::Horizontal, 11) == "Dor311557425");
    board.post(0, 1, Direction::Vertical, "0502151255");
    CHECK(board.read(0, 1, Direction::Horizontal, 10) == "0502151255");
    CHECK(board.read(0, 0, Direction::Horizontal, 3) == "D0r");
    board.post(0, 2, Direction::Horizontal, "aaaaa");
    CHECK(board.read(0, 1, Direction::Vertical, 3) == "0a0");
    board.post(0, 2, Direction::Vertical, "ddddd");
    CHECK(board.read(0, 0, Direction::Horizontal, 7) == "D0d3115");
    board.post(0, 0, Direction::Vertical, "HELLO");
    CHECK(board.read(0, 0, Direction::Horizontal, 3) == "H0d");
    board.post(0, 4, Direction::Vertical, "World");
    CHECK(board.read(0, 0, Direction::Horizontal, 7) == "H0d3W15");
}


