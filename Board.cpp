#include <iostream>
#include "Board.hpp"
using namespace std;

namespace ariel
{
    /**
     * post a message on the message board, in a given the position and orientation of the message.
     * In case there's a message already in the same position it is overwritten. 
     * @param row
     * @param col
     * @param orientation
     * @param message
     */
    void Board::post(uint row, uint col, ariel::Direction orientation, const string &message)
    {
        this->max_row = max(this->max_row, row);
        this->max_col = max(this->max_col, col);
        this->min_row = min(this->min_row, row);
        this->min_col = min(this->min_col, col);

        if (orientation == Direction::Horizontal)
        {
            for (char c : message)
            {
                this->board[row][col].ch = c;
                col++;
            }
        }
        else
        {
            for (char c : message)
            {
                this->board[row][col].ch = c;
                row++;
            }
        }
    }



    /**
     * read - the position where to start reading the message on the board,
     * from the row and column position with a number of characters to read in the chosen orientation.
     * @param row
     * @param col
     * @param orientation
     * @param lenght - number of characters
     * @return the message on the board.
     */
    string Board::read(uint row, uint col, ariel::Direction orientation, uint length)
    {
        string message;
        for(int i=0; i < length ; i++){
            message += this->board[row][col].ch;
            if(orientation == Direction::Horizontal){
                col++;
            }else row++;
        }

        return message;
    }



    /**
     * show - displays the message board.
     */
    void Board::show()
    {
        for(uint i = this->min_row; i <= this->max_row; i++){
            for(uint j = this->min_col; j <= this->max_col; j++){
                cout << this->board[i][j].ch << "";
            }
            cout << "\n\n";
        }
    }

}