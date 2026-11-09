// from server: 50% by atomic.potato
struct DropperTool {
    char pad[0xc];
    void* p;
    void* create();
};

struct Init {
    void init(void*);
};

extern "C" void* __cdecl operator_new(unsigned int);

void* DropperTool::create() {
    void* mem = operator_new(0x28);
    if (mem) {
        ((Init*)mem)->init(*(void**)((char*)p + 0xacc));
        *(void**)mem = (void*)0xab9774;
        *(void**)((char*)mem + 4) = (void*)0xab9748;
    }
    return mem;
}
