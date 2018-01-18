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
    public :
        doublelist() {length=0;}

        void showlength() {
            cout<<endl<<length<<endl;
        }

        void searchvalue(int val) {
            element * carrier = start;
            while(carrier != NULL) {
                if(carrier->info == val) {
                    current = carrier;
                    break;
                } else carrier = carrier->next;
            }
        }

        int printLIST(int direction){
            if (length != 0) {
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
                start->prev = new_one;
                start = new_one;
                current = new_one;
            } else {
                element *new_one=new element;
                new_one->info=value;
                new_one->next=NULL;
                new_one->prev=finalist;
                finalist->next = new_one;
                finalist=new_one;
                current=new_one;
                length++;
            }
            return true;
        }
        
        int delRight(){
            if (length==0) {
                return NULL;
            }else if(length == 1) {
                int old_value = current->info;
                delete current;
                start=current=finalist=NULL;
                length=0;
                return old_value;
            } else if(current == finalist) {
                int old_value = finalist->info;
                finalist=finalist->prev;
                delete finalist->next;
                finalist->next = NULL;
                current=finalist;
                length--;
                return old_value;
            } else {
                int old_value = current->next->info;
                if(current->next == finalist) {
                    delete current->next;
                    current->next = NULL;
                } else {
                    element * copy = current->next;
                    current->next = current->next->next;
                    delete copy;
                    current->next->prev = current;
                }
                length--;
                return old_value;
            }
        }

        int delLeft(){
            if (length==0) {
                return NULL;
            } else if(length == 1) {
                int old_value = start->info;
                delete start;
                start=current=finalist=NULL;
                length=0;
                return old_value;
            } else if(current == start) {
                int old_value = start->info;
                start=start->next;
                delete start->prev;
                start->prev = NULL;
                current=start;
                length--;
                return old_value;
            } else {
                int old_value = current->prev->info;
                if(current->prev == start) {
                    delete current->prev;
                    current->prev = NULL;
                } else {
                    element * copy = current->prev;
                    current->prev = current->prev->prev;
                    current->prev->next = current;
                    delete copy;
                }
                return old_value;
            }
        }
    protected :
} somelist;

int main() {
    for(int i=1;i<=10;i++){
        somelist.addLeft(i);
        somelist.printLIST(1);
    }
    somelist.searchvalue(5);
    somelist.delRight();
    somelist.printLIST(1);
    somelist.searchvalue(7);
    somelist.delLeft();
    somelist.delLeft();
    somelist.printLIST(1);
    somelist.printLIST(0);
}
