#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

enum NodeType{
    Root,
    Left,
    Right
};

struct TreeNode;

struct TreeNode{
    TreeNode(NodeType type, TreeNode *parent = nullptr) 
    : left(nullptr), right(nullptr), parent(parent), type(type) {/*cout << "constructed " << type << "\n"*/;}
    ~TreeNode();
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    NodeType type;
};

TreeNode::~TreeNode(){
    if(left != nullptr)
        delete left;
    if(right != nullptr)
        delete right;
    // cout << "deleted " << type << "\n";
}

TreeNode *makeTree(string serialized){
    TreeNode *root = new TreeNode(Root);
    TreeNode *current_node = root;
    for(auto ch : serialized){
        if(ch == 'D'){
            TreeNode *new_node = new TreeNode(Left, current_node);
            current_node->left = new_node;
            current_node = new_node;
        }else{
            while(current_node->type == Right)
                current_node = current_node->parent;
            current_node = current_node->parent;
            TreeNode *new_node = new TreeNode(Right, current_node);
            current_node->right = new_node;
            current_node = new_node;
        }
    }
    return root;
}

void traverse(TreeNode *root, string &prefix, vector<string> &res){
    if(root->left == nullptr && root->right == nullptr){
        res.push_back(prefix);
        return;
    }
    prefix.append("0");
    traverse(root->left, prefix, res);
    prefix.pop_back();
    prefix.append("1");
    traverse(root->right, prefix, res);
    prefix.pop_back();
}

int main() {
    ifstream fin("input.txt");
    int n = 0;
    fin >> n;
    vector<string> lines(n);
    for(auto &line : lines)
        fin >> line;
    fin.close();

    for(const auto &line : lines){
        auto root = makeTree(line);
        string prefix;
        vector<string> res;
        traverse(root, prefix, res);
        cout << res.size() << "\n";
        for(auto str : res)
            cout << str << "\n";
        delete root;
    }
}