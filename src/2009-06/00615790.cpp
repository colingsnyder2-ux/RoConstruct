// from server: 100% by why2
struct S {
    char pad[0x9c];
    unsigned int field_0x9c;
    int get();
};

int S::get() {
    return (field_0x9c >> 2) & 1;
}
