
import java.util.HashSet;
import java.util.Set;

class sliding_window {

    static int lengthOfLongestSubstring(String s) {
        Set<Character> list = new HashSet();
        int maxLen = 0, left = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);

            while (list.contains(c)) {
                list.remove(c);
                left++;
            }

            list.add(c);
            maxLen = Math.max(maxLen, right - left + 1);
        }

        return maxLen;
    }

    public static void main(String[] args) {
        String s = "abcabcbb";
        int len = lengthOfLongestSubstring(s);
        System.out.println(len);
    }
}
