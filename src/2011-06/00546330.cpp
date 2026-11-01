// from server: 69% by atomic.potato
struct S {
    char pad0[0x20];
    char* buf;
    int limit;
    char pad1[8];
    int pos;
    int f();
};

extern "C" void __cdecl sub_546040();

int S::f() {
    sub_546040();
    int p = pos;
    if (p >= limit) {
        return -1;
    }
    return (unsigned char)buf[p];
}
