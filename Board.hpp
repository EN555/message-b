//
// Created by eviat on 3/16/2021.
//

#ifndef MESSAGEBOARD_A_MAIN_BOARD_HPP
#define MESSAGEBOARD_A_MAIN_BOARD_HPP

#include "Direction.hpp"
#include <vector>
#include <string>
using namespace std;    //need to delete that

namespace ariel{

class Board{
    public:
        Board();
        void post(unsigned int row, unsigned int column, Direction direction,std::string const& post);
        std:: string read(unsigned int row,unsigned int column,Direction direction, unsigned int len);
        void  show();
    private:
        std::vector<std::vector<char>> board;
};




}


#endif //MESSAGEBOARD_A_MAIN_BOARD_HPP
