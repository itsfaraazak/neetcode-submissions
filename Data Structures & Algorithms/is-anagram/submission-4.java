class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        int[] characterDifferenceCount = new int[26];
        for (int i = 0; i < s.length(); i++) {
            characterDifferenceCount[s.charAt(i) - 'a']++;
            characterDifferenceCount[t.charAt(i) - 'a']--;
        }

        for (int difference : characterDifferenceCount) {
            if (difference != 0) {
                return false;
            }  
        }
        return true;
    }
}
