// from server: 100% by tester
struct S {
    char pad[200];
    int field;
    S* get() const;
};

S* S::get() const {
    return (S*)((char*)this - 0x118);
}
