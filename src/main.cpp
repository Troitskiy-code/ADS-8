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
    std::cout << "'war' found: " << (tree.search("war") ? "yes" : "no") << std::endl;
    std::cout << "'peace' found: " << (tree.search("peace") ? "yes" : "no") << std::endl;
    std::cout << "Frequencies:\n";
    printFreq(tree);
    return 0;
}
