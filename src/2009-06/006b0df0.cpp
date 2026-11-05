// from server: 100% by why2
struct S {
    char pad[0x34];
    int field_0x34;
    void method();
};

extern "C" void __stdcall helper(int* p);

void S::method() {
    if (field_0x34 != 0) {
        helper(&field_0x34);
    }
}
