// from server: 41% by Intel
struct SignalSlotCallable {
    int vtable;
    int field_4;
    int field_8;
    int field_C;

    int func(int a1, int a2);
};

extern "C" bool __stdcall func_00880f30();

int SignalSlotCallable::func(int a1, int a2) {
    int v4;
    int v5;
    int v6;
    int v7;

    v6 = a1;
    v7 = a2;
    v4 = 0;
    v5 = 0;
    if (func_00880f30()) {
        vtable = 0;
        return 0;
    }
    int* ptr = &field_8;
    if (ptr) {
        *ptr = v4;
        *(ptr + 1) = v5;
    }
    vtable = 0xD70B2C;
    return 0;
}
