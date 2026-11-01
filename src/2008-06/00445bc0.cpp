// from server: 100% by king_originala
struct Type {
    unsigned char data[16];
    Type(const char *, const void *);
    ~Type();
};

const Type &singleton();
void *__cdecl allocate(unsigned int);

struct Object;

struct Table {
    void (__thiscall *destroy)(Object *, unsigned int);
};

extern Table objectTable;

struct Object {
    Table *table;
    int value;
};

struct S {
    const Type *type;
    Object *owned;
    S *assign(int *value);
};

S *S::assign(int *value)
{
    type = &singleton();
    Object **slot = &owned;

    Object *replacement = static_cast<Object *>(allocate(8));
    if (replacement) {
        replacement->table = &objectTable;
        replacement->value = *value;
    } else {
        replacement = 0;
    }

    Object *old = replacement;
    if (static_cast<void *>(&value) != static_cast<void *>(slot)) {
        old = *slot;
        *slot = replacement;
    }

    if (old)
        old->table->destroy(old, 1);

    return this;
}
