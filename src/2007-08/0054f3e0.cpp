// from server: 100% by colin
struct S {
    char pad[0x9c];
    unsigned int flags;
    void set_flag(char value);
};

void S::set_flag(char value) {
    unsigned int old = flags;
    unsigned int mask = (value != 0) ? 0x10 : 0;
    flags = (old & 0xffffffef) | mask;
}
