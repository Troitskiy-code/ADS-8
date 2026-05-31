// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "File error!" << std::endl;
        return;
    }

    std::string word;
    int ch;
    while ((ch = file.get()) != EOF) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            word += static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
        } else {
            if (!word.empty()) {
                tree.insert(word);
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        tree.insert(word);
    }
    file.close();
}

void printFreq(BST<std::string>& tree) {
    auto freq = tree.getFrequencyList();
    std::sort(freq.begin(), freq.end(),
        [](const auto& a, const auto& b) { return b.second < a.second; });

    for (const auto& p : freq) {
        std::cout << p.first << " : " << p.second << std::endl;
    }

    std::ofstream out("result/freq.txt");
    if (out) {
        for (const auto& p : freq) {
            out << p.first << " : " << p.second << "\n";
        }
        out.close();
    } else {
        std::cerr << "Cannot write result/freq.txt" << std::endl;
    }
}
