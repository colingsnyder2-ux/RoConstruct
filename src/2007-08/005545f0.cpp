// from server: 100% by colin
struct S {
    char pad[0xe8];
    int field_e8;
    void set(int value);
};

void __stdcall helper(int);

void S::set(int value) {
    field_e8 = value;
    helper(0x8c1d14);
}
