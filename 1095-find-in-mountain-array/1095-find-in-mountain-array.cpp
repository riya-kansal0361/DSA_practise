/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
         int index_peak = findPeak(target, mountainArr);

        // search the target on the left part (strict increasing array)
        int index_left = findLeft(target, mountainArr, 0, index_peak);
        if (index_left != -1) return index_left;

        // search the target on the right part (strict decreasing array)
        int index_right= findRight(target, mountainArr, index_peak, mountainArr.length() - 1);
        if (index_right != -1) return index_right;

        // the target does not exist
        return -1;
    }
private:
    int findPeak(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            // if (m == 0) return 0;
            // if (m == (n - 1)) return (n - 1);
            int m1 = mountainArr.get(m - 1);
            int m2 = mountainArr.get(m);
            int m3 = mountainArr.get(m + 1);
            if ((m1 < m2) && (m2 < m3)) l = m;
            else if ((m1 > m2) && (m2 > m3)) r = m;
            else return m;
        }
        return l;
    }
    int findLeft(int target, MountainArray& mountainArr, int l, int r) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            int value = mountainArr.get(m);
            if (value == target) return m;
            else if (value < target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
    int findRight(int target, MountainArray& mountainArr, int l, int r) {
        while (l <= r) {
            int m = l + (r - l) / 2;
            int value = mountainArr.get(m);
            if (value == target) return m;
            else if (value > target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};