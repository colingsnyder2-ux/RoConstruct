// from server: 100% by atomic.potato
struct BoundPropGetSet {
    void* vtable0;
    void* vtable4;
    char pad[8];
    void* vtable10;
    void* vtable14;
    char pad2[0x14];
    void* vtable2c;
    char pad3[0x14];
    void* vtable44;
    char pad4[0x14];
    void* vtable5c;
    char pad5[0x14];
    void* vtable74;
    char pad6[0x14];
    void* vtable8c;
    char pad7[0x58];
    void* vtablee8;
    void* vtablef0;
    BoundPropGetSet(void* arg);
};

struct Base {
    void init(void* arg);
};

BoundPropGetSet::BoundPropGetSet(void* arg) {
    ((Base*)this)->init(arg);
    *(void**)this = (void*)0x7bea04;
    *(void**)((char*)this + 4) = (void*)0x7be9fc;
    *(void**)((char*)this + 0x10) = (void*)0x7be9f4;
    *(void**)((char*)this + 0x14) = (void*)0x7be9e4;
    *(void**)((char*)this + 0x2c) = (void*)0x7be9d4;
    *(void**)((char*)this + 0x44) = (void*)0x7be9c4;
    *(void**)((char*)this + 0x5c) = (void*)0x7be9b4;
    *(void**)((char*)this + 0x74) = (void*)0x7be9a4;
    *(void**)((char*)this + 0x8c) = (void*)0x7be994;
    *(void**)((char*)this + 0xe8) = (void*)0x7be97c;
    *(void**)((char*)this + 0xf0) = (void*)0x7be970;
}
