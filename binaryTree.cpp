#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the data: ";
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter the data to insert in the left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data to insert in the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void LevelOrderTraversal(Node *root) // also called breadth first search
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;   // if the level is completed
            if (!q.empty()) // if there are further elements remaining in the tree
            {
                q.push(NULL); // Next NULL for next level
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left) // if left node contains data
            {
                q.push(temp->left);
            }
            if (temp->right) // if right node contains data
            {
                q.push(temp->right);
            }
        }
    }
}

void reverseLevelOrderTraversal(Node *root) // also called breadth first search
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    stack<Node *> s;
    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            s.push(NULL);
            if (!q.empty()) // if there are further elements remaining in the tree
            {
                q.push(NULL); // Next NULL for next level
            }
        }
        else
        {
            s.push(temp);
            if (temp->left) // if left node contains data
            {
                q.push(temp->left);
            }
            if (temp->right) // if right node contains data
            {
                q.push(temp->right);
            }
        }
    }
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        if (temp == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << temp->data << " ";
        }
    }
}

void inorder(Node *root)
{
    // LNR

    // base case
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    // NLR

    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    // LRN

    // base case
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void buildTreeFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    root = new Node(rootData);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int leftData;
        cout << "Enter data for left: ";
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        cout << "Enter data for right: ";
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int height(Node *node)
{
    // base case
    if (node == NULL)
    {
        return 0;
    }
    int leftSubtreeHeight = height(node->left);
    int rightSubtreeHeight = height(node->right);
    return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
} // time complexity=O(n) Space complexity=O(height)

pair<int, int> diameterFast(Node *root)
{
    // base case
    if (root == NULL)
    {
        pair<int, int> p = {0, 0};
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}
// Function to return the diameter of a Binary Tree.
int diameter(Node *root)
{
    return diameterFast(root).first;
}

pair<bool, int> fastIsBalanced(Node *root)
{
    // base case
    if (root == NULL)
    {
        pair<bool, int> p = {true, 0};
        return p;
    }

    pair<bool, int> left = fastIsBalanced(root->left);
    pair<bool, int> right = fastIsBalanced(root->right);

    bool isLeftBalanced = left.first;
    bool isRightBalanced = right.first;
    bool isDiffBalanced = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if (isLeftBalanced && isRightBalanced && isDiffBalanced)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

bool isBalanced(Node *root)
{
    return fastIsBalanced(root).first;
}

bool isIdentical(Node *r1, Node *r2)
{
    // base case
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }

    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }

    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    bool isValueSame = r1->data == r2->data;

    if (left && right && isValueSame)
    {
        return true;
    }
    else
    {
        return false;
    }
}

pair<bool, int> solve(Node *root)
{
    // base case
    if (root == NULL)
    {
        pair<bool, int> p = {true, 0};
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = {true, root->data};
        return p;
    }

    pair<bool, int> left = solve(root->left);
    pair<bool, int> right = solve(root->right);

    bool leftSum = left.first;
    bool rightSum = right.first;
    bool condn = root->data == left.second + right.second;

    pair<bool, int> ans;
    if (leftSum && rightSum && condn)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
        return ans;
    }

    return ans;
}
bool isSumTree(Node *root)
{
    return solve(root).first;
}

vector<int> zigZagTraversal(Node *root)
{
    if (root == NULL)
    {
        return {};
    }
    vector<int> result;
    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {

        int size = q.size(); // To traverse all the nodes for a level
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            int index = leftToRight ? i : size - 1 - i; // Normal insert or reverse insert
            ans[index] = temp->data;
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        leftToRight = !leftToRight;
        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}

void traverseLeft(Node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->data);
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

void traverseLeaf(Node *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);

    // wapas aagye
    ans.push_back(root->data);
}

vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    // left part print/store
    traverseLeft(root->left, ans);

    // traverse Leaf Nodes

    // left subtree
    traverseLeaf(root->left, ans);
    // right subtree
    traverseLeaf(root->right, ans);

    // traverse right part
    traverseRight(root->right, ans);

    return ans;
}

vector<int> verticalOrder(Node *root)
{
    map<int, map<int, vector<int>>> nodes; // 1st int-HD,2nd int=Level
    queue<pair<Node *, pair<int, int>>> q; // 1st int=Horizontal distance and 2nd int=level in 2nd pair
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, make_pair(0, 0))); // In start both level and HD is 0

    while (!q.empty())
    {

        pair<Node *, pair<int, int>> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }

    return ans;
}

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> topNode;      // 1st int=HD,2nd int=root->data
    queue<pair<Node *, int>> q; // int represents HD
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        if (topNode.find(hd) == topNode.end()) // true if there is no entry in map corresponding to topNode
        {
            topNode[hd] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> topNode;      // 1st int=HD,2nd int=root->data
    queue<pair<Node *, int>> q; // int represents HD
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

void solveLeft(Node *root, vector<int> &ans, int level)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // we entered a new level
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    solveLeft(root->left, ans, level + 1);
    solveLeft(root->right, ans, level + 1);
}

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    solveLeft(root, ans, 0);
    return ans;
}

void solveRight(Node *root, vector<int> &ans, int level)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // we entered a new level
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    solveRight(root->right, ans, level + 1);
    solveRight(root->left, ans, level + 1);
}
// Function to return list containing elements of right view of binary tree.
vector<int> rightView(Node *root)
{
    vector<int> ans;
    solveRight(root, ans, 0);
    return ans;
}

void solveForBloodline(Node *root, int sum, int &maxSum, int len, int &maxLen)
{
    // base case
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(maxSum, sum);
        }
        return;
    }

    sum = sum + root->data;

    // 2 calls for left child and right child now
    solveForBloodline(root->left, sum, maxSum, len + 1, maxLen);
    solveForBloodline(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = INT32_MIN;

    solveForBloodline(root, sum, maxSum, len, maxLen);
    return maxSum;
}

Node *lca(Node *root, int n1, int n2)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    // if the data has been found
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);

    // applying all 4 possible combinations
    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else
    {
        return NULL;
    }
} // T>C:O(n), SC:O(h)

void solveKSum(Node *root, unordered_map<int, int> &mp, int k, int &count, int prev)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    int curr = prev + root->data;

    if (mp.find(curr - k) != mp.end())
    {
        count += mp[curr - k];
    }

    if (curr == k)
    {
        count++;
    }

    mp[curr]++;

    solveKSum(root->left, mp, k, count, curr);
    solveKSum(root->right, mp, k, count, curr);

    mp[curr]--;
}

int sumK(Node *root, int k)
{
    unordered_map<int, int> mp;
    int count = 0;
    solveKSum(root, mp, k, count, 0);
    return count;
}

Node *solveKthAncestor(Node *root, int &k, int node)
{
    // base case
    if (root == NULL)
        return NULL;

    if (root->data == node)
    {
        return root;
    }

    Node *leftAns = solveKthAncestor(root->left, k, node);
    Node *rightAns = solveKthAncestor(root->right, k, node);

    // wapas
    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            // answer lock
            k = INT32_MAX;
            return root;
        }
        return leftAns;
    }

    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            // answer lock
            k = INT32_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solveKthAncestor(root, k, node);
    if (ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}

pair<int, int> solveAdjSum(Node *root)
{
    // base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = solveAdjSum(root->left);
    pair<int, int> right = solveAdjSum(root->right);

    pair<int, int> res;

    res.first = root->data + left.second + right.second;

    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}
int getMaxSum(Node *root)
{
    pair<int, int> ans = solveAdjSum(root);
    return max(ans.first, ans.second);
}

int findPosition(int in[], int inorderStart, int inorderEnd, int element, int n)
{
    for (int i = inorderStart; i <= inorderEnd; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node *solvetoBuild(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n)
{
    // base case
    if (index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = pre[index++]; // to get the root element in preorder
    Node *root = new Node(element);
    int position = findPosition(in, inorderStart, inorderEnd, element, n); // to find the position of root element in inorder

    // recursive calls
    root->left = solvetoBuild(in, pre, index, inorderStart, position - 1, n);
    root->right = solvetoBuild(in, pre, index, position + 1, inorderEnd, n);

    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    Node *ans = solvetoBuild(in, pre, preOrderIndex, 0, n - 1, n);
    return ans;
}

Node *create(int in[], int pre[], int n, int &index, int startIndex, int endIndex, map<int, int> &valueToIndex)
{
    // base case
    if (index < 0 || startIndex > endIndex)
        return NULL;

    int element = pre[index--];
    Node *temp = new Node(element);
    int position = valueToIndex[element];

    temp->right = create(in, pre, n, index, position + 1, endIndex, valueToIndex);
    temp->left = create(in, pre, n, index, startIndex, position - 1, valueToIndex);

    return temp;
}
void createMap(int in[], int n, map<int, int> &valueToIndex)
{
    for (int i = 0; i < n; i++)
    {
        valueToIndex[in[i]] = i;
    }
}
Node *buildTreeWithPost(int in[], int post[], int n)
{
    // Your code here
    int postorderIndex = n - 1;
    map<int, int> valueToIndex;
    createMap(in, n, valueToIndex);

    Node *ans = create(in, post, n, postorderIndex, 0, n - 1, valueToIndex);

    return ans;
}

int main()
{
    Node *root = NULL;
    // root = buildTree(root);
    cout << endl;
    buildTreeFromLevelOrder(root);
    cout << endl;
    LevelOrderTraversal(root);
    // reverseLevelOrderTraversal(root);
    cout << endl;
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    return 0;
}
