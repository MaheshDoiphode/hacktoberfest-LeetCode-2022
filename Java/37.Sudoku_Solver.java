class Solution {
    public void solveSudoku(char[][] board) {
         if(board == null || board.length < 9){
            return;
        }
        solve(board);    
    }
    public  boolean solve(char[][] board) {
        int n = board.length;
        int r = -1;
        int c = -1;

        boolean emptyLeft = true;
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n; j++) {
                if(board[i][j] == '.'){
                    r = i;
                    c = j;
                    emptyLeft = false;
                    break;
                }
            }
                if(emptyLeft == false){
                    break;
                }
            }
        if(emptyLeft == true){
            return true;//Soduku solved
        }
        //backtrack
        for (char i = '1'; i <= '9' ; i++) {
            if(isSafe(board,r,c,i)){
                board[r][c] = i;
                if (solve(board)){
                    return true; // found the ans
                }
                else{
                    board[r][c] = '.';
                }
            }
        }
        return false;
    }
     boolean isSafe(char[][] board, int r, int c, char n){
        for (int i = 0; i < board.length; i++) {
            if(n == board[r][i]){
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
        for (r = rowStart ; r < rowStart+sqrt ; r++) {
            for (c = colStart; c < colStart+sqrt ; c++) {
                if(board[r][c] ==  n){
                    return false;
                }
            }
        }
        return true;
    }
}
