class Solution {
    
public:
    int kInversePairs(int n, int K) {
        int f[1001][1001] = {};
        f[0][0] = 1;
        for (int i = 1; i <= n; ++ i) // 1000
        {
            long long s = 0; // maintain a window that is length min(i, j);
            for (int j = 0; j <= K; ++ j) // 1000
            {
                s += f[i - 1][j];
                if (j >= i)
                    s -= f[i - 1][j - i];
                f[i][j] = ((long long)f[i][j] + s) % 1000000007; 
            }
        }
        return f[n][K];
    }
};