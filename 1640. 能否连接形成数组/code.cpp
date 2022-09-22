class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int pieces_len = 0;
        for (int i = 0; i < pieces.size(); i ++) {
            pieces_len += pieces[i].size();
        }
        if (pieces_len != arr.size()) return false;
        for (int i = 0; i < pieces.size(); i ++) {
            if (pieces[i].size() > 1) {
                int pos = find(arr.begin(), arr.end(), pieces[i][0]) - arr.begin();
                for (int j = 1; j < pieces[i].size(); j ++) {
                    if (pos+1 != find(arr.begin(), arr.end(), pieces[i][j]) - arr.begin()) {
                        return false;
                    }
                    pos = find(arr.begin(), arr.end(), pieces[i][j]) - arr.begin();
                }
            }else {
                if (find(arr.begin(), arr.end(), pieces[i][0]) == arr.end()) return false;
            }
        }
        return true;
    }
};
