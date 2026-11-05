// from server: 100% by colin
struct Holder {
    void* vtable;
    float value;
};

struct Any {
    void* makeHolder();
};

extern "C" void* __cdecl operator_new(unsigned int size);

void* Any::makeHolder() {
    Holder* h = (Holder*)operator_new(8);
    if (h) {
        h->vtable = (void*)0x78a5ec;
        h->value = *(float*)((char*)this + 4);
        return h;
    }
    return 0;
}
