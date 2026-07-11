class LRUCache {

    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };

private:
    int cap;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    void addNode(Node* newNode) {
        Node* currMRU = head->next;

        newNode->next = currMRU;
        newNode->prev = head;

        head->next = newNode;
        currMRU->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.count(key)) {
            Node* resNode = mp[key];

            deleteNode(resNode);
            addNode(resNode);

            return resNode->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // if the key already exits
        if(mp.count(key)) {
            Node* resNode = mp[key];
            resNode->val = value;
            deleteNode(resNode);
            addNode(resNode);
            return;
        }

        // if the cpacity of the map is full
        if(cap == mp.size()) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */