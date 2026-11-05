// from server: 100% by king_originala
struct S {
    unsigned int fields[13];
    S* f();
};

S* S::f() {
    fields[8] = 0;
    fields[2] = 0x81c80c;
    fields[3] = 0;
    fields[5] = 0;
    fields[9] = 0;
    fields[10] = 0;
    fields[11] = 0;
    fields[12] = 0;
    return this;
}
