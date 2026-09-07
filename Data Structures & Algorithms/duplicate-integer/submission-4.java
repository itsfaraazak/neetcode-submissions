class Solution {
    public boolean hasDuplicate(int[] nums) {
        HashMap<Integer, Integer> counts = new HashMap<>();
        for (int num : nums) {
            if (counts.get(num) != null) {
                return true;
            }
            counts.put(num, 1);
        }
        return false;
    }
}