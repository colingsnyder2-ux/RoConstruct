// from server: 66% by Intel
struct Workspace {
    void* vftable;
    int field_4;
    int field_8;
    int field_C;
    int field_10;

    void sub_57C6C0();

    void sub_57C6F0();
};

extern "C" void __cdecl sub_62FC62(int);

void Workspace::sub_57C6C0() {
    vftable = (void*)0x7AB754;
    int* ptr = &field_8;
    if (*ptr) {
        sub_62FC62(*ptr);
    }
    *ptr = 0;
    field_C = 0;
    field_10 = 0;
}

void Workspace::sub_57C6F0() {
    vftable = (void*)0x7AB764;
    int* ptr = &field_8;
    if (*ptr) {
        sub_62FC62(*ptr);
    }
    *ptr = 0;
    field_C = 0;
    field_10 = 0;
}
