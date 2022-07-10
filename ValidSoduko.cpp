#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkRow(int row, vector<vector<char>> &board){
        unordered_set<char> us;
        for(int i = 0; i<9; i++){
            if(board[row][i] != '.'){
                
                if(us.find(board[row][i]) == us.end()){
                    us.insert(board[row][i]);
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    
    bool checkCol(int col, vector<vector<char>> &board){
        unordered_set<char> us;
        for(int i = 0; i<9; i++){
            if(board[i][col] != '.'){
                
                if(us.find(board[i][col]) == us.end()){
                    us.insert(board[i][col]);
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    
    bool checkSqr(int row, int col, vector<vector<char>> &board){
        vector<int> v = {-1,0,1};
        unordered_set<char> us;
        for(auto x: v){
            for(auto y:v){
                int a = x+row;
                int b = y+col;
                if(board[a][b] != '.'){
                     if(us.find(board[a][b]) == us.end()){
                        us.insert(board[a][b]);
                    }else{
                        return false;
                    }   
                }
            }
        }
            return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++){
            if(!checkRow(i,board) || !checkCol(i,board)){
                return false;
            }
        }
        vector<int> v = {1,4,7};
        for(auto x: v){
            for(auto y: v){
                if(!checkSqr(x,y,board)){
                    return false;
                }
            }
        }
        return true;
    }
};


int main(){
    vector<vector<char>> board = 
                                {{'5','3','.','.','7','.','.','.','.'}
                                ,{'6','.','.','1','9','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'8','.','.','.','6','.','.','.','3'}
                                ,{'4','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}};
    cout << Solution().isValidSudoku(board) << endl;

}
