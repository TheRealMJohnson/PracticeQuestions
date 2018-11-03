//
//  main.cpp
//  BigIntMultiplier
//
//  Created by Matthew Johnson on 2018-11-02.
//  Copyright © 2018 Matthew Johnson. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

struct Node {
    Node * next = nullptr;
    int val = 0;
};

int clean(Node * curr) {
    int toAdd = 0;
    if(curr) {
        toAdd = clean(curr->next);
        toAdd += curr->val;
        curr->val = toAdd % 10;
        return toAdd/10;
    }
    else {
        return 0;
    }
}

Node * cleanRoot(Node * root) {
    int result = clean(root);
    
    while(result != 0) {
        Node * parent = new Node;
        parent->val = result%10;
        result /= 10;
        parent->next = root;
        root = parent;
    }
    
    return root;
}

void printList(Node * root) {
    std::cout << "[";
    while (root) {
        std::cout << root->val << ", ";
        root = root->next;
    }
    std::cout << "]\n";
}

Node * getMultiplication(Node * rootA, Node * rootB) {
    Node * currA;
    Node * currB;
    Node * currOut;
    Node * startOut;
    Node * rootOut  = new Node;
    
    currA = rootA;
    startOut = rootOut;
    
    do {
        currB = rootB;
        currOut = startOut;
        do {
            currOut->val += currA->val * currB->val;
            currB = currB->next;
            if(!(currOut->next) && currB) {
                currOut->next = new Node;
            }
            currOut = currOut->next;
        } while (currB);
        
        startOut = startOut->next;
        currA = currA->next;
        std::cout << "multiplied one column with next. Result:\n";
        printList(rootOut);
    } while (currA);
    //rootOut = cleanRoot(rootOut);
    return rootOut;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arrSize = 5;
    Node allNodes[arrSize];
    for (int i = 0; i < arrSize; i++){
        allNodes[i].val = i+1;
        std::cout << allNodes[i].val <<", ";
    }
    std::cout << "\n-----\n";
    
    allNodes[0].next = &allNodes[1];
    allNodes[1].next = &allNodes[2];
    allNodes[2].next = nullptr;
    allNodes[3].next = &allNodes[4];
    allNodes[4].next = nullptr;
    
    std::cout << "Hello, World!\n";
    
    printList(&allNodes[0]);
    printList(&allNodes[3]);
    
    Node * result = getMultiplication(&allNodes[0], &allNodes[3]);
    printList(result);
    result = cleanRoot(result);
    printList(result);
    
    return 0;
}
