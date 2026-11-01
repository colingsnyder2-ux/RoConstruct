// from server: 100% by colin
struct S {
    char pad[0xec];
    int field_ec;
    void set(int value);
};

void __stdcall helper(int);

void S::set(int value) {
    field_ec = value;
    helper(0x8c1d4c);
}
