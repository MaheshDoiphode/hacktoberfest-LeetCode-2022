package com.Ayush.Backtracking;

// https://leetcode.com/problems/sudoku-solver/
 // Runtime 11 ms Beats 76.40%
public class SodukoSolver {
    public static void main(String[] args) {

    }
    public void solveSudoku(char[][] board){
        if(solve(board)){
            return;
        }
    }
    public static boolean solve(char[][] board) {
        int n = board.length;
        int r = -1;
        int c = -1;

        boolean emptyLeft = true;
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n; j++) {
                if(board[i][j] == 0){
                    r = i;
                    c = j;
                    emptyLeft = false;
                    break;
                }
                if(emptyLeft == false){
                    break;
                }
            }
        }
        if(emptyLeft == true){
            return true;//Soduku solved
        }
        //backtrack
        for (char i = '1'; i < '9' ; i++) {
            if(isSafe(board,r,c,i)){
                board[r][c] = i;
                if (solve(board)){
                    return true; // found the ans
                }
                else{
                    board[r][c] = '0';
                }
            }
        }
        return false;
    }
    static boolean isSafe(char[][] board, int r, int c, char n){
        for (int i = 0; i < board.length; i++) {
            if(n == board[i][c]){
                return false;
            }
        }
        for (char[] nums:board){
            if(nums[c] == n){
                return false;
            }
        }
        int sqrt = (int)(Math.sqrt(board.length));
        int rowStart = r - r%sqrt;
        int colStart = c - c%sqrt;
        for (int i = rowStart ; i < rowStart+sqrt ; i++) {
            for (int j = colStart; j < colStart+sqrt ; j++) {
                if(board[i][j] ==  n){
                    return false;
                }
            }
        }
        return true;
    }
}
