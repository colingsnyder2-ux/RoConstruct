// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);

struct Node {
    Node* next;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0C;
    void* value;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1C;
    unsigned int field20;
    unsigned int field24;

    Node(void* p);
};

inline Node::Node(void* p)
    : next(0), field04(0), field08(0), value(p),
      field14(0), field20(0), field24(0)
{
}

struct S {
    unsigned int field00;
    Node* head;
    Node* tail;

    void append(void* p);
};

void S::append(void* p)
{
    Node* n = new Node(p);
    if (tail == 0) {
        head = n;
        tail = n;
    } else {
        tail->next = n;
        tail = n;
    }
}
