// from server: 52% by atomic.potato
struct Base {
    int f(int);
};

struct Inner {
    char pad0[4];
    void* p4;
    int v8;
    int vc;
    int v10;
};

struct S {
    char pad0[0x28];
    void* p28;
    void* p2c;
    int v30;
    int v34;
    int v38;
    S(int*);
};

extern "C" void __stdcall sub_4017b0(int*);

S::S(int* a) {
    sub_4017b0(a);
    *(void**)this = (void*)0x9a1e2c;
    *(void**)((char*)this + 0x28) = (void*)0x99fdd8;
    Inner* in;
    if (a) {
        in = (Inner*)((char*)a + 0x28);
    } else {
        in = 0;
    }
    void* q = in->p4;
    *(void**)((char*)this + 0x2c) = q;
    if (q) {
        (*(void (__stdcall**)(void*))(*(int*)q + 0xc))(q);
    }
    *(int*)((char*)this + 0x30) = in->v8;
    *(int*)((char*)this + 0x34) = in->vc;
    *(int*)((char*)this + 0x38) = in->v10;
    *(void**)this = (void*)0x9a20a4;
    *(void**)((char*)this + 0x28) = (void*)0x9a209c;
}
