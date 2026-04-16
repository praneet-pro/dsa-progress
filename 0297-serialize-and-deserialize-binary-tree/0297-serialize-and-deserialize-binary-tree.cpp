/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string out = "";
        buildString(root, out);
        return out;
    }

    void buildString(TreeNode* node, string& out) {
        if(node == NULL) {
            out += "N,";
            return;
        }

        out += to_string(node->val) + ",";

        buildString(node->left, out);
        buildString(node->right, out);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> belt = splitString(data);     // remove commas in string and store em seperately in queue
        return buildTree(belt);
    }

    queue<string> splitString(string data) {
        queue<string> belt;
        stringstream ss(data);
        string token;
        while(getline(ss, token, ','))
            belt.push(token);
        return belt;
    }

    TreeNode* buildTree(queue<string>& belt) {
        if(belt.empty()) return NULL;

        string current = belt.front();
        belt.pop();

        if(current == "N") 
            return NULL;

        TreeNode* house = new TreeNode(stoi(current));
        house->left = buildTree(belt);
        house->right = buildTree(belt);

        return house;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));