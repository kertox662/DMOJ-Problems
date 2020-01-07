#include <iostream>
#include <set>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    set<int> lengths;
    vector<string> seqs;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = seqs.size() - 1; j >= 0; j--)
        {
            seqs[j] += s[i];
            cout << seqs[j] << endl;
            if (count(seqs[j].begin(), seqs[j].end(), seqs[j][seqs[j].length() - 1]) > 1)
            {
                lengths.insert(seqs[j].length() - 1);
                seqs.erase(seqs.begin() + j);
            }
        }
        seqs.push_back(string(1,s[i]));
    }
    for (int i = 0; i < seqs.size(); i++)
        lengths.insert(seqs[i].length());
    int m;
    auto it = lengths.begin();
    for (int i = 1; i < lengths.size(); i++)
        it++;
    return *it;
}

int main(){
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}