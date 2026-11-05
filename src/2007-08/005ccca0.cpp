// from server: 100% by colin
struct IPipelined {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    bool method18(int);
};

extern "C" void __cdecl sub_5B47A0(int, int);

bool IPipelined::method18(int arg) {
    bool result = ((bool (__thiscall *)(IPipelined *))*(void **)(*(int *)this + 0x18))(this);
    if (result) {
        if (this->field18 == -1) {
            sub_5B47A0(this->field8, this->fieldC);
        }
        this->field18 = arg;
    } else {
        if (this->field18 < arg) {
            this->field18 = -1;
        }
    }
    return result;
}
