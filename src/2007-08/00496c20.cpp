// from server: 100% by colin
struct S {
    char pad[0x148];
    int field_148;
    void set(int value);
};

extern "C" void __stdcall sub_444710(int);

void S::set(int value) {
    if (value != this->field_148) {
        this->field_148 = value;
        sub_444710(0x8be04c);
    }
}
