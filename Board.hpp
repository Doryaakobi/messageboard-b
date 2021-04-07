#include "Direction.hpp"
#include <iostream>
#include <map>
using namespace std;
using namespace ariel;


struct letter{
    char ch = '_';
};


namespace ariel
{
    class Board
    {
        uint min_row,min_col,max_row,max_col;
        map<uint,map<uint,letter>> board;

        public:
        // constructor
        Board(){
            map<uint, map<uint,letter>> board;
            min_row = min_col = INT32_MAX;
            max_row = max_col = 0;
        }

        // deconstructor
        ~Board(){}

        void post(uint row, uint col, ariel::Direction, const string &message);
        string read(uint row, uint col, ariel::Direction, uint length);
        void show();
    };
}
