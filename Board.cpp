//
// Created by eviat on 3/16/2021.
//
#include <iostream>
#include "Board.hpp"
#include <vector>
#include <string>

namespace ariel{
 const char PLACE = '_';
 const int INIT = 5;

    Board::Board()
    {
        board.resize(INIT,vector<char>(INIT,PLACE));  // initial dynamic matrix with '_' in all her indexes
    }

    void Board::post(unsigned int row, unsigned int column, Direction direction,std::string const& post) {

        //check the the number of row and column in compare to the matrix
        unsigned int col_len = board[0].size();
        unsigned int row_len = board.size();
//        define the new size of the matrix
        unsigned int new_col_len = column + ((direction == Direction::Horizontal) ? post.length() +1 : 1);
        unsigned int new_row_len = row + ((direction == Direction::Vertical) ? post.length() +1 : 1);

        // check the number of row
        if (row_len < new_row_len) {
            board.resize(new_row_len, vector<char>(col_len, PLACE));
        }

        //chek the number of columns
        if(col_len<new_col_len){
            for(unsigned int i=0; i<board.size(); i++){
                board[i].resize(new_col_len,PLACE);
            }
        }

        for (char character: post) {  //insert the post
            board[row][column] = character;
            (direction == Direction::Horizontal) ? column++ : row++;
        }
    }
    std::string Board::read(unsigned int row,unsigned int column,Direction direction, unsigned int len) {

            if (len == 0) {
                return "";
            }
            //check the the number of row and column in compare to the matrix
            unsigned int col_len = board[0].size();
            unsigned int row_len = board.size();
            //define the new size of the matrix
            unsigned int new_col_len = 1+column + ((direction == Direction::Horizontal) ? len +1 : 1);
            unsigned int new_row_len = 1+row + ((direction == Direction::Vertical) ? len+ 1 : 1);


        // check the number of row
        if (row_len < new_row_len) {
            board.resize(new_row_len, vector<char>(col_len, PLACE));
        }

        //chek the number of columns
        if(col_len<new_col_len){
            for(unsigned int i=0; i<board.size(); i++){
                board[i].resize(new_col_len,PLACE);
            }
        }
            string res;

            if (direction == Direction::Vertical){
                for(unsigned int i=0; i<len; i++){
                    res+= board[row++][column];
                }
            }
            else{
                for(unsigned int i=0; i<len; i++){
                    res+= board[row][column++];
                }
            }
            return res;
        }

        void Board:: show(){

        for(unsigned int i=0 ; i< board.size(); i++){
            for(unsigned int j=0; j< board[0].size(); j++){
                std::cout<< " "<< board[i][j];
            }
                std::cout<<" "<<std::endl;
        }

    }


}
