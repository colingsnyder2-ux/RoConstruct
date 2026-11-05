// from server: 30% by atomic.potato
extern "C" void __stdcall sub_401610(int, int);
extern "C" void* __cdecl sub_5d08a0();
extern "C" void* __cdecl sub_5cad30();
extern "C" void __cdecl sub_5e4090();
extern "C" void* __cdecl sub_80a05e(unsigned int);

struct S {
    char pad0[0x1c];
    void* field1c;
    void* field20;
    void* method(int, int, int, int, int);
};

void* S::method(int a, int b, int c, int d, int e) {
    sub_401610(0xcca328, 0x5d0900);
    void* p = sub_5d08a0();
    sub_5cad30();
    sub_5e4090();
    field1c = p;
    *(void**)this = (void*)0xab1e94;
    void* q = sub_80a05e(0xc);
    if (q) {
        *(void**)q = (void*)0xab19c4;
        *(int*)((char*)q + 4) = c;
        *(int*)((char*)q + 8) = d;
    } else {
        q = 0;
    }
    field20 = q;
    return this;
}
