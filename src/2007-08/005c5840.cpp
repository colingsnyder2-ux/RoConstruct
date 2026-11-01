// from server: 28% by colin
struct lua_exception {
    void* vfptr;          // 0x00
    int field_04;         // 0x04
    int field_08;         // 0x08
    int field_0c;         // 0x0c
    int field_10;         // 0x10
    unsigned char field_14; // 0x14
    void destroy();
};

extern "C" void __stdcall sub_5bd590(int, int);
extern "C" void __stdcall std_exception_dtor(void*);

void lua_exception::destroy() {
    vfptr = (void*)0x7b967c;
    if (field_14 == 0) {
        *(int*)(field_10 + 8) = 0;
        sub_5bd590(field_0c, -2);
    }
    std_exception_dtor(this);
}
