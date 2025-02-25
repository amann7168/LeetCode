// 105. Construct Binary Tree from Preorder and Inorder Traversal

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         return buildtreehelper(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
    }
    
private:
    TreeNode* buildtreehelper(vector<int>& in, vector<int>& pre, int inS, int inE, int preS, int preE) {
        if (inS > inE) return nullptr;

        int rootdata = pre[preS];
        int rootindex = -1;

         for (int i = inS; i <= inE; i++) {
            if (in[i] == rootdata) {
                rootindex = i;
                break;
            }
        }

         int leftInS = inS;
        int leftInE = rootindex - 1;
        int leftPreS = preS + 1;
        int leftPreE = leftInE - leftInS + leftPreS;

        int rightPreS = leftPreE + 1;
        int rightPreE = preE;
        int rightInS = rootindex + 1;
        int rightInE = inE;

         TreeNode* root = new TreeNode(rootdata);

        root->left = buildtreehelper(in, pre, leftInS, leftInE, leftPreS, leftPreE);
        root->right = buildtreehelper(in, pre, rightInS, rightInE, rightPreS, rightPreE);

        return root;
    }
};
