// from server: 100% by king_originala
struct S;

struct InsertResult {
    unsigned long data[3];
};

struct Registry {
    void insert(InsertResult* result, S** value);
};

extern Registry registry;
extern unsigned long table[];

struct S {
    unsigned long* tablePointer;
    S* initialize();
};

S* S::initialize()
{
    InsertResult result;
    S* value;
    tablePointer = table;
    value = this;
    registry.insert(&result, &value);
    return this;
}
