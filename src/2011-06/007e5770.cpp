// from server: 55% by atomic.potato
struct AdvMoveToolBase {
    char pad0[0x1c];
    int field_1c;
    char pad20[0x44];
    int field_64;
    char pad68[0x1c];
    unsigned char field_84;
    void sub_75dc80();
    void sub_75c020(int);
    void sub_611d00(const char*, int);
    void virtual_call_0();
    void virtual_call_30();
    void func(int);
};

void AdvMoveToolBase::func(int arg) {
    if (field_84 != 0) {
        sub_75dc80();
        field_64 = 0;
        virtual_call_0();
        char* p = (char*)this + 4;
        if (*(int*)(p + 0x18) < 0x10) {
            p = p + 4;
        } else {
            p = *(char**)(p + 4);
        }
        sub_611d00(p, field_1c);
        field_84 = 0;
    }
    virtual_call_30();
    sub_75c020(arg);
}
