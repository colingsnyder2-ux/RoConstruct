// from server: 60% by atomic.potato
struct Inner {
    char pad0[0x10];
    int field10;
    char pad14[0x4];
    int field14;
};

struct Outer {
    char pad0[0x28];
    int field28;
    char call_inner(Inner* inner, int arg);
    char call_virtual(int a, int b);
};

char Outer::call_inner(Inner* inner, int arg) {
    if (this->call_virtual(this->field28, inner->field10)) {
        return 0;
    }
    return this->call_virtual(arg, inner->field14);
}
