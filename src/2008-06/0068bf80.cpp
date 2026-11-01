// from server: 100% by king_originala
typedef bool (__thiscall *BoolMethod)(void*);
extern BoolMethod getShadowsEnabled;

struct Item {
    char padding[4];
    unsigned short count;
};

struct S {
    BoolMethod* vtable;
    char padding0[0xb8];
    void* viewport;
    char padding1[0x8994];
    int mode;
    char padding2[0x129];
    bool enabled;
    bool disabled;

    bool f(const Item* item);
};

bool S::f(const Item* item)
{
    if (!disabled && getShadowsEnabled(viewport)) {
        if ((vtable[188](this) && mode == 2) ||
            mode == 1 || enabled) {
            if (item->count > 0)
                return false;
        }
    }
    return true;
}
