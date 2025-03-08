#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long ull;

/*
Binary Search Tree Properties
1> No duplicate
2> Inorder traversal giver sorted array 
*/

struct Node
{
    Node *pLeftChild, *pRightChild;
    int iVal;
    Node ()
    {
        iVal = 0;
        pLeftChild = pRightChild = NULL;
    }
    Node (int iVal)
    {
        this->iVal = iVal;
        pLeftChild = pRightChild = NULL;
    }
};

class BST
{
    private:    
    int iNodeCnt;
    Node *pRootNode;

    public:
    BST () : pRootNode {NULL}, iNodeCnt{0} {}

    /*
        7
       / \
      5   10
      Process for insertion:
      1> Remeber BST does not hold duplicate elements.
      2> In BST we always insert element on leaf node so keep 
         checking for element value if it is lesser go to left else 
         if element value is greater than crnt node than go to right.
      3> Once leaf node (NULL) is reached check if parent is valid if valid then insert.
      4> If parent is NULL then set it in RootNode.
    */
    bool insert(int iVal)
    {
        Node *pNode = new Node(iVal);
        cout<<"Node Created!\n";
        Node *pCrntNode = pRootNode;
        Node *pParentNode = NULL;
        while (pCrntNode)
        {
            pParentNode = pCrntNode;
            if (pNode->iVal < pCrntNode->iVal)
            {
                pCrntNode = pCrntNode->pLeftChild;
            }
            else if (pNode->iVal > pCrntNode->iVal)
            {
                pCrntNode = pCrntNode->pRightChild;
            }
            else 
            {
                cout << "Failed to Insert.BST does not support duplicate elements!\n";
                delete pNode;
                pNode = NULL;
                return false;
            }
        }

        if (pParentNode)
        {
            if (pNode->iVal < pParentNode->iVal)
            {
                pParentNode->pLeftChild = pNode;
            }
            else
            {
                pParentNode->pRightChild = pNode;
            }
        }
        else 
        {
            pRootNode = pNode;
        }

        ++iNodeCnt;
        return true;
    }

    Node* minOfRightSubTree(Node *pNode)
    {
        while (pNode && pNode->pLeftChild)
        {
            pNode = pNode->pLeftChild;
        }
        return pNode;
    }
    // Function to delete a node from BST.
    Node* deleteNode(Node *root, int iVal) 
    {
        if (!root)
        {
            return NULL;
        }
        if (iVal < root->iVal)
        {
            root->pLeftChild = deleteNode(root->pLeftChild, iVal);
        }
        else if (iVal > root->iVal)
        {
            root->pRightChild = deleteNode(root->pRightChild, iVal);
        }
        else
        {
            //If the node has only one child [s].
            if (NULL == root->pLeftChild)
            {
                Node *pNode = root->pRightChild; //Even if right node is NULL or not it does not matter.
                delete root;
                return pNode; //Even if right node is NULL or not it does not matter.
            }
            else if (NULL == root->pRightChild)
            {
                Node *pNode = root->pLeftChild;
                delete root;
                return pNode;
            }
            //If the node has only one child [e].
            
            Node *pNode = minOfRightSubTree(root->pRightChild);
            root->iVal = pNode->iVal;
            root->pRightChild = deleteNode(root->pRightChild, root->iVal);   
        }
        return root;
    }

    void remove(int iVal)
    {
        Node* pNode = pRootNode;
        deleteNode(pNode, iVal);
    }
    

    //Inorder Traversal for tree.
    void fillInorder(vector<int>& vecInorder, Node *pNode)
    {
        if (pNode)
        {
            fillInorder(vecInorder, pNode->pLeftChild);
            vecInorder.push_back(pNode->iVal);
            cout << pNode->iVal << " ";
            fillInorder(vecInorder, pNode->pRightChild);
        }
    }

    void getInorder()
    {
        Node *pNode = pRootNode;
        vector<int> vecInorder;
        cout << "Inorder traversal for BST:\n";
        fillInorder(vecInorder, pNode);
        cout << endl;
    }
};
    
int main()
{
    cout << "\n";
    BST bst;
    bst.insert(7);
    bst.insert(5);
    bst.insert(10);
    bst.insert(10);
    bst.getInorder();
    bst.remove(7);

    bst.getInorder();
    
    return 0;
}
