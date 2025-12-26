//leetcode692 Top K Frequent Words
// Given an array of strings words and an integer k, return the k most frequent strings.

// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

// Example 1:
// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.

// Example 2:
// Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
// Output: ["the","is","sunny","day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.

#include<map>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:
    class compare
    {
    public:
        bool operator()(const pair<string, int>& x, const pair<string, int>& y)
        {
            return x.second == y.second? x.first < y.first : x.second > y.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> nodemap;
        vector<string>::iterator it = words.begin();
        while(it != words.end())
        {
            nodemap[*it]++;
            ++it;
        }
        vector<pair<string, int>> v(nodemap.begin(), nodemap.end());
        sort(v.begin(), v.end(), compare());  //stable_sort
        vector<string> ret;
        int i = 0;
        while(i < k)
        {
            ret.push_back(v[i].first);
            i++;
        }
        return ret;

    }
};

// class Solution {
// public:
//     class compare
//     {
//     public:
//         bool operator()(const pair<string, int>& x, const pair<string, int>& y)
//         {
//             return x.second == y.second? x.first > y.first:x.second < y.second;
//         }
//     };

//     vector<string> topKFrequent(vector<string>& words, int k) {
//         map<string, int> nodemap;
//         vector<string>::iterator it = words.begin();
//         while(it != words.end())
//         {
//             nodemap[*it]++;
//             ++it;
//         }
//         priority_queue<pair<string, int>, vector<pair<string, int>>,compare> myheap(nodemap.begin(), nodemap.end());

//         vector<string> ret;
//         while(k)
//         {
//             ret.push_back(myheap.top().first);
//             myheap.pop();
//             --k;
//         }
//         return ret;
//     }
// };

int main()
{
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    vector<string> ret = Solution().topKFrequent(words, 2);
}