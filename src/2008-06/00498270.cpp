// from server: 100% by king_originala
extern void (__thiscall *destroy_string)(void *);

struct String {
    char storage[28];
    ~String();
};

__forceinline String::~String()
{
    destroy_string(this);
}

struct Value {
    unsigned int tag;
    String first;
    String second;
};

struct Node {
    Node *next;
    Node *previous;
    Value value;
};

struct S {
    char padding[20];
    Node *head;
    unsigned int count;
    void clear();
};

void S::clear()
{
    Node *current = head->next;
    head->next = head;
    head->previous = head;
    count = 0;

    while (current != head) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}
