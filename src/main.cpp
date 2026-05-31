// Copyright 2021 NNTU-CS
#include <iostream>
#include <string>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
    BST<std::string> tree;
    makeTree(tree, "src/war_peace.txt");

    std::cout << "Tree depth: " << tree.depth() << std::endl;
    int warFreq = tree.search("war");
    int peaceFreq = tree.search("peace");
    std::cout << "'war' frequency: " << warFreq << std::endl;
    std::cout << "'peace' frequency: " << peaceFreq << std::endl;
    std::cout << "All frequencies:\n";
    printFreq(tree);
    return 0;
}
