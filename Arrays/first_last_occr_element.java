
class first_last_occr_element {

    public static int[] searchRange(int[] nums, int target) {
        if (nums.length == 0) {
            return new int[]{-1, -1};
        }
        int first = getFirstElement(nums, target);
        int last = getLastElement(nums, target);

        return new int[]{first, last};
    }

    public static int getFirstElement(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                ans = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }

        return ans;
    }

    public static int getLastElement(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                ans = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        int nums[] = {0, 0, 1, 3, 6, 9, 9, 8};
        int t = 9;

        int res[] = searchRange(nums, t);
        for (int i : res) {
            System.out.println(i + " ");
        }
    }
}
