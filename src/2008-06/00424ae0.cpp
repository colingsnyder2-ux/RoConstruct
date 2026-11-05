// from server: 100% by king_originala
struct Owner;

struct Table {
    void* padding[81];
    unsigned int (__thiscall *get)(Owner*, unsigned int, int);
    void* reserved;
    void (__thiscall *set)(Owner*, unsigned int, unsigned int, int);
};

struct Owner {
    Table* table;
};

struct S {
    unsigned char padding0[0x54];
    unsigned char flags;
    unsigned char disabled;
    unsigned char padding1[2];
    Owner* owner;
    unsigned char padding2[0x24];
    unsigned int item;

    void f(int);
};

void S::f(int)
{
    if (disabled) {
        flags &= 0xfd;
        return;
    }

    if (owner->table->get(owner, item, 8) | 0x20) {
        Owner* p = owner;
        flags |= 2;
        if (p->table->get(p, item, 8) | 0x80)
            owner->table->set(owner, item, 0x20, 8);
    }
}
