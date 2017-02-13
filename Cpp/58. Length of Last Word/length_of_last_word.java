public class Solution {
    public int lengthOfLastWord(String s) {
        int n = s.length();
        if (n <= 0) 
            return 0;
        
        int lastDigit = n - 1;
        while(lastDigit >= 0 && s.charAt(lastDigit)==' ') {
            lastDigit--;
        }
        if (lastDigit == -1) 
            return 0;
        int result = 0;
        for (int i = lastDigit; i >= 0; i--) {
            if (s.charAt(i) != ' ') {
                result++;
            } else {
                return result;
            }
        }
        return result;
    }
}
