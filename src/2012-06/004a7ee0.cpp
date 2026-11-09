// from server: 55% by Intel
struct DxUserInput {
    char pad0[0x1c8];
    int field_1c8;
    char pad1[0x1e1 - 0x1c8 - 4];
    unsigned char field_1e1;
    unsigned char field_1e3;
    void f();
};

void DxUserInput::f()
{
    if (field_1c8 != 0) {
        if (field_1e3 == field_1e1) {
            return;
        }
        if (field_1e1 != 0) {
            void (*func)() = reinterpret_cast<void(*)()>(*reinterpret_cast<int*>(this));
            func();
        } else {
            void (*func)() = reinterpret_cast<void(*)()>(*reinterpret_cast<int*>(this) + 11);
            func();
        }
    } else {
        field_1e3 = 0;
    }
}
