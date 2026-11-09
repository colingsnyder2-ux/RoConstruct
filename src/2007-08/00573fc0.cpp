// from server: 100% by colin
struct Inner2 {
    char pad0[0x7c];
    float value;
};

struct Inner1 {
    char pad0[0x64];
    Inner2* inner2;
};

struct S {
    char pad0[0x1d8];
    Inner1* inner1;
    float get() const;
};

float S::get() const {
    return inner1->inner2->value;
}
