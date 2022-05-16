#include <iostream>

using namespace std;

class BSearchTree;
class BinaryNode {
    friend class BSearchTree;
private: 
    BinaryNode* Left;
    int data;
    BinaryNode* Right;
    BinaryNode(BinaryNode *lp=0, int d=0, BinaryNode* rp=0):
                                    Left(lp), data(d), Right(rp) { }
};

class BSearchTree {
private:
    BinaryNode *root;
public:
    BSearchTree() : root(NULL) { }   // 积己磊
    BinaryNode* GetRoot( ) { return root; }
    int CreatTree(int, int*);
    //int LVXN(int);             // 巩力 (a)
    //int TRSM(BinaryNode*);    // 巩力 (b)
    //int HGHT(BinaryNode*);    // 巩力 (c)
    int IsLeaf(int);             // 巩力 (d) 
    void DeleteNode(BinaryNode*);
    ~BSearchTree(){DeleteNode(root);};
};

int BSearchTree::CreatTree(int n, int* IntArray)
{
	BinaryNode *p, *q;
	for (int i=0; i<n; ++i) {
	   q=NULL; p = root;
	   while (p) {
	        q = p;
	        if (IntArray[i] == p->data) return 0;
	        if (IntArray[i] < p->data) p = p->Left;
	        else p = p->Right;
	   }
	   p = new BinaryNode; 
	   p->data = IntArray[i];
	   if (!root) root = p;
	   else if (q->data < IntArray[i]) q->Right = p;
	   else q->Left = p;
	}
	return 1; 
}

void BSearchTree::DeleteNode(BinaryNode *ptr)
{
	if(ptr) {
		DeleteNode(ptr->Left);
		DeleteNode(ptr->Right);
		delete ptr;
	}
}
/*
int BSearchTree::LVXN(int x)
{
   BinaryNode* p;
   int level=0;

   p = root;
   while (p) {
      if (p->data == x) return level;
      if (p->data > x)
         p = p->Left;
      else
         p = p->Right;
      level = level + 1;
    }
    cout << level;
   return -1;
}
*/

/*
int BSearchTree::TRSM(BinaryNode* nd)
{
   if (nd == NULL) 
      return 0;
    
    
   return(nd->data + TRSM(nd->Left) +
                      TRSM(nd->Right));

}
*/
/*
int BSearchTree::HGHT(BinaryNode* nd)
{
   int left, right;
   if (nd == NULL)
      return -1;
   left = HGHT(nd->Left) + 1;
   right = HGHT(nd->Right) + 1;
   if (left > right)
      return left;
   else
      return right;
}
*/
int BSearchTree::IsLeaf(int x)
{
   BinaryNode* p;

   p = root;
   while (p) {
      if (p->data == x) break;
      if (p->data > x) {
         p = p->Left;
      }
      else {
         p = p->Right;
      }
   }
   if (p == NULL)
      return -1;
   if (p->Left == NULL 
            && p->Right == NULL)
      return 1;
   return 0;
}
int main(void)
{
	BinaryNode *p;
	int z = 0;
	
	int IntArray[] = {38,14,56,8,23,48,82,18,70,20};
	BSearchTree bst;
	bst.CreatTree(10, IntArray);
	p = bst.GetRoot( );
	bst.IsLeaf(38);
	z = bst.IsLeaf(38);
	cout << z;
	delete p;
	return 0;
}
