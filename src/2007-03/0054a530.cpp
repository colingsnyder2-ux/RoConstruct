// from server: 100% by tester
struct S {
    unsigned int pad[21];
    unsigned int field;
    unsigned int f();
};

unsigned int S::f() {
    return (this->field >> 4) & 1;
}
