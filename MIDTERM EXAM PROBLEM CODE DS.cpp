#include <iostream>
using namespace std;

class Node
{
  public:
    int PatientID;
    Node *prev;
    Node *next;
    Node(int pid) : PatientID(pid), prev(nullptr), next(nullptr) {}

   Node* head;
   Node* tail;
   Node() : head(nullptr), tail(nullptr) {}

   void insertAtBeginning(int pid)
   {
       Node* node_new = new Node(pid);
       if (!head) {
           head = tail = node_new;
       } else {
           node_new->next = head;
           head->prev = node_new;
           head = node_new;
       }

}

    void insertAtEnd(int pid)
    {
        Node* node_new = new Node(pid);
        if (!tail) {
            head = tail = node_new;
        } else {
            tail->next = node_new;
            node_new->prev = tail;
            tail = node_new;
        }
    }

    void insertAtPosition(int pid, int pos)
    {
        if (pos <= 1 || !head) {
            insertAtBeginning(pid);
            return;
        }

        Node* current = head;
        int index = 1;
        while (current && index < pos - 1) {
            current = current->next;
            index++;
        }
        
        if (!current || !current->next) {
            insertAtEnd(pid);


        } else {
            Node* node_new = new Node(pid);
            node_new->next = current->next;
            node_new->prev = current;
            current->next->prev = node_new;
            current->next = node_new;
        }
        
    }

    void deleteFromBeginning()
    {
        if (!head) return;
        Node* toDel = head;
        if (head==tail)
        {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete toDel;
    } 
       
    void travforward()
    {
        Node* current = head;
        while (current) {
            cout << current->PatientID << " ";
            current = current->next;
        }
        cout << endl;

    }

    void travbackward()
    {
        Node* current = tail;
        while (current) {
            cout << current->PatientID << " ";
            current = current->prev;
        }
        cout << endl;
    }




};


int main(){
    Node list;
    list.insertAtEnd(101);
    list.insertAtEnd(102);
    list.insertAtBeginning(200); 
    list.insertAtPosition(150, 2); 
    list.deleteFromBeginning();
    list.insertAtEnd(300);

    if (list.head) {
        cout << "(a) Head patient ID: " << list.head->PatientID << endl;
    } else {
        cout << "(a) Head patient ID: (none)" << endl;
    }

    if (list.tail) {
        cout << "(b) Tail patient ID: " << list.tail->PatientID << endl;
    } else {
        cout << "(b) Tail patient ID: (none)" << endl;
    }

    cout << "(c) Forward (head → tail): ";
    list.travforward();

    cout << "(d) Backward (tail → head): ";
    list.travbackward();

    return 0;

}
