// from server: 100% by king_originala
struct Accessor;
struct Holder;

typedef bool (__thiscall *Getter)(Accessor*, void*);
typedef void (__thiscall *Disposer)(Holder*, unsigned int);

struct AccessorTable {
    void* slots[2];
    Getter get;
};

struct Accessor {
    AccessorTable* table;
};

struct HolderTable {
    Disposer dispose;
};

struct Holder {
    HolderTable* table;
    bool value;
};

struct Result {
    void* type;
    Holder* value;
};

extern HolderTable boolHolderTable;
extern void* __cdecl getBoolType();
extern void* __cdecl allocate(unsigned int);

struct S {
    unsigned char padding[24];
    Accessor* accessor;
    void f(void* object, Result* result);
};

void S::f(void* object, Result* result)
{
    bool value = accessor->table->get(accessor, object);
    result->type = getBoolType();
    Holder** destination = &result->value;

    Holder* holder = static_cast<Holder*>(allocate(sizeof(Holder)));
    if (holder) {
        holder->table = &boolHolderTable;
        holder->value = value;
    } else {
        holder = 0;
    }

    object = holder;
    if (&object != reinterpret_cast<void**>(destination)) {
        object = *destination;
        *destination = holder;
    }

    if (object) {
        Holder* old = static_cast<Holder*>(object);
        old->table->dispose(old, 1);
    }
}
