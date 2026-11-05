// from server: 25% by atomic.potato
struct Inner {
    char pad0[0xac];
};

struct Outer {
    char pad0[4];
    void construct(Inner* p, float f);
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __stdcall Inner_ctor(Inner* p, float f);

struct Inner2 {
    void init(float f);
};

void Inner2::init(float f) {
    char* self = (char*)this;
    *(float*)(self + 0x20) = f;
}

struct Base {
    void setup(Inner* p);
};

void Base::setup(Inner* p) {
    char* self = (char*)this;
    *(Inner**)(self + 0x0) = p;
}

struct Holder {
    void assign(Inner* p, int flag);
};

void Holder::assign(Inner* p, int flag) {
    char* self = (char*)this;
    *(Inner**)(self + 0x0) = p;
    *(int*)(self + 0x4) = flag;
}

struct S {
    void __cdecl func(float f);
};

void S::func(float f) {
    Inner* p = 0;
    int flag = 0;
    p = (Inner*)operator_new(0xac);
    if (p) {
        Inner2* q = (Inner2*)p;
        q->init(f);
        *(void**)((char*)p + 0x0) = (void*)0xa72b5c;
        *(void**)((char*)p + 0x4) = (void*)0xa72b50;
        *(void**)((char*)p + 0x18) = (void*)0xa72b44;
        *(void**)((char*)p + 0x1c) = (void*)0xa72b38;
        *(void**)((char*)p + 0x90) = (void*)0xa72b30;
    } else {
        p = 0;
    }
    Holder* h = (Holder*)this;
    h->assign(p, flag);
}
