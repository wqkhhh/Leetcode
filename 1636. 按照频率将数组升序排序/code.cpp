class Solution {
public:
    typedef pair<int, int> kvpair;

    struct CmpByValue {
        bool operator()(const kvpair& p1, const kvpair& p2) {
            return p1.second < p2.second;
        }
    };

    struct CmpByKey {
        bool operator()(const kvpair& p1, const kvpair& p2) {
            return p1.first > p2.first;
        }
    };
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> nums_map;
        for(int i = 0; i < nums.size(); i++){
            if(nums_map.count(nums[i]) == 0){
                nums_map[nums[i]] = 1;
            }else{
                nums_map[nums[i]] ++;
            }
        }
        vector<kvpair> nums_vector(nums_map.begin(), nums_map.end());
        sort(nums_vector.begin(), nums_vector.end(), CmpByKey());
        stable_sort(nums_vector.begin(), nums_vector.end(), CmpByValue());
        vector<int> res;
        for(int i = 0; i < nums_vector.size(); i ++){
            res.insert(res.end(), nums_vector[i].second, nums_vector[i].first);
        }
        return res;
    }
};
