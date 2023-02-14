#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode;

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
};

bool addValue(TreeNode *&node, int new_value){
    if(node == nullptr) {
        node = new TreeNode{new_value, nullptr, nullptr};
        return true;
    }else{
        if(node->value == new_value)
            return false;
        else if(node->value < new_value)
            addValue(node->right, new_value);
        else
            addValue(node->left, new_value);
    }
}

void printTree(TreeNode *node, int depth) {
    if(node == nullptr)
        return;
    printTree(node->left, depth + 1);
    string str(depth, '.');
    cout << str << node->value << "\n";
    printTree(node->right, depth + 1);
}

bool searchTree(TreeNode *node, int target){
    if(node == nullptr)
        return false;
    if(node->value == target){
        return true;
    }else if(node->value < target){
        searchTree(node->right, target);
    }else{
        searchTree(node->left, target);
    }
}

int main() {
    TreeNode *root = nullptr;
    ifstream fin("input.txt");
    string line;
    while(getline(fin, line)){
        istringstream iss(line);
        vector<string> line_split;
        string word;
        while(getline(iss, word, ' ')){
            line_split.push_back(word);
        }
        if(line_split.front() == "ADD"){
            if(addValue(root, stoi(line_split.back())))
                cout << "DONE\n";
            else
                cout << "ALREADY\n";
        }else if(line_split.front() == "SEARCH"){
            if(searchTree(root, stoi(line_split.back())))
                cout << "YES\n";
            else
                cout << "NO\n";
        }else if(line_split.front() == "PRINTTREE"){
            printTree(root, 0);
        }
    }
    fin.close();

    return 0;
}