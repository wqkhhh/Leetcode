class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n = s1.size();
        queue<pair<string, int>> qu;
        unordered_set<string> st;
        qu.emplace(s1, 0);
        st.emplace(s1);

        for (int step = 0; ; step ++){
            int sz = qu.size();
            for (int i = 0; i < sz; i ++) {
                auto [cur, pos] = qu.front();
                qu.pop();
                if (cur == s2) return step;
                while(pos < n && cur[pos] == s2[pos]){
                    pos  ++;
                }
                for (int j = pos+1; j < n; j ++) {
                    if(cur[j] != s2[j] && cur[j] == s2[pos]){
                        swap(cur[j], cur[pos]);
                        if(!st.count(cur)){
                            st.emplace(cur);
                            qu.emplace(cur, pos+1);
                        }
                        swap(cur[j], cur[pos]);
                    }
                }
            }
        }
    }
};
