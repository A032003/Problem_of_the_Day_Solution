class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        map<int, int> mp;

    
        for(auto i : arr1) {
            mp[i]++;
        }

 
        for(auto it : arr2) {
            if(mp.count(it)) {
                int temp = mp[it];
                while(temp > 0) {
                    ans.push_back(it);
                    temp--;
                }
                mp.erase(it); 
            }
        }

        
        for(auto i : mp) {
            int temp = i.second;
            while(temp > 0) {
                ans.push_back(i.first);
                temp--;
            }
        }
        return ans;
    }
};


//Approach 2

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        unordered_map<int, int> mp;

        for (int i = 0; i < arr2.size(); i++) {
            mp[arr2[i]] = i;
        }

        for (int& num : arr1) {
            if (!mp.count(num))
                mp[num] = 1e9;
        }

        auto lambda = [&](int& num1, int& num2) {
            if (mp[num1] == mp[num2]) {
                return num1 < num2;
            }
            return mp[num1] < mp[num2];
        };

        sort(arr1.begin(), arr1.end(), lambda);
        return arr1;
    }
};
