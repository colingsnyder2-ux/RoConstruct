// from server: 75% by colin
struct EnumDesc {
    char pad[0x24];
    unsigned int count;
    char pad2[0x88 - 0x28];
    void** items;
};

struct RefCounted {
    virtual void unknown0();
    virtual void unknown1();
    virtual void release();
};

extern "C" void* __cdecl operator_new(unsigned int size);

struct Holder {
    void* vtable;
    void* value;
};

struct S {
    char pad[0x24];
    unsigned int count;
    char pad2[0x88 - 0x28];
    void** items;

    bool get(unsigned int index, void** out, Holder* dst);
};

bool S::get(unsigned int index, void** out, Holder* dst)
{
    void* value;
    bool found;
    if (index < count) {
        value = items[index];
        found = true;
    } else {
        value = *out;
        found = false;
    }

    Holder* h = (Holder*)operator_new(8);
    if (h) {
        h->vtable = (void*)0xa88e5c;
        h->value = value;
    } else {
        h = 0;
    }

    Holder* old = dst;
    Holder* tmp = h;
    if (&tmp != &dst) {
        old = (Holder*)dst->value;
        dst->value = (void*)h;
    }

    if (old) {
        void** vt = (void**)old->vtable;
        void (*fn)(RefCounted*, int) = (void (*)(RefCounted*, int))vt[0];
        fn((RefCounted*)old, 1);
    }

    return found;
}
