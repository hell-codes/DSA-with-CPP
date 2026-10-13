/*
Question_8:
Implement LRU Cache using a Doubly Linked List.
Most recently used page is at front and
least recently used page is at rear.
*/

#include <iostream>
using namespace std;

typedef struct QNode{
    int pageNumber;
    QNode *prev,*next;
}QNode;
typedef struct Queue{
    int size;
    QNode *front,*rear;
}Queue;
QNode* newQNode(unsigned pageNumber){
    QNode *n=new QNode{(int)pageNumber,NULL,NULL};
    return n;
}
Queue* createQueue(int numberOfFrames){
    Queue *q=new Queue{numberOfFrames,NULL,NULL};
    return q;
}
void refer(Queue *q,int x){
    QNode *p=q->front;

    while(p){
        if(p->pageNumber==x){
            if(p!=q->front){
                if(p==q->rear) q->rear=p->prev;
                if(p->prev) p->prev->next=p->next;
                if(p->next) p->next->prev=p->prev;

                p->prev=NULL;
                p->next=q->front;
                q->front->prev=p;
                q->front=p;
            }
            return;
        }
        p=p->next;
    }
    if(q->size==0) return;

    if(q->front && q->rear){
        int c=0;
        p=q->front;
        while(p){ c++; p=p->next; }

        if(c==q->size){
            p=q->rear;
            q->rear=p->prev;
            if(q->rear) q->rear->next=NULL;
            else q->front=NULL;
            delete p;
        }
    }
    p=newQNode(x);
    p->next=q->front;

    if(q->front) q->front->prev=p;
    else q->rear=p;
    q->front=p;
}
int main(){
    int n,m,x;
    cin>>n>>m;

    Queue *q=createQueue(m);
    while(n--){
        cin>>x;
        refer(q,x);
    }
    for(QNode *p=q->front;p;p=p->next)
        cout<<p->pageNumber<<" ";
    return 0;
}
