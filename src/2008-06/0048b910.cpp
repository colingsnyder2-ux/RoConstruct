// from server: 100% by king_originala
struct Dispatch;

struct DispatchTable {
    void *reserved[3];
    int (__thiscall *invoke)(Dispatch *, void *, int *);
};

struct Dispatch {
    DispatchTable *table;
};

extern Dispatch *dispatcher;

struct S {
    char reserved[20];
    int f(int value);
};

int S::f(int value)
{
    void *object = this ? (void *)(reserved + 20) : 0;
    return dispatcher->table->invoke(dispatcher, object, &value);
}
