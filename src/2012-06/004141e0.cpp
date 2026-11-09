// from server: 33% by atomic.potato
extern "C" void* __cdecl sub_98211A(unsigned int size);

struct Inner {
    void init();
    void assign(void* a, void* b);
};

struct AuthoringSettings {
    void* vtable0;
    void* vtable4;
    char pad[0x10];
    void* vtable18;
    void* vtable1c;
    void* construct(void* a, void* b);
};

void Inner::init() {
    sub_98211A(0);
}

void* AuthoringSettings::construct(void* a, void* b) {
    Inner* mem = (Inner*)sub_98211A(0x80);
    Inner* obj = mem;
    if (obj) {
        obj->init();
        *(void**)((char*)obj + 0) = (void*)0xb44cd4;
        *(void**)((char*)obj + 4) = (void*)0xb44ccc;
        *(void**)((char*)obj + 0x18) = (void*)0xb44cc0;
        *(void**)((char*)obj + 0x1c) = (void*)0xb44cb4;
    } else {
        obj = 0;
    }
    ((Inner*)this)->assign(obj, a);
    return this;
}
