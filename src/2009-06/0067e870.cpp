// from server: 100% by why2
struct Inner {
    char pad[0x7c];
    int field_7c;
};

struct Outer {
    Inner* ptr_0;
};

struct RBX_Mechanism {
    char pad[0xb0];
    Outer* field_b0;
    int get();
};

int RBX_Mechanism::get() {
    return field_b0->ptr_0->field_7c;
}
