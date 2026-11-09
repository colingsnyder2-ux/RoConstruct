// from server: 100% by colin
struct S {
    int f();
};

int S::f() {
    int zero = 0;
    *(int*)((char*)this + 0) = 0x79efcc;
    *(int*)((char*)this + 4) = 0x67452301;
    *(int*)((char*)this + 8) = 0xefcdab89;
    *(int*)((char*)this + 12) = 0x98badcfe;
    *(int*)((char*)this + 16) = 0x10325476;
    *(int*)((char*)this + 20) = 0xc3d2e1f0;
    *(int*)((char*)this + 24) = zero;
    *(int*)((char*)this + 28) = zero;
    return zero;
}
