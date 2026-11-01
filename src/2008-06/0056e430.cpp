// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);

extern unsigned int firstType;
extern unsigned int secondType;

struct Value {
    volatile unsigned int type;
    int tag;
    int number;
    unsigned int reserved;
    unsigned int extra1;
    unsigned int extra2;

    void clear();
};

struct Node {
    Node* volatile next;
    volatile unsigned int field4;
    volatile unsigned int field8;
    unsigned int field12;
    Value value;

    Node(unsigned int type);
};

inline Node::Node(unsigned int type)
{
    next = 0;
    field4 = 0;
    field8 = 0;
    value.type = type;
    value.tag = 0;
    value.extra1 = 0;
    value.extra2 = 0;
}

struct List {
    unsigned int field0;
    Node* first;
    Node* last;
};

struct Pair {
    short x;
    short y;
};

struct Accessor;

struct AccessorTable {
    void* unused[2];
    Pair* (__thiscall *get)(Accessor*, Pair*, void*);
};

struct Accessor {
    AccessorTable* table;
};

struct S {
    unsigned char padding[24];
    Accessor* accessor;

    void f(void* object, List* list);
};

void S::f(void* object, List* list)
{
    unsigned int type1 = firstType;
    Node* a = new Node(type1);

    if (!list->last)
        list->first = a;
    else
        list->last->next = a;
    list->last = a;

    unsigned int type2 = secondType;
    Node* b = new Node(type2);

    if (!list->last)
        list->first = b;
    else
        list->last->next = b;
    list->last = b;

    Pair result;
    accessor->table->get(accessor, &result, object);

    int x = result.x;
    Value* value = &a->value;
    value->clear();
    value->number = x;
    value->tag = 5;

    int y = result.y;
    value = &b->value;
    value->clear();
    value->number = y;
    value->tag = 5;
}
