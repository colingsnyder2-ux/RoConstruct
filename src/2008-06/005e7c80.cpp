// from server: 100% by tester
struct Geometry {
    char pad0[0x38];
    int* field38;
    int field3c;
    int f();
};

int __stdcall helper(int);

int Geometry::f() {
    int value;
    if (field3c > 0) {
        value = *field38;
    } else {
        value = 0;
    }
    return helper(value);
}
