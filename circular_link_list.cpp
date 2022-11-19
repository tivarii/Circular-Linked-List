#include <bits/stdc++.h>
using namespace std;
struct node
{
    int item;
    node *next;
};
class CLL
{
    node *last;
public:
    CLL();
    void traverse();
    void insertAtbegin(int);
    void append(int);
    node * search(int);
    void insertAfter_specific_node(node *,int);
    void deleteFirstnode();
    void deleteLastnode();
    void deleteSpecificnode(node *);
    ~CLL();
};
CLL::~CLL(){
    while(last)
        deleteFirstnode();
}
void CLL::deleteSpecificnode(node * index){
    if(!index){
        cout<<"Invalid index";
    }
    node *temp=last;
    while(temp->next!=index)
        temp=temp->next;
    if(temp->next==temp){
        delete temp;
        last=NULL;
    }
    temp->next=index->next;
    if(index==last){
        delete index;
        last=temp;
        return;
    }
    delete index;
}

void CLL::deleteLastnode(){
    if(!last){
        cout<<"\nlist is empty.";
        return;
    }
    node *temp=last;
    if(temp->next==last){
        delete temp;
        last=NULL;
        return;
    }
    while(temp->next!=last)
        temp=temp->next;
    temp->next=last->next;
    delete last;
    last=temp;
}

void CLL::deleteFirstnode(){
    if(!last){
        cout<<"\nlist is empty.";
        return;
    }
    node *temp=last->next;
    if(temp->next==last){
        delete temp;
        last=NULL;
        return;
    }
    last->next=temp->next;
    delete temp;

}

void CLL::insertAfter_specific_node(node * index,int data){
    if(!index){
        cout<<"invalid adress.";
        return;
    }
    node *ptr=new node;
    ptr->item=data;
    ptr->next=index->next;
    index->next=ptr;
}

node * CLL::search(int data){
    if(!last){
        cout<<"list is empty";
        return NULL;
    }
    node * temp=last;
    if(last->item==data){
        return last;
    }
    while(temp->next!=last){
        if(temp->item==data){
            cout<<data<<"is found at \""<<temp<< "\" address";
            return temp;
        }
        temp=temp->next;
    }
    cout<<data<<" is not present in the list";
    return NULL;
}

void CLL:: append(int data){
    if(!last){
        insertAtbegin(data);
        return;
    }
    node *ptr=new node;
    ptr->item=data;
    ptr->next=last->next;
    last->next=ptr;
    last=ptr;
    return;
}

void CLL::traverse(){
    if(!last){
        cout<<"list is empty.";
        return;
    }
    node *temp=last->next;
    while(true){
        cout<<temp->item<<", ";
        if(temp->next==last->next)
            break;
        temp=temp->next;
    }
    return;

}

void CLL::insertAtbegin(int data)
{
    node *ptr = new node;
    if (!last)
    {
        ptr->item = data;
        ptr->next = ptr;
        last = ptr;
        return;
    }
    ptr->item = data;
    ptr->next = last->next;
    last->next = ptr;
    return;
}

CLL::CLL()
{
    last = nullptr;
}

int main()
{
    CLL ar;
    
    // ar.append(152);
    // ar.append(896);
    // ar.insertAtbegin(5);
    // ar.insertAtbegin(87);
    // ar.insertAtbegin(8506);
    // ar.insertAtbegin(1063);
    // ar.insertAtbegin(10369);
    // ar.search(50);
    // ar.search(1063);
    // ar.insertAfter_specific_node(ar.search(50),1485);
    // ar.traverse();
    // ar.deleteLastnode();
    // ar.traverse();
    // ar.deleteLastnode();
    // ar.deleteFirstnode();
    // ar.deleteFirstnode();
    // ar.deleteSpecificnode(ar.search(5));
    // cout<<"\n";
    // ar.traverse();

}