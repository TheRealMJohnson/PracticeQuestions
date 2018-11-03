//
//  main.cpp
//  Template
//
//  Created by Matthew Johnson on 2018-10-27.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

struct Node {
    Node * lChild = nullptr;
    Node * rChild = nullptr;
    int val = 0;
};

int getTreeDepth(Node * root) {
    if(!root) return 0;
    return std::max(getTreeDepth(root->lChild), getTreeDepth(root->rChild))+1;
}

void printInOrder(Node * root) {
    if(!root) return;
    printInOrder(root->lChild);
    std::cout << root->val << ", ";
    printInOrder(root->rChild);
}

void printPreOrder(Node * root) {
    if(!root) return;
    std::cout << root->val << ", ";
    printInOrder(root->lChild);
    printInOrder(root->rChild);
}

void printPostOrder(Node * root) {
    if(!root) return;
    printInOrder(root->lChild);
    printInOrder(root->rChild);
    std::cout << root->val << ", ";
}

void printBreadthFirst(Node root) {
    std::vector<Node> queue;
    queue.push_back(root);
    
    while(!queue.empty()) {
        if (queue.begin()->lChild) {
            queue.push_back(*(queue.begin()->lChild));
        }
        if (queue.begin()->rChild) {
            queue.push_back(*(queue.begin()->rChild));
        }
        std::cout << queue.begin()->val << ", ";
        queue.erase(queue.begin());
    }
}

int main(int argc, const char * argv[]) {
    int arrSize = 10;
    Node allNodes[arrSize];
    for (int i = 0; i < arrSize; i++){
        allNodes[i].val = i;
        std::cout << allNodes[i].val <<", ";
    }
    std::cout << "\n-----\n";
    
    allNodes[0].lChild = &allNodes[1];
    allNodes[0].rChild = &allNodes[2];
    allNodes[1].lChild = &allNodes[3];
    allNodes[1].rChild = &allNodes[4];
    allNodes[2].rChild = &allNodes[5];
    allNodes[5].rChild = &allNodes[6];
    std::cout << "Hello, World!\n";
    
    std::cout << "Depth of the tree is [" << getTreeDepth(&allNodes[0]) << "]";
    
    return 0;
}
