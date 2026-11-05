// from server: 20% by atomic.potato
struct Base {
    void* vfptr;
    void init();
};

struct Pool {
    char pad0[0xc];
    void* field_c;
    char pad10[0x10];
    void* field_20;
    void* field_24;
    void* field_28;
    void* field_2c;
    void* field_30;
};

extern "C" void* __cdecl sub_7a79a0(int);

struct Outer {
    char pad0[0xc];
    Pool pool;
    void ctor();
};

void Outer::ctor() {
    Base* b = (Base*)this;
    b->init();
    *(void**)this = (void*)0xa41238;
    void* p = sub_7a79a0(4);
    if (p != 0) {
        *(void**)p = (void*)((char*)this + 0xc);
    } else {
        p = 0;
    }
    *(void**)((char*)this + 0xc) = p;
    *(void**)((char*)this + 0x1c) = 0;
    *(void**)((char*)this + 0x20) = 0;
    *(void**)((char*)this + 0x24) = 0;
    *(void**)((char*)this + 0x28) = 0;
    *(void**)((char*)this + 0x2c) = 0;
    *(void**)((char*)this + 0x30) = 0;
}
