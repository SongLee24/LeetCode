class Solution {
public:
    int findKth(int A[], int m, int B[], int n, int k)  
    {  
    	if (m > n)    // 保证数组A的大小总是小于数组B的大小
    		return findKth(B, n, A, m, k);  
    	if (m == 0)   // 如果A为空
    		return B[k - 1];  
    	if (k == 1)   // 如果k为1
    		return min(A[0], B[0]);  
    	
    	// 每次把k分两半
    	int pa = min(k/2, m);  /*A的元素可能小于k/2个*/
    	int pb = k - pa;
    
    	if (A[pa-1] < B[pb-1])  
    		return findKth(A+pa, m-pa, B, n, k-pa);  
    
    	else if (A[pa-1] > B[pb-1])  
    		return findKth(A, m, B+pb, n-pb, k-pb);  
    	else  
    		return A[pa-1];  
    } 
    
     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int *A = nums1.data();
    	int *B = nums2.data();
    	int m = nums1.size();
    	int n = nums2.size();
    
    	int total = m+n;
    	if (total%2 == 1)  // 奇数个
    		return findKth(A, m, B, n, total/2+1);  
    	else  
    		return (findKth(A, m, B, n, total/2) 
    				+ findKth(A, m, B, n, total/2+1)) / 2.0; 
     }
};