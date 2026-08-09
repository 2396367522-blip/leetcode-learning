#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs){
    unordered_map<string, vector<string>> mp;

    for(string& s: strs){
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }
    
    vector<vector<string>> result;
    for(auto it = mp.begin(); it != mp.end(); ++it){
        result.push_back(it->second);
    }

    return result;
}

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groupedAnagrams = groupAnagrams(strs);

    for(const auto& group: groupedAnagrams){
        for(const auto& word: group){
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
