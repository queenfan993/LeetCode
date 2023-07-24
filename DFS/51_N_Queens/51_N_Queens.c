/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


bool isValid(int* board, int row, int col) {
    for(int i = 0; i < row; i++) {
        if(board[i] == col || abs(board[i] - col) == abs(i - row)){
            return false;
        } 
    }
    return true;
}

void sloveNQueensHelper(char**** res, int* returnSize, int* board, int row, int n) {
    if(row == n) {
        char** str = calloc(n, sizeof(char*));
        for(int i = 0; i < n; i++) {
            str[i] = calloc(n + 1, sizeof(char));
            for(int j = 0; j < n; j++) {
                str[i][j] = (board[i] == j)? 'Q' : '.';
            }
            str[i][n] = '\0';
        }

        (*returnSize)++;
        *res = realloc(*res, (*returnSize) * sizeof(char**));
        (*res)[(*returnSize)-1] = str;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(isValid(board, row, i)) {
            board[row] = i;
            sloveNQueensHelper(res, returnSize, board, row + 1, n);
        }
    }
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    //initialize
    *returnSize = 0;
    char*** res = calloc(1, sizeof(char**));

    int* board = malloc(n * sizeof(int));
    sloveNQueensHelper(&res, returnSize, board, 0, n);

    //return
    *returnColumnSizes = malloc((*returnSize) * sizeof(int*));
    for(int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = n;
    }

    free(board); 
    return res;
}