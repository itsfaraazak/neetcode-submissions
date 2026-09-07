class Solution {
    public boolean isAnagram(String s, String t) {
        Map<String, Integer> sCharacterFrequency = getCharacterFrequency(s);
        Map<String, Integer> tCharacterFrequency = getCharacterFrequency(t);
        if (sCharacterFrequency.equals(tCharacterFrequency)) {
            return true;
        }
        return false;
    }

    private Map getCharacterFrequency(String string) {
        HashMap<String, Integer> characterFrequency = new HashMap<>();

        for (int i = 0; i < string.length(); i++) {
            String currentCharacter = String.valueOf(string.charAt(i));
            if (characterFrequency.get(currentCharacter) == null) {
                characterFrequency.put(currentCharacter, 1);
            } else {
                characterFrequency.put(currentCharacter, characterFrequency.get(currentCharacter) + 1);
            }
        }
        return characterFrequency;
    }
}
