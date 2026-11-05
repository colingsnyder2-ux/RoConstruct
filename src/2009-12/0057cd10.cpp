// from server: 27% by atomic.potato
extern "C" void* __cdecl sub_7F3860(unsigned int);
extern "C" void __cdecl sub_57C040(void*, void*);

struct Inner {
    char pad0[0x3c];
    void* vtbl3c;
    char pad40[0x28];
    void* vtbl28;
    void* vtbl0;
};

struct Outer {
    char pad0[0x3c];
    Inner inner;
    void* f();
};

void* Outer::f() {
    Inner* p = (Inner*)sub_7F3860(0x40);
    if (p) {
        sub_57C040(p, &this->inner);
        *(void**)((char*)p + 0x3c) = (void*)0x99fd90;
        *(void**)p = (void*)0x9c0d48;
        *(void**)((char*)p + 0x28) = (void*)0x9c0d40;
        *(void**)((char*)p + 0x3c) = (void*)0x9c0d30;
    }
    return p;
}
