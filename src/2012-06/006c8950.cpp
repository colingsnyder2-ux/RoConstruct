// from server: 23% by Intel




struct Node {
    Node* next;
};

struct Trie {
    Node* head;
    Node* allocateNode();
    Node* insert(void* key);
};

extern "C" void __stdcall __security_cookie_check(int);

Node* Trie::allocateNode() {
    return 0;
}

Node* Trie::insert(void* key) {
    __security_cookie_check(0xABA301);
    Node* current = head;
    Node* newNode = 0;
    if (current) {
        newNode = current;
        head = current->next;
    } else {
        newNode = allocateNode();
    }
    if (!newNode) {
        return 0;
    }
    newNode->next = static_cast<Node*>(key);
    return newNode;
}
