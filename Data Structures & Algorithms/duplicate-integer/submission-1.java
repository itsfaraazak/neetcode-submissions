class Solution {
    public boolean hasDuplicate(int[] nums) {
        HashSet numSet = new HashSet<>();

        for (int num : nums) {
            numSet.add(num);
        }

        if (numSet.size() != nums.length) {
            return true;
        }
        return false;
    }
}