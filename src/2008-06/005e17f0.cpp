// from server: 100% by king_originala
struct Holder;

struct HolderTable {
    void (__thiscall *destroy)(Holder *, unsigned int);
};

struct Holder {
    HolderTable *table;
    unsigned int padding;
    double value;
};

extern HolderTable holderTable;
extern "C" void * __cdecl getType();
extern "C" void * __cdecl allocate(unsigned int);

struct Result {
    void *type;
    Holder *holder;
};

struct Descriptor {
    unsigned char padding[0x38];
    double (__thiscall *getter)(void *);
    int adjustment;

    void evaluate(Holder *object, Result *result);
};

void Descriptor::evaluate(Holder *object, Result *result)
{
    double value = getter((char *)object + adjustment);
    result->type = getType();
    Holder **slot = &result->holder;

    Holder *replacement = (Holder *)allocate(16);
    if (replacement) {
        replacement->table = &holderTable;
        replacement->value = value;
    } else {
        replacement = 0;
    }

    Holder *old = replacement;
    if (&object != slot) {
        old = *slot;
        *slot = replacement;
    }

    if (old)
        old->table->destroy(old, 1);
}
