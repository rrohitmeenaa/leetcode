class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col == 2 || col == 3 || col == 4 || col == 5)
                mp[row] |= 1;

            if (col == 4 || col == 5 || col == 6 || col == 7)
                mp[row] |= 2;

            if (col == 6 || col == 7 || col == 8 || col == 9)
                mp[row] |= 4;
        }

        int ans = (n - mp.size()) * 2;

        for (auto &it : mp) {
            int mask = it.second;

            if (mask == 0)
                ans += 2;
            else if ((mask & 1) == 0 || (mask & 4) == 0)
                ans += 1;
            else if ((mask & 2) == 0)
                ans += 1;
        }

        return ans;
    }
};