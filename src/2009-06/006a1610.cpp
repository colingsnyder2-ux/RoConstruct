// from server: 100% by why2
struct S {
    char pad[0x2c];
    int field_2c;

    int get();
};

struct Inner {
    char pad[0x2c];
    int field_2c;
};

struct Outer {
    char pad[0xe4];
    Inner* inner;
};

int S::get() {
    Outer* o = *(Outer**)((char*)this - 0x130);
    return o->inner->field_2c;
}
