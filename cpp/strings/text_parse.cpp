//given a text string and q words.
//For all q words, need to find out all words from text string which are matching with given word.

#include <unordered_map>

vector<vector<int>> find_words(string text, vector<string> words) {
    vector<vector<int>> ans;
    unordered_map<string, vector<int>> map;

    int start = 0, i = 0;
    for (i = 0; i < text.length(); i++) {
        if (text[i] == ' ') {
            map[text.substr(start, i-start)].push_back(start);
            start = i+1;
        }
    }
    map[text.substr(start, i-start)].push_back(start);

    for (auto word : words) {
        if (map.find(word) != map.end())
            ans.push_back(map[word]);
        else
            ans.push_back({-1});
    }

    return ans;
}

