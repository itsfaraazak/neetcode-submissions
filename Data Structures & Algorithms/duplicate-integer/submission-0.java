class Solution {
    public boolean hasDuplicate(int[] nums) {
        HashMap<Integer,Integer> frequency = new HashMap<>();

        for (int num : nums) {
            if (frequency.get(num) == null) {
                frequency.put(num, 1);
            } else {
                return true;
            }
        }
        return false;
    }
}