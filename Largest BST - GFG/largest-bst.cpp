//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    unordered_map<Node *,pair<bool,vector<int>>> m; 
    pair<bool,vector<int>> isBst(Node *root){
        if(!root){
            return {true,{INT_MAX,INT_MIN,0}};
        }
        if(m.find(root)!=m.end()){
            return m[root];
        }
        pair<bool,vector<int> > left = isBst(root->left);
        pair<bool,vector<int>> right = isBst(root->right);
        pair<bool,vector<int>> current = {false,{0,1,2}};
        current.first = left.first&&right.first;
        if(root->left){
            current.first = current.first&&root->data>left.second[1];
        }
        if(root->right){
            current.first = current.first&&root->data<right.second[0];
        }
        current.second[2]=left.second[2]+right.second[2]+1;
        current.second[1]= max(root->data, max(left.second[1],right.second[1]));
        current.second[0]= min(root->data, min(left.second[0],right.second[0]));
        return m[root]= current;
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	if(!root){
    	    return 0;
    	}
    	int left = largestBst(root->left);
    	int right = largestBst(root->right);
    	pair<bool,vector<int>> current = isBst(root);
    	if(current.first){
    	    return max(left,max(right,current.second[2]));
    	}
    	return max(left,right);
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends