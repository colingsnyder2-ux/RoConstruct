// from server: 100% by tester
struct S {
    char pad[0x5c];
    int field_5c;
    void setFlag(bool value);
};

void S::setFlag(bool value) {
    field_5c = (field_5c & ~0x10) | (value ? 0x10 : 0);
}
