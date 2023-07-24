double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if (nums1Size > nums2Size) return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    
    const int k = (nums1Size + nums2Size + 1) / 2;

    int l = 0;
    int r = nums1Size;
            
    while (l < r) {
        const int m1 = l + (r - l) / 2; 
        const int m2 = k - m1; 
        if (nums1[m1] < nums2[m2 - 1])
            l = m1 + 1; 
        else
            r = m1; 
    }

    const int m1 = l;
    const int m2 = k - l;
    
    const int c1 = fmax(m1 <= 0 ? INT_MIN : nums1[m1 - 1], \
                            m2 <= 0 ? INT_MIN : nums2[m2 - 1]);

    if ((nums1Size + nums2Size) % 2 == 1)
        return c1;    
    
    const int c2 = fmin(m1 >= nums1Size ? INT_MAX : nums1[m1], \
                            m2 >= nums2Size ? INT_MAX : nums2[m2]);
            
    return (c1 + c2) * 0.5;
}