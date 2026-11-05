// from server: 100% by king_originala
struct String;
extern void (__thiscall *stringDestroy)(String *);
extern void __cdecl operator delete(void *);

struct String {
    char storage[32];
    ~String();
};

__forceinline String::~String() {
    stringDestroy(this);
}

struct Tail {
    ~Tail();
};

struct Value {
    String text;
    Tail tail;
    ~Value();
};

__forceinline Value::~Value() {
}

struct Node {
    Node *next;
    Node *previous;
    Value value;
};

struct S {
    char reserved[20];
    Node *head;
    unsigned int count;

    void clear();
};

void S::clear() {
    Node *current = head->next;
    head->next = head;
    head->previous = head;
    count = 0;

    while (current != head) {
        Node *next = current->next;
        current->value.~Value();
        operator delete(current);
        current = next;
    }
}
