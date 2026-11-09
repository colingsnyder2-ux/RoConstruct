// from server: 100% by king_originala
extern void* __cdecl allocate(unsigned int);
extern void* __cdecl getType();

struct Holder;

struct HolderTable {
    void* (__thiscall* destroy)(Holder*, unsigned int);
};

extern HolderTable holderTable;

struct Holder {
    HolderTable* table;
    float value;
};

struct Result {
    void* type;
    Holder* holder;
};

struct S {
    char padding[56];
    float (__thiscall* getter)(void*);
    int adjustment;

    void evaluate(void* object, Result* result);
};

void S::evaluate(void* object, Result* result)
{
    float value = getter(static_cast<char*>(object) + adjustment);
    result->type = getType();
    Holder*& destination = result->holder;

    Holder* p = static_cast<Holder*>(allocate(8));
    if (p) {
        p->table = &holderTable;
        p->value = value;
    } else {
        p = 0;
    }

    Holder* old = p;
    if (&p != &destination) {
        old = destination;
        destination = p;
    }

    if (old)
        old->table->destroy(old, 1);
}
