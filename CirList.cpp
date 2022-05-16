#include <iostream>

using namespace std;

class CirList;
class ListNode {
    friend class CirList;
    
private:
    int data;
    ListNode  *next;
public:
    ListNode(int a=0, ListNode* ptr=NULL) : data(a), next(ptr) { }
};

class CirList {
    ListNode  *last;    // 마지막 노드의 주소
public: 
    CirList( ) : last(NULL) {  }    // 생성자
    CirList(int c) : last(new ListNode( c )) { last ->next = last; }  // 생성자
    //int Oddsum( );
	//int Findmax( ); 
	//int Deleven( );      
	void Movemin( );
    void Display( );
    void InsertLast(ListNode* ptr);
    ~CirList(){
    	cout << "객체 소멸";
	};
};

void CirList::InsertLast(ListNode *ptr) 
{ 
	if ( last == NULL )  // 빈 리스트
		ptr -> next = ptr;
	else {
	    ptr -> next = last -> next;
	    last -> next = ptr;
	}
	last = ptr;
}

void CirList::Display( )	
{
    ListNode* ptr;

    if (last==NULL)
        return;
    ptr = last->next;   cout << "(";
    while ( ptr != last ) {
        cout << ptr -> data << "→";
        ptr = ptr -> next;
    }
    cout << ptr -> data;    cout << ")\n";
 }
 
/*
int CirList::Oddsum( )
{
   int sum=0, count=1;
   if (last==NULL) return -1;
   ListNode *ptr = last->next;
   sum = ptr->data;
   if (ptr==last) return sum;
   do {
      count++;
      ptr = ptr->next;
      if (count % 2 == 1)
         sum = sum+ptr->data;
   } while (ptr != last);
   cout << sum << endl;
   return sum;
}
*/
/*
int CirList::Findmax( )
{
   int max;
   ListNode *ptr = last->next;
   if (last == NULL) return -1;
   max = ptr->data;
   if (ptr == last) return max;
   do {
      ptr = ptr->next;
      if (ptr->data > max)
         max = ptr->data;
   } while (ptr != last);
   cout << "최대값은"<< max << endl;
   return max;
}
*/
/*
int CirList::Deleven( )
{
   int count=1, odd=0;
   ListNode *ptr, *pre, *tmp;
   if (last == NULL) return 0;
   pre = last;;
   ptr = last->next;
   if (ptr == last) return 1;
   do {
      if (count % 2 == 0) {
         pre->next = ptr->next;
         tmp = ptr;
         ptr = pre->next;
         if (tmp == last) last = pre;
         delete tmp;
      }
      else {
         odd++;
         pre = ptr;
         ptr = ptr->next;
      }
      count++;
   } while (pre != last);
   cout << "남은 노드의 갯수는 "<< odd << endl;
   return odd;
}
*/

void CirList::Movemin( )
{
   int min;
   ListNode *ptr, *pmin, *pre, *ptmp; 
   if (last == NULL) return;
   ptr = last->next;
   if (ptr == last) return;
   min = ptr->data;
   pmin = ptr;
   pre = NULL;
   do {
      ptmp = ptr;
      ptr = ptr->next;
      if (ptr->data < min) {
         min = ptr->data;
         pmin = ptr;
         pre = ptmp;
      }
   } while (ptr != last);
   if (pre == NULL) return;
   if (pmin == last) {
      last = pre;
      return;
   }
   pre->next = pmin->next;
   pmin->next = last->next;
   last->next = pmin;
   return;
}
int main(void)
{
	int c;
	ListNode *ptr;
	cin >> c;
	CirList clobj(c);
 
	cin >> c;
	ptr=new ListNode(c);
	clobj.InsertLast(ptr);

	cin >> c;
	ptr=new ListNode(c);
	clobj.InsertLast(ptr);

	cin >> c;
	ptr=new ListNode(c);
	clobj.InsertLast(ptr);

	cin >> c;
	ptr=new ListNode(c);
	clobj.InsertLast(ptr);
	
	clobj.Movemin();    
	clobj.Display();
	delete ptr;
	return 0;
}
