// from server: 52% by atomic.potato
struct Inner {
    char pad[0xacc];
    void* p;
};

struct Outer {
    char pad[0xc];
    Inner* p;
};

struct Result {
    char pad[0x20];
    char flag;
};

extern "C" void* __cdecl operator_new(unsigned int);

struct InitArg {
    void* p;
};

struct Tool {
    Result* create();
};

Result* Tool::create() {
    Result* r = (Result*)operator_new(0x24);
    if (r) {
        Outer* o = (Outer*)this;
        void* arg = o->p->p;
        void (__thiscall *init)(Result*, void*) = (void (__thiscall *)(Result*, void*))0x78be20;
        init(r, arg);
        r->flag = 0;
        *(void**)r = (void*)0xa97bcc;
        *(void**)((char*)r + 4) = (void*)0xa97ba4;
        return r;
    }
    return 0;
}
