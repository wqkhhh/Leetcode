// class Solution {
// public:
//     int getKthMagicNumber(int k) {
//         vector<int> dp(k+1,1);
//         int p3 = 1;
//         int p5 = 1;
//         int p7 = 1;
//         for(int i = 2;i <= k;i ++) {
//             int cur = min(dp[p3]*3, min(dp[p5]*5, dp[p7]*7));
//             dp[i] = cur;
//             if(dp[p3]*3 == cur) p3 ++;
//             if(dp[p5]*5 == cur) p5 ++;
//             if(dp[p7]*7 == cur) p7 ++;
//         }
//         return dp[k];
//     }
// };

class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> factors = {3, 5, 7};
        unordered_set<long> seen;
        priority_queue<long, vector<long>, greater<long>> heap;
        seen.insert(1L);
        heap.push(1L);
        int magic = 0;
        for(int i = 0;i < k;i ++) {
            long cur = heap.top();
            heap.pop();
            magic = (int)cur;
            for(int factor : factors) {
                long next = factor * cur;
                if(!seen.count(next)) {
                    seen.insert(next);
                    heap.push(next);
                }
            }
        }
        return magic;
    }
};
