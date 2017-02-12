// Source : https://leetcode.com/problems/container-with-most-water/
// Author : Jimmy Liu
// Date   : 2017-02-11
// Reference: https://discuss.leetcode.com/topic/16754/simple-and-fast-c-c-with-explanation
//            http://blog.unieagle.net/2012/09/16/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Acontainer-with-most-water/
// idea: define left_bound & right_bound of the container. If left<right, left++, o.w. right--.
//       If left<right, then for j<=right, current area=max(i=left, i<=j<=right). 
//       Moving j to the left will not increase the area with left bound fixed. 
//       An example
//             |
//             |         |  |
//    |     |  |         |  |
//    |  |  |  |  .....  |  |
//    proof: We are looking for max_area(i,j) (abbr. as max(i,j) ), area is the water volumn function, i & j are two bound parameters.
//           max(i in 1:n, j in 1:n) can be mutually partitioned.
//           For the example above:
//           step 1: i=1, j=n. Notice that left<right, so area(1,n)= max over j>=1 of area(const i=1, j), 
//                   i.e. max(i=1,j>=1).
//           step 2: i++, now i=2, j=n. We still have left<right, so area(2,n) = max over j>=2 of area(const i=2,j), 
//                   i.e. max(i=2,j>=2).
//           step 3: i++, i=3,j=n. max over i=3, j>=3,
//                   i.e. max(i=3,j>=3)
//           step 4: i++, i=4,j=n. Left>right, max over i=4, j>=4, 
//                   the current value is the max that right bound fixed at n, and left bound>=4.
//                   i.e. max(i>=4,j=n)
//                   No need to consider i<4&j=n since they are included in step 1~3.
//           continue until i=j.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if (n <= 1) return 0;
        int left = 0, right = n - 1, maxV = 0;
        while(left < right) {
            maxV = max(maxV, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right]) {
                left++;
            } else if (height[left] > height[right]) {
                right--;
            } else {
                left++; 
                right--;
            }
        }
        return maxV;
    }
};
