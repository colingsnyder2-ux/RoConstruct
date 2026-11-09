// from server: 87% by atomic.potato
struct S {
    char pad0[0x94];
    void* field94;
    char pad1[0xbc - 0x94 - 4];
    int fieldBC;
    void f();
};

extern "C" void __cdecl sub_401610(void*, void*);
extern "C" void* __cdecl sub_809F68(void*, void*);
extern "C" void __cdecl sub_5A3740(void*);

void S::f() {
    if (field94 != 0) {
        sub_401610((void*)0x59cab0, (void*)0xcbd434);
        int idx = fieldBC * 0x7c + 0xcbc200;
        void* r = sub_809F68((void*)idx, field94);
        sub_5A3740(r);
    }
}
