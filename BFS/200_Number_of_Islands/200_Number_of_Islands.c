void helpler(char** grid, int gridSize, int* gridColSize, int i, int j, char nums){
    grid[i][j] = nums;
    //up
    if(i != 0){
        if(grid[i-1][j] == '1'){
            helpler(grid, gridSize, gridColSize, i-1, j, nums);
        }
    }
    //down
    if(i != gridSize-1){ 
        if(grid[i+1][j] == '1'){
            helpler(grid, gridSize, gridColSize, i+1, j, nums);
        }
    }
    //left
    if(j != 0){
        if(grid[i][j-1] == '1'){
            helpler(grid, gridSize, gridColSize, i, j-1, nums);
        }
    }
    //right
    if(j != (*gridColSize)-1){
        if(grid[i][j+1] == '1'){
            helpler(grid, gridSize, gridColSize, i, j+1, nums);
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    char nums = '2';
    int time = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < (*gridColSize); j++){
            if(grid[i][j] == '1'){
                helpler(grid, gridSize, gridColSize, i, j, nums);
                time++;         
            }
        }
    }
    /*
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    */
    return time;
}