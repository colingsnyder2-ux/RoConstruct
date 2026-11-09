// from server: 50% by Intel
struct Assembly {
    void ctor();
};

extern "C" void G1_func_00961540();
extern "C" void G1_func_007219d0();

void Assembly::ctor() {
    int* vtable_ptr = (int*)0x00bc1d28;
    int* vtable_ptr2 = (int*)0x00bc1d00;
    int* vtable_ptr3 = (int*)0x007e4ad0;

    *(int*)((char*)this + 4) = 0;
    G1_func_00961540();
    *(int*)((char*)this + 0x34) = 0;
    *(int*)((char*)this + 0x38) = 0;
    G1_func_007219d0();
    G1_func_007219d0();
    *(int*)((char*)this + 0x6c) = -1;
    *(int*)((char*)this + 0x70) = -1;
    *(int*)((char*)this + 0x68) = 0;
    *(int*)((char*)this + 0x74) = 7;
    *(int*)((char*)this + 0x88) = (int)vtable_ptr3;
    *(int*)((char*)this + 0x8c) = 0;
    *(char*)((char*)this + 0x7c) = 1;
    *(int*)((char*)this + 0x80) = (int)this;
    *(int*)this = (int)vtable_ptr;
    *(int*)((char*)this + 8) = (int)vtable_ptr2;
    *(char*)((char*)this + 0x3c) = 0;
    *(char*)((char*)this + 0x3d) = 0;
    *(int*)((char*)this + 0x40) = 0;
    *(int*)((char*)this + 0x44) = 0;
}
