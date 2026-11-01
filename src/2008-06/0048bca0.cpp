// from server: 100% by king_originala
struct Holder;
typedef void (__thiscall *Destroy)(Holder*, unsigned int);

struct Holder {
    Destroy* table;
    unsigned int value;
};

extern Destroy holderTable[];
extern void* __cdecl getType();
extern void* __cdecl allocate(unsigned int);

struct S {
    void* type;
    Holder* holder;
    S* assign(const unsigned int* value);
};

S* S::assign(const unsigned int* value)
{
    type = getType();
    Holder** destination = &holder;
    Holder* fresh = static_cast<Holder*>(allocate(8));
    if (fresh) {
        fresh->table = holderTable;
        fresh->value = *value;
    } else {
        fresh = 0;
    }

    Holder* previous = fresh;
    if (static_cast<void*>(&value) != static_cast<void*>(destination)) {
        previous = *destination;
        *destination = fresh;
    }
    if (previous)
        previous->table[0](previous, 1);
    return this;
}
