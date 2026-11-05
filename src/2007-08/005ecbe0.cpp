// from server: 100% by colin
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
    *(void**)this = (void*)0x7be924;
    *(void**)((char*)this + 4) = (void*)0x7be91c;
    *(void**)((char*)this + 0x10) = (void*)0x7be914;
    *(void**)((char*)this + 0x14) = (void*)0x7be904;
    *(void**)((char*)this + 0x2c) = (void*)0x7be8f4;
    *(void**)((char*)this + 0x44) = (void*)0x7be8e4;
    *(void**)((char*)this + 0x5c) = (void*)0x7be8d4;
    *(void**)((char*)this + 0x74) = (void*)0x7be8c4;
    *(void**)((char*)this + 0x8c) = (void*)0x7be8b4;
    *(void**)((char*)this + 0xe8) = (void*)0x7be89c;
    *(void**)((char*)this + 0xf0) = (void*)0x7be890;
}
