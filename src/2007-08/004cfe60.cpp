// from server: 100% by tester
struct S {
    char pad[0x194];
    int field_ec;
    int get(int* out);
};

int S::get(int* out) {
    *out = field_ec;
    return (int)out;
}