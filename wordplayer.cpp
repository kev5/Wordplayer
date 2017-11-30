// Copyright 2017 Keval Khara kevalk@bu.edu

#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <unordered_map>
#define xCy(x, y) std::tgamma(x+1)/(std::tgamma(y+1)*std::tgamma(x-y+1))
#define strsort(a) std::sort(a.begin(), a.end())
#define ESC {std::cout << "." << std::endl; \
             continue;}
std::set<std::string> wordset;
std::unordered_map<int, std::unordered_map<std::string, \
        std::set<std::string> > > dictionary;

int insert(std::string s) {
    for (auto const& i : dictionary[s.length()][s])
        wordset.insert(i);
}

int check(std::string large, std::string small) {
    for (auto i : small) {
        int pos = large.find_first_of(i);
        if (pos != std::string::npos)
            large.erase(pos, 1);
        else
            return 0;
    }
    return 1;
}

int search(std::string s, int l) {
    for (auto i : dictionary[l]) {
          if (check(s, i.first)) {
            for (auto j : i.second)
                wordset.insert(j);
          }
    }
}

int combine(std::string s, int m, int n, std::string t) {
    if (n == 0) {
        insert(t);
        return 0;
    }
    for (int i = m; i <= s.length()-n; i++) {
        std::string q = t;
        q.push_back(s[i]);
        combine(s, i+1, n-1, q);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    std::ifstream infile(argv[1]);
    std::string word;
    while (infile >> word) {
        std::string sortedword = word;
        strsort(sortedword);
        dictionary[word.length()][sortedword].insert(word);
    }
    std::string searchstr;
    int length;
    while (std::cin >> searchstr >> length) {
        if (!length)
            return 0;
        wordset.clear();
        strsort(searchstr);
        if (searchstr.length() < length)
            ESC;
        if (xCy(searchstr.length(), length) < \
                dictionary[searchstr.length()].size())
            combine(searchstr, 0, length, "");
        else
            search(searchstr, length);
        for (auto &i : wordset)
            std::cout << i << std::endl;
        ESC;
    }
}
