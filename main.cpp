#include<iostream>
using namespace std;

typedef struct element {
    int info;
    struct element *next;
    struct element *prev;
} termen;

class doublelist {
    private :
        int length = 0;
        termen *start,*current,*finalist;
        bool isempty() {return length == 0;}
    public :
        doublelist() { length=0; }

        int showlength() {int value=length;cout<<endl<<value;}

        int printLIST(int direction){
            if (!isempty()) {
                element *carrier;
                if(direction) {
                    carrier=start;
                    while (carrier!=NULL) {
                        cout<<carrier->info<<" ";
                        carrier=carrier->next;
                    }
                } else {
                    carrier=finalist;
                    while (carrier!=NULL) {
                        cout<<carrier->info<<" ";
                        carrier=carrier->prev;
                    }
                }
                cout<<endl;
                return 1;
            }
            return 0;
        }

        int addRight(int value) {
            if (length == 0) {
                length=1;
                element *new_one=new element;
                new_one->next=new_one->prev=NULL;
                new_one->info=value;
                start = finalist = current = new_one;
            } else if(current == finalist) {
                element *new_one=new element;
                new_one->info=value;
                new_one->next=NULL;
                new_one->prev=finalist;
                finalist->next = new_one;
                finalist=new_one;
                current=new_one;
                length++;
            } else {
                element *new_one=new element;
                new_one->info=value;
                new_one->next=current->next;
                new_one->prev=current;
                current->next = new_one;
                current->next->prev = new_one;
                current=new_one;
                length++;
            }
            return true;
        }

        int addLeft(int value) {
            if (length == 0) {
                length=1;
                element *new_one=new element;
                new_one->next=new_one->prev=NULL;
                new_one->info=value;
                start = finalist = current = new_one;
            } else if(current == start) {
                length++;
                element *new_one = new element;
                new_one->info=value;
                new_one->next=start;
                new_one->prev=NULL;
                start->next = new_one;
                finalist=new_one;
                current=new_one;
            }
            element *new_one=new element;
            new_one->info=value;
            new_one->next=NULL;
            new_one->prev=finalist;
            finalist->next = new_one;
            finalist=new_one;
            current=new_one;
            length++;
            return true;
        }
    protected :
} somelist;

int main() {
    for(int i=1;i<=10;i++)
        somelist.addLeft(i);
    somelist.printLIST(1); // 1 2 3 4 5 6 7 8 9 10
    somelist.printLIST(0); // 10 9 8 7 6 5 4 3 2 1
}
