//always move the shorter lines
#define LEFT    0
#define RIGHT   1
#define EVEN    2
int minimum(int left, int right){
    if(left < right){
        return LEFT; 
    }
    else if(left > right)
    {
        return RIGHT;
    }
    else return EVEN;
}

int maxArea(int* height, int heightSize){
    int p1 = 0;
    int p2 = heightSize-1;
    int length = heightSize-1;
    int maximum = (minimum(height[p1],height[p2]) == LEFT)? height[p1]*length : height[p2]*length;
    while(length > 1){
        length --;
        if(minimum(height[p1], height[p2]) == LEFT){
            p1++;
        } else if(minimum(height[p1], height[p2]) == RIGHT) {
            p2--;
        } else{
            if(minimum(height[p1+1], height[p2-1]) == LEFT) {
                p2--;
            } else {
                p1++;
            }
        }
        maximum = (minimum(height[p1],height[p2]) == LEFT)? ((maximum > height[p1]*length)? maximum : height[p1]*length) : ((maximum > height[p2]*length)? maximum : height[p2]*length);
    }
    return maximum;
}