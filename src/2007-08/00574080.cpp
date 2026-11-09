// from server: 100% by colin
struct S_00574080_inner {
    char pad[0x6c];
    void* value;
};

struct S_00574080 {
    char pad[0x1d8];
    S_00574080_inner* ptr;
    bool f();
};

bool S_00574080::f() {
    return ptr->value != 0;
}
