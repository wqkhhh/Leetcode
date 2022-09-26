class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        // 从前往后的累加和
        int sum = 0;

        int d[n][n+1];
        memset(d, 0, sizeof(d));
        for (int i = n-1; i >= 0; --i)
        {
            sum += piles[i];
            for (int j = 1; j <= n; ++j)
            {
                // 超过最大的堆数
                if (i+2*j >= n)
                {
                    d[i][j] = sum;
                }
                else
                {
                    for (int x = 1; x <= 2*j; ++x)
                    {
                        d[i][j] = max(d[i][j], sum - d[i+x][max(j, x)]);
                    }
                }
            }
        }
        return d[0][1];
    }
};
