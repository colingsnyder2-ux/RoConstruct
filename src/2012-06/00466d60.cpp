// from server: 93% by atomic.potato
struct EnumDesc {
    void* vtable;
    int value;
    EnumDesc(int*);
};

extern "C" void __cdecl sub_9831F5(void*);

EnumDesc::EnumDesc(int* p) {
    static int init_flag;
    if (!(init_flag & 1)) {
        init_flag |= 1;
        *(void**)0xe18dec = (void*)0xd6bd8c;
        *(void**)0xe18df4 = (void*)0x5708d0;
        *(void**)0xe18df0 = (void*)0x59a790;
        sub_9831F5((void*)0xb12330);
    }
    if (*(void**)this == (void*)0xe18dec) {
        this->value = *p;
        return;
    }
    if (*(void**)this) {
        ((void (__thiscall*)(void*, int*))*(void**)(*(int*)this + 4))(this, &this->value);
        *(void**)this = 0;
    }
    if (&this->value) {
        this->value = *p;
    }
    *(void**)this = (void*)0xe18dec;
}
