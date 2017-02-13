// Source : https://leetcode.com/problems/implement-strstr/
// Author : Jimmy Liu
// Date   : 2017-02-12
// Reference: KMP http://en.wikipedia.org/wiki/Knuth-Morris-Pratt_algorithm
//            In Chinese http://www.cppblog.com/cxiaojia/archive/2011/09/20/kmp.html
//            http://www.cnblogs.com/dolphin0520/archive/2011/08/24/2151846.html
// Idea: 
//   Meaning of the problem: find the specific substring in a string 
//   Restatement of the idea:
//   Suppose H = * haystack = "ABC ABCDAB ABCDABCDABDE", P = * needle = "ABCDABD" , both ending with '\0',
//                             12345678901234567890123                   1234567
//   
//   Initially, H[1~3] match P[1~3]; and at i=4, j=4, mismatch happened. 
//              notice that no repeated A's beteween P[2] and P[3], so nothing in H by [3] can be the new match, so set hay_shift = 4. 
//              and P has to start from 1 as well.
//   Got mismatch on H[4]&P[1], move i=5 to check H[5] and P[1],  ABC ABCDAB ABCDABCDABDE
//                                                                    ABCDABD
//   matched for j=1:6 and mismatch j=7. but this time, notice that there is a pattern in P[1~6], so j only needs to go to 3, 
//              and i does not to move since P[1,2]=AB are matched.
//   ABC ABCDAB ABCDABCDABDE gives mismatch. j need to be reset as 1, and i don't move again
//          ABCDABD
//   ABC ABCDAB ABCDABCDABDE mismatch at j=1, so i++,j remain 1.
//             ABCDABD
//   ABC ABCDAB ABCDABCDABDE got mismatch at j=7, so j move to 3, and i remained
//              ABCDABD
//   ABC ABCDAB ABCDABCDABDE got perfect match.
//                  ABCDABD

//   In summary, the structure of needle determins: 
//                      if current j is mismatched, (1) how to shift j,
//                                                  (2) how to shift i.   Use hay_shift[] and needle_shift[] to record such info.
//   Note, from analysis above, we can see that i are not shift frequently: 
//                                               case   (1)  If mismatch for j=1 (i.e. the first element[0]), we need i++
//                                                      (2)  If mismatch for j>1, then j=needle_shift[j], i remain the same.
//   So we only need needle_shift   <- this is the partial match table T in wiki.

//                 Partial match table for "A  B  C  D  A  B  D":      
//                                         -1  0  0  0  0  1  0  
//                                      (here index starting from 0)
//   Every mismatch happens, set j = needle_shift[j]
//   How to set needle_shift? 
//   needle_shift[0] = -1 , needle_shift[1] = 0 always. Here value -1 just for iterate ealisy purpose.
//   if needle_shift[1~k] are done, then for k+1: 
//                                          case (1) needle_shift[k] = 0, which means there is no previous match before [k],
//                                                   so only have to compare P[k] with P[0];
//                                               (2) needle_shift[k] = some m >0.
//                                                   It means P[ 0 ~ m-1] is matched to haystack ,
//                                                   in other words,  among P[ 0 ~ k-1], P[k-m ~ k-1 ] is the longest suffix that 
//                                                   matches prefix, i.e. P[0:m-1] == P[(k-m):(k-1)],
//                                                   so now compare P[k] to P[m], 
//                                                   (a) if ==, then needle_shift[k+1]=m+1
//                                                   (b) else, compare P[k] with P[0] 

class Solution 
{
public:
    char *strStr(char *haystack, char *needle) 
    {
        if (*needle == '\0') {
            return haystack;
        } else if(*haystack == '\0') {
            return NULL;
        } else {
            //get the length of the array, excluding \0
            int N = 0, n = 0; //length of haystack and needle respectively
            while(needle[n] != '\0') {
                n++;
            }
            while(haystack[N] != '\0'){
                N++;
            }
            
            // Obtain the needle_shift table information
            vector<int> needle_shift(n);
            needle_shift[0] = -1; //first mismatch makes the haystack pointer move one step
            int i, j = 0;
            for (i = 1; i < n; i++) {
                if (needle_shift[i-1] == -1) {
                    needle_shift[i] = 0;
                } else if (needle_shift[i-1] == 0) {
                    needle_shift[i] = (needle[i-1] == needle[0]) ? 1 : 0;
                } else { 
                    //check whether the previous longest suffix can be extended
                    if (needle[i-1] == needle[needle_shift[i - 1]])
                    {
                        needle_shift[i] = needle_shift[i - 1] + 1;
                    } else {
                        needle_shift[i] = (needle[i-1] == needle[0]) ? 1 : 0;
                    }
                }
            }
       
            // find the pattern
            // i is index of haystack, j is index of substring
            i=0;
            j=0;
            while(i < N) { 
                if (haystack[i] == needle[j]) {
                    i++;
                    j++;
                    if (j==n) {
                        // reaches the end
                        return &haystack[i - n];
                    }
                } else {
                    if (j == 0) {
                        i++;     
                    } else {
                        j = needle_shift[j];
                    }
                }
            }
            return NULL;
        }//end of else
    }//end of function
};
