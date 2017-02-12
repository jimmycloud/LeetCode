// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Jimmy Liu
// Date   : 2017-02-11
// Reference: 
// Idea: 

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       if (nums1.size()>nums2.size()) 
       {
           return assist(nums2, nums1);
       } else {
           return assist(nums1, nums2);
       }
    }
    double assist(vector<int>& x, vector<int>& y) {
        int m = x.size(), n = y.size();
        if (m == 0) return (n%2 == 0) ? (double(y[n/2-1] + y[n/2])/2.0) : (y[n/2]);
        int counter = 0, i = 0, j = 0, midLow, midHigh, current;
        while(counter-1 <= (m+n)/2 && i < m && j < n) {
            if (x[i] < y[j]) {
                counter++;
                i++;
                if (counter-1 == (m+n)/2-1) midLow = x[i-1];
                if (counter-1 == (m+n)/2) midHigh = x[i-1];
            } else {
                counter++;
                j++;
                if (counter-1 == (m+n)/2-1) midLow = y[j-1];
                if (counter-1 == (m+n)/2) midHigh = y[j-1];
            }
        }
        
        //if this is executed, then all x have been compared and not found yet.
        while (counter-1 <= (m+n)/2 && i >= m && j < n) {         
            counter++;
            j++;
            if (counter-1 == (m+n)/2-1) midLow = y[j-1];
            if (counter-1 == (m+n)/2) midHigh = y[j-1];
        }
        //if this is executed, then all y have been compared and not found yet.
        while (counter-1 <= (m+n)/2 && j >= n && i < m) {
            counter++;
            i++;
            if (counter-1 == (m+n)/2-1) midLow = x[i-1];
            if (counter-1 == (m+n)/2) midHigh = x[i-1];
        }
        //cout<<"mid low is "<<midLow<<", mid high is "<<midHigh<<endl;
        return ((m+n)%2 == 0) ? (double(midLow + midHigh) / 2) : (midHigh);
    }
};
