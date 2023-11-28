#include <vector>
#include <iostream>
#include <queue>
using namespace std;

template<typename generic>
void anySwap(generic& a, generic& b);

template<typename generic>
generic anyMax(generic a, generic b);

//used for the print function
struct trueInt {
    int val;
    bool exists;
    //constructor
    trueInt(int v, bool e) : val(v), exists(e) {}

};

//this is the structure for an individual tree node
//is it from leetcode? ...maybe, but it also has built in height, dupe counter, and return number of children function
struct TreeNode {
    //main definition
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int n) : val(n), left(nullptr), right(nullptr), dupes(1) {}
    TreeNode(int n, TreeNode* lptr, TreeNode* rptr) : val(n), left(lptr), right(rptr), dupes(1) {}
    //height:
    int height;
    int dupes;
    //give number of children
    int numberOfChildren(TreeNode* root) {
        return((root->left ? 1 : 0) + (root->right ? 1 : 0));
    }

};

//this is used for the print function
class numStruct {
    public:
    vector<trueInt> treeStorage;
    string name;

    numStruct(string n) : name(n) {}

    //adds node value to storage
    void addNodeVal(int v, bool e) {
        treeStorage.push_back(trueInt(v, e));
    }

    void push_back_vals(TreeNode* root) { //THIS NEEDS TO BE BFS
        //if root is null entire tree is empty, set all to empty
        if(!root) { 
            for(int i = 0; i < 15; i++) { addNodeVal(0, false); }
            return;
        }
        //bfs queue and adding first in queue (root if root != nullptr)
        queue<TreeNode*> bfs;
        bfs.push(root);
        //maxes out at 15
        for (int i = 0; i < 15; i++) {
            //set temp node, if the queue is
            TreeNode* temp = nullptr;
            //if queue not empty, set temp to first in line, remove from queue; otherwise temp is null
            if (!bfs.empty()) { temp = bfs.front(); bfs.pop(); }
            //if exists, add itself to the treeStorage vector, in addition, add children to queue
            if(temp) { addNodeVal(temp->val, true); bfs.push(temp->left); bfs.push(temp->right); }
            //otherwise add null node and 2 placeholder children
            else { addNodeVal(0, false); bfs.push(nullptr); bfs.push(nullptr); }
        }
        //fill out remaining null children with null nodes
        while(treeStorage.size() < 15) { addNodeVal(0, false); }
    }

    void printTree(TreeNode* root) { //inefficient but its for bfs print readability... don't ask :(
        //layer 1
        push_back_vals(root);
        string one = treeStorage[0].exists ? "\x1b[92m[" + to_string(treeStorage[0].val) + "]" : "\x1b[31m[ ]\33[0m";
            string oneLeft = treeStorage[1].exists ? "\x1b[92m________________________" : "\x1b[31m________________________";
            string oneRight = treeStorage[2].exists ? "\x1b[92m________________________\33[0m" : "\x1b[31m________________________\33[0m";
            one = oneLeft + one + oneRight;
        //layer 2
        string two = treeStorage[1].exists ? "\x1b[92m[" + to_string(treeStorage[1].val) + "]\33[0m" : "\x1b[31m[ ]\33[0m";
            string twoLeft = treeStorage[3].exists ? "\x1b[92m__________" : "\x1b[31m__________";
            string twoRight = treeStorage[4].exists ? "\x1b[92m__________\33[0m" : "\x1b[31m__________\33[0m";
            two = twoLeft + two + twoRight;
        string three = treeStorage[2].exists ? "\x1b[92m[" + to_string(treeStorage[2].val) + "]\33[0m" : "\x1b[31m[ ]\33[0m";
            string threeLeft = treeStorage[5].exists ? "\x1b[92m__________" : "\x1b[31m__________";
            string threeRight = treeStorage[6].exists ? "\x1b[92m__________\33[0m" : "\x1b[31m__________\33[0m";
            three = threeLeft + three + threeRight;
        //layer 3
        string four = treeStorage[3].exists ? "\x1b[92m[" + to_string(treeStorage[3].val) + "]\33[0m" : "\x1b[31m[ ]\33[0m";
            string fourLeft = treeStorage[7].exists ? "\x1b[92m_____" : "\x1b[31m_____";
            string fourRight = treeStorage[8].exists ? "\x1b[92m_____\33[0m" : "\x1b[31m_____\33[0m";
            four = fourLeft + four + fourRight;
        string five = treeStorage[4].exists ? "\x1b[92m[" + to_string(treeStorage[4].val) + "]\33[0m" : "\x1b[31m[ ]\33[0m";
            string fiveLeft = treeStorage[9].exists ? "\x1b[92m_____" : "\x1b[31m_____";
            string fiveRight = treeStorage[10].exists ? "\x1b[92m_____\33[0m" : "\x1b[31m_____\33[0m";
            five = fiveLeft + five + fiveRight;
        string six = treeStorage[5].exists ? "\x1b[92m[" + to_string(treeStorage[5].val) + "]\33[0m" : "\x1b[31m[ ]\33[0m";
            string sixLeft = treeStorage[11].exists ? "\x1b[92m_____" : "\x1b[31m_____";
            string sixRight = treeStorage[12].exists ? "\x1b[92m_____\33[0m" : "\x1b[31m_____\33[0m";
            six = sixLeft + six + sixRight;
        string seven = treeStorage[6].exists ? "\x1b[92m[" + to_string(treeStorage[6].val) + "]\33[0m" : "\x1b[31m[ ]\33[0m";
            string sevenLeft = treeStorage[13].exists ? "\x1b[92m_____" : "\x1b[31m_____";
            string sevenRight = treeStorage[14].exists ? "\x1b[92m_____\33[0m" : "\x1b[31m_____\33[0m";
            seven = sevenLeft + seven + sevenRight;
        //layer 4, leaf nodes no need no connect
        string eight = treeStorage[7].exists ? "\x1b[92m[" + to_string(treeStorage[7].val) + "]\33[0m" : "\x1b[31m[ ]\33[0m";
        string nine = treeStorage[8].exists ? "\x1b[92m[" + to_string(treeStorage[8].val) + "]\33[0m" : "\x1b[31m[ ]\33[0m";
        string ten = treeStorage[9].exists ? "\x1b[92m[" + to_string(treeStorage[9].val) + "]\33[0m" : "\x1b[31m[ ]\33[0m";
        string eleven = treeStorage[10].exists ? "\x1b[92m[" + to_string(treeStorage[10].val) + "]\33[0m" : "\x1b[31m[ ]\33[0m";
        string twelve = treeStorage[11].exists ? "\x1b[92m[" + to_string(treeStorage[11].val) + "]\33[0m" : "\x1b[31m[ ]\33[0m";
        string thirteen = treeStorage[12].exists ? "\x1b[92m[" + to_string(treeStorage[12].val) + "]\33[0m" : "\x1b[31m[ ]\33[0m";
        string fourteen = treeStorage[13].exists ? "\x1b[92m[" + to_string(treeStorage[13].val) + "]\33[0m" : "\x1b[31m[ ]\33[0m";
        string fifteen = treeStorage[14].exists ? "\x1b[92m[" + to_string(treeStorage[14].val) + "]\33[0m" : "\x1b[31m[ ]\33[0m";
        //main cout :)
        cout <<
        "\n\x1b[95mTree:\n––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\33[0m\n\n"
        "                       " + one + "                       \n"
        "            " + two + "                           " + three + "            \n"
        "      " + four + "         " + five + "               " + six + "         " + seven + "      \n"
        "     " + eight + "         " + nine + "       " + ten + "         " + eleven + "             " + twelve + "         " + thirteen + "       " + fourteen + "         " + fifteen + "      \n\n"
        "\x1b[95m––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\33[0m\n";
        //clear storage for next call
        treeStorage.clear();
    }

};

//this has the avl tree code
class Tree {
    public:
    string name;
    Tree(string n) : name(n) {}

    //recursively getting height and checking balance
    void balance(TreeNode*& root) {        
        //base case
        if(root == nullptr) return;
        //leaf, check if balanced BY POSTORDER
        balance(root->left);
        balance(root->right);
        //find height from max children height. nullptr = -1 height. done through POSTORDER TRAVERSAL
        //set height
        root->height = anyMax((root->left ? root->left->height : 0), (root->right ? root->right->height : 0)) + 1;
        //checking balance, [syntax is ––> if(true) ? do : else], need to recalculate heights before
        int balanceFactor = returnBalance(root);
        //skip checks
        if(abs(balanceFactor) <= 1) return;
        //balance factor = left height - right height
        //if negative (<-1), right heavy  |  rotate left
        //if positive (>1), left heavy    |  rotate right
        if(balanceFactor > 1) { //IF LEFT HEAVY, check if LEFT CHILD IS RIGHT HEAVY. if so, LR
            //if child balance factor = 0, child balanced or is a leaf node
            int leftBalanceFactor = returnBalance(root->left);
            if(leftBalanceFactor < 0) { leftRotate(root->left); 
                                        updateHeight(root->left); }
            //balance of left child can be 1 (left heavy) or 0 (neutral)
            //do actual rotation
            rightRotate(root);
            updateHeight(root);
        } else if(balanceFactor < -1) { //right heavy, need to check if RIGHT CHILD IS RIGHT HEAVY, gives LR
            //right balance factor
            int rightBalanceFactor = returnBalance(root->right);
            //balance of rchild can be -1 (rh) or 0 (n)
            if(rightBalanceFactor > 0) { rightRotate(root->right);
                                         updateHeight(root->right); }
            //actual rotation
            leftRotate(root);
            updateHeight(root);
        } 
    }

    //give balance factor of a given root
    int returnBalance(TreeNode* root) {
        //every case this is called has a height check before it, therefore no need to update height
        if(root == nullptr) return 0;
        return((root->left ? root->left->height : 0) - (root->right ? root->right->height : 0));
    }

    //updates height bottom up from root
    void updateHeight(TreeNode* root) {
        if(root == nullptr) return;
        updateHeight(root->left);
        updateHeight(root->right);
        root->height = anyMax((root->left ? root->left->height : 0), (root->right ? root->right->height : 0)) + 1;
    }

    //inserts a value, dupes are added to int TreeNode::count
    void insertValue(TreeNode*& root, int valOfInsertion) {
        //standard bst insertion:
        if(root == nullptr) { root = new TreeNode(valOfInsertion); return; }
        if(valOfInsertion == root->val) { root->dupes++; cout << "\x1b[93m\n[There are (" //dupe message
                                                                  + to_string(root->dupes)
                                                                  + ") instances of "
                                                                  + to_string(valOfInsertion)
                                                                  + "]\33[0m\n"; return; }
        if(valOfInsertion > root->val) { insertValue(root->right, valOfInsertion); }
        else if(valOfInsertion < root->val) { insertValue(root->left, valOfInsertion); }
        //balance resets all height from root downwards
    }

    //deletes a value, cases are 0,1,2 child
    void deleteValue(TreeNode*& root, int val, bool& found) {
        //found defaults to false
        if(root == nullptr) return; //if past leaf node
        //end early
        if(found == true) return;
        //everything here has AT LEAST 1 CONNECTING NODE
        if(root->val == val) {
            //located, stops all other recursion
            found = true;
            if(root->dupes > 1) { root->dupes--; cout << "\x1b[93m\n[There are (" //dupe message
                                                          + to_string(root->dupes)
                                                          + ") instances of "
                                                          + to_string(val)
                                                          + "]\33[0m\n"; return; }
            int children = root->numberOfChildren(root);
            switch(children) {
                case 0:
                    delete root;
                    root = nullptr;
                    break;
                case 1:
                    anySwap(root->val, root->left ? root->left->val : root->right->val);
                    if(root->left) { delete root->left; root->left = nullptr; }
                    else { delete root->right; root->right = nullptr; }
                    break;
                default:
                    //if there are 2 children of current node and both of the children nodes lack left(for r) and right(for l)
                    //then we swap 
                    //if successor exists
                    if(returnSmallest(root->right) != nullptr) {
                        anySwap(returnSmallest(root->right)->val, root->val);
                        deleteSmallest(root->right);                    
                    } else if(returnLargest(root->left) != nullptr) {
                        anySwap(returnLargest(root->left)->val, root->val);
                        deleteLargest(root->left);
                    } else {
                        //if left child only has left children or if right child only has right children, or if left and right child have no children                        
                        TreeNode* tempLeft = root->left; //saves node
                        TreeNode* tempRight = root->right;
                        delete root;
                        root = nullptr;
                        root = tempLeft;
                        root->right = tempRight;
                    }                    
            }
        } else { //recurse
            deleteValue(root->left, val, found);
            deleteValue(root->right, val, found);
        }
    }

    //auxillary function for deleteValue
    TreeNode* returnSmallest(TreeNode* root) { //call with root->right
        //if left isnt null then go left otherwise return null
        if(root->left) { while(root->left) { root = root->left; } return root; }
        else return nullptr;
    }

    //auxillary function for deleteValue
    TreeNode* returnLargest(TreeNode* root) { //call with root->left
        //same logic as return smallest but flipped
        if(root->right) { while(root->right) { root = root->right; } return root; }
        else return nullptr;
    }

    //auxillary function for deleteValue
    void deleteSmallest(TreeNode*& root) { //call with root->right
        //if root->left == nullptr, smallest !predecessor reached
        if(root->left == nullptr) {
            TreeNode* tempRight = root->right;
            delete root;
            root = nullptr;
            root = tempRight;
        } else { deleteSmallest(root->left); return; }
    }

    //auxillary function for deleteValue
    void deleteLargest(TreeNode*& root) {
        //if root->right == nullptr, largest predecessor reached
        if(root->right == nullptr) {
            TreeNode* tempLeft = root->left;
            delete root;
            root = nullptr;
            root = tempLeft;
        } else { deleteLargest(root->right); return; }
    }

    //auxillary function for balance
    void rightRotate(TreeNode*& root) {
        //save left child
        TreeNode* newRoot = root->left;        
        //set original root's left child to new root right child:
        root->left = newRoot->right;
        //set new root right child to original root:
        newRoot->right = root;
        //"return" newRoot
        root = newRoot;
    }

    //auxillary function for balance
    void leftRotate(TreeNode*& root) {
        //0. save right child
        TreeNode* newRoot = root->right;        
        //1. set original root's right child to new root left child:
        root->right = newRoot->left;
        //2. set new root left child to original root:
        newRoot->left = root;
        //"return" newRoot
        root = newRoot;
    }

    //delete, postorder
    void deleteTree(TreeNode*& root) {
        if(root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = nullptr;
    }

};

//generic swap
template<typename generic>
void anySwap(generic& a, generic& b) {
    generic temp = a;
    a = b;
    b = temp;
}

//generic compare
template<typename generic>
generic anyMax(generic a, generic b) {
    if(a > b) return a;
    return b;
}

int main() {
    //resizing terminal based on OS
    #ifdef _WIN32
        system("mode con: cols=109 lines=21");
    #elif defined(__unix__) || defined(__APPLE__) && defined(__MACH__)
        system("resize -s 21 109");
    #else
        cout << "\x1b[31mUnable to resize terminal.\n
                         Please make terminal larger.\33[0m\n\n";
    #endif
    //INTRO ASCII ART BLOCK  + small title + credits
    cout << "\033[48;5;201m\x1b[1;30m\n\n   _____ _____ __       _____ _____ _____ _____    _____ _____ _____ _____ _____ _ _____ _____ _____ _____   \n"
            "  |  _  |  |  |  |     |_   _| __  |   __|   __|  |  |  |     |   __|  |  |  _  | |     |__   |   __| __  |  \n"
            "  |     |  |  |  |__     | | |    -|   __|   __|  |  |  |-   -|__   |  |  |     | |-   -|   __|   __|    -|  \n"
            "  |__|__|\\___/|_____|    |_| |__|__|_____|_____|   \\___/|_____|_____|_____|__|__|_|_____|_____|_____|__|__|  \n"
            "  AVL Tree Visualizer                                                                        By: Alex Zhang\n\33[0m\n\n";
    //this NEEDS to be at least 109x49 because of the intro block
    //INTRO INSTRUCTIONS ETC
    cout << "\x1b[95m\nIntroduction:\n–––––––––––––\n"
                    "Welcome to AVL Tree Visualizer!\n"
                    "For demonstrative purposes, this model will only allow integers.\n"
                    "I'm pretty sure I bad-input-proofed everything...\n"
                    "Have fun with it :)\n\n";
    //ngl i optimized a lot of the earlier functions and i just couldnt be bothered to optimize the stuff in the switch
    //loop so its just a copy/paste skull emoji
    //class declaration
    Tree tree("treeOne");
    numStruct storage("treeStorage");
    //run condition and delete condition
    bool quit = false;
    bool deleted = false;
    //root instantiation
    TreeNode* root = nullptr;
    //main loop
    while(quit == false) {
        //edge case
        if(root == nullptr) {
            cout << "\n\x1b[95mEnter your first value (int):\n–––––––––––––––––––––––––––––\33[0m\n";
            //cin first node val
            int firstValue;
            cin >> firstValue;
            //if user is an idiot or a troll or a tester
            if(cin.fail()) {
                cin.clear();
                cin.ignore(500, '\n');
                cout << "\n\x1b[31mInvalid symbol. Please enter a number:\n––––––––––––––––––––––––––––––––––––––\33[0m\n\n";
                continue;
            }
            //make first node
            root = new TreeNode(firstValue);
        } else {
            //variables for action and value
            char action;
            int value;
            cout << "\n\x1b[95mAction required:\n–––––––––––––––––––\n"
                    "\x1b[92m'A' to add value\n"
                    "\x1b[31m'D' to delete value\n"
                    "\033[48;5;160m\x1b[1;30m'C' to clear tree\33[0m\n"
                    "\x1b[93m'Q' to quit\33[0m\n";
            cin >> action;
            switch(action) {
                case 'A': //addition
                    cout << "\n\x1b[92mEnter value to add:\n–––––––––––––––––––\33[0m\n";
                    cin >> value;
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(500, '\n');
                        cout << "\n\x1b[31mInvalid number. Please enter a number:\n––––––––––––––––––––––––––––––––––––––\33[0m\n\n";
                        continue;
                    }
                    tree.insertValue(root, value);
                    break;
                case 'D': //deletion
                    cout << "\n\x1b[31mEnter value to delete:\n––––––––––––––––––––––\33[0m\n";
                    cin >> value;
                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(500, '\n');
                        cout << "\n\x1b[31mInvalid number. Please enter a number:\n––––––––––––––––––––––––––––––––––––––\33[0m\n\n";
                        continue;
                    }
                    tree.deleteValue(root, value, deleted);
                    if(deleted == false) { cout << "\n\x1b[31mValue not found. Please try again:\n––––––––––––––––––––––––––––––––––\33[0m\n\n"; }
                    else { deleted = false; }
                    break;
                case 'Q': //quit
                    quit = true;
                    cout << "\n\x1b[93mJoever:\n–––––––\33[0m\n";
                    break;
                case 'C': //clear tree
                    tree.deleteTree(root);
                    break;
                default: //wrong input
                    cin.clear();
                    cin.ignore(500, '\n');
                    cout << "\n\x1b[31mInvalid action. Please enter again:\n–––––––––––––––––––––––––––––––––––\33[0m\n\n";
                    continue;
                    break;
            }
        }
        //balance
        tree.balance(root);
        //print
        storage.printTree(root);
    }
    return 0;
}