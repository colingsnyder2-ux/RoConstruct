// from server: 100% by why2
struct S {
    char pad[0x118];
    int field;
    S* get() const;
};

S* S::get() const {
    return (S*)((char*)this - 0x118);
}
