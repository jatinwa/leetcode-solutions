class Solution {
public:
    
    bool is_palindrome(string s) {
        int low = 0;
        int high = s.size() - 1;
        while(low<=high) {
            if(s[low] != s[high]) return false;
            low++;
            high--;
        }
        return true;
    }
        
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> ans;
        unordered_map<string,int> m;
        for(int i=0;i<n;i++) {
            string temp = words[i];
            reverse(temp.begin(),temp.end());
            m[temp] = i;
        }
        
        if(m.count("")){
            for(int i=0;i<n;i++) {
             if(!words[i].empty() && is_palindrome(words[i])) {
                 ans.push_back({i,m[""]});
             }
        }
        }
        
        for(int i=0;i<n;i++) {
            string left, right;
            for(int j=0;j<words[i].size();j++) {
                left.push_back(words[i][j]);
                right = words[i].substr(j+1);
                
                if(m.count(left) && i!=m[left] && is_palindrome(right)){
                    ans.push_back({i,m[left]});
                }
                if(m.count(right) && i!=m[right] && is_palindrome(left)) {
                    ans.push_back({m[right],i});
                }
            }
        }
        return ans;
    }
};