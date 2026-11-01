// from server: 100% by king_originala
struct Visitor {
    char padding[12];
    unsigned char active;
    unsigned char flag;
    char padding2[2];
    int value;
};

typedef void (__thiscall *AcceptVisitor)(void*, Visitor*, int);
extern AcceptVisitor acceptVisitor;

struct S {
    char padding[0x8bec];
    Visitor* visitor;

    void f(void* collection, int unused, unsigned char flag, int value);
};

void S::f(void* collection, int unused, unsigned char flag, int value)
{
    visitor->active = 1;
    visitor->flag = flag;
    visitor->value = value;
    acceptVisitor(collection, visitor, 2);
    visitor->active = 0;
}
