class Solution {
    public int strStr(String haystack, String needle) {
         if (needle.isEmpty()) {
            return 0;
        }
        return haystack.indexOf(needle);
    }
}
