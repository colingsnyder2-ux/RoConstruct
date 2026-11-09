// from server: 93% by atomic.potato
struct S {
    void* field0;
    void* f();
};

extern "C" void* __cdecl sub_00401610(const char*, const char*);
extern "C" void* __cdecl sub_00592ce0();
extern "C" void* __cdecl sub_005c0370();
extern "C" void* __cdecl sub_00401c90(void*);
extern "C" void* __cdecl sub_0058d8f0(void*);

void* S::f() {
    field0 = (void*)0xa8f6fc;
    void* v;
    if (*(int*)0xaad380 == 0) {
        v = sub_00592ce0();
    } else {
        sub_00401610((const char*)0x5c1420, (const char*)0xcbe614);
        v = sub_005c0370();
    }
    void* p = sub_00401c90(&v);
    void* q = sub_0058d8f0(p);
    *(void**)q = this;
    *(int*)0xcca214 = 0x29a;
    return this;
}
