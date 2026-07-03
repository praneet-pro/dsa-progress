class MyLinkedList {
private:
    struct Node {
        int val;
        struct Node* next;
        struct Node* prev;

        Node(int x) : val(x), next(nullptr), prev(nullptr) {}
    };

    int size;
    Node* dummyHead;
    Node* dummyTail;

public:
    MyLinkedList() {
        size = 0;
        dummyHead = new Node(-1);
        dummyTail = new Node(-1);

        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    
    int get(int index) {
        if(index >= size || index < 0) return -1;

        Node* temp = dummyHead->next;

        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newHead = new Node(val);
        Node* nextNode = dummyHead->next;

        newHead->next = nextNode;
        nextNode->prev = newHead;
        dummyHead->next = newHead;
        newHead->prev = dummyHead;

        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        Node* prevNode = dummyTail->prev;

        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = dummyTail;
        dummyTail->prev = newNode;

        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size || index < 0) return;

        Node* newNode = new Node(val);
        Node* temp = dummyHead;

        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        
        Node* prevNode = temp;
        Node* nextNode = temp->next;

        prevNode->next = newNode;
        newNode->prev = prevNode;

        newNode->next = nextNode;
        nextNode->prev = newNode;

        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size || index < 0) return;

        Node* temp = dummyHead;

        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        
        Node* prevNode = temp;
        Node* targetNode = temp->next;
        Node* nextNode = temp->next->next;

        nextNode->prev = prevNode;
        prevNode->next = nextNode;

        delete targetNode;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */