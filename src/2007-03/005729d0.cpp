// from server: 100% by tester
struct Inner2 {
    char pad0[0x78];
    float value;
};

struct Inner1 {
    char pad0[0x64];
    Inner2* inner2;
};

struct S {
    char pad0[0x1e0];
    Inner1* inner1;
    float get() const;
};

float S::get() const {
    return inner1->inner2->value;
}