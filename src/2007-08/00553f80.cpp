// from server: 100% by colin
struct S {
    char pad[0xec];
    int field_ec;
    int get(int* out);
};

int S::get(int* out) {
    *out = field_ec;
    return (int)out;
}
