// from server: 100% by king_originala
struct Visitor {
    char pad0[12];
    bool flag0;
    bool flag1;
    char pad1[2];
    int value;
};

typedef void (__thiscall *AcceptVisitor)(void *, Visitor *, int);
extern AcceptVisitor acceptVisitor;

struct S {
    char pad0[35820];
    Visitor *visitor;
    void f(void *collection, int mode, bool flag, int value);
};

void S::f(void *collection, int mode, bool flag, int value)
{
    visitor->flag1 = flag;
    visitor->value = value;
    visitor->flag0 = false;
    acceptVisitor(collection, visitor, mode);
}
