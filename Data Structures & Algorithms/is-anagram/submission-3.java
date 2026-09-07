class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        HashMap<Character, Integer> sFrequency = new HashMap<>();
        HashMap<Character, Integer> tFrequency = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            sFrequency.put(s.charAt(i), sFrequency.getOrDefault(s.charAt(i), 0) + 1);
            tFrequency.put(t.charAt(i), tFrequency.getOrDefault(t.charAt(i), 0) + 1);
        }

        return sFrequency.equals(tFrequency);
    }

}
