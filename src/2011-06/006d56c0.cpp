// from server: 100% by atomic.potato
struct ManualGlue {
    char pad0[0x90];
    void* field90;
    void* init(void*);
};

struct Base {
    void base_init(void*);
};

void* ManualGlue::init(void* a) {
    ((Base*)this)->base_init(a);
    *(void**)this = (void*)0xaa6a4c;
    *(void**)((char*)this + 4) = (void*)0xaa6a44;
    *(void**)((char*)this + 0x18) = (void*)0xaa6a38;
    *(void**)((char*)this + 0x1c) = (void*)0xaa6a2c;
    *(void**)((char*)this + 0x90) = (void*)0xaa6a04;
    return this;
}
