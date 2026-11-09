// from server: 81% by tester
extern "C" void _invalid_parameter_noinfo();

struct Item {
    virtual void f();
};

struct EnumDesc {
    char pad[0x2c];
    unsigned int count;
    char pad2[0xc8 - 0x30];
    Item** begin;
    Item** end;
    bool getItem(unsigned int index, Item** out);
};

extern "C" void* __cdecl operator_new(unsigned int);
void* __cdecl sub_7a79a0(unsigned int size);

struct Holder {
    void* vtable;
    unsigned int value;
};

bool EnumDesc::getItem(unsigned int index, Item** out)
{
    Item* item;
    bool found;
    if (index < count) {
        unsigned int n = (unsigned int)(((char*)end - (char*)begin) >> 2);
        if (index >= n)
            _invalid_parameter_noinfo();
        item = begin[index];
        found = true;
    } else {
        item = 0;
        found = false;
    }
    Holder* h = (Holder*)sub_7a79a0(8);
    if (h) {
        h->vtable = (void*)0xa2aed4;
        h->value = (unsigned int)item;
    } else {
        h = 0;
    }
    Item* old = *out;
    if (out != (Item**)&out) {
        old = *out;
        *out = (Item*)h;
    }
    if (old) {
        void** vt = *(void***)old;
        void (*fn)(Item*, int) = (void (*)(Item*, int))vt[0];
        fn(old, 1);
    }
    return found;
}
