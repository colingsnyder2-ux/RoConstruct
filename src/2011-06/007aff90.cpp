// from server: 100% by atomic.potato
struct RBX_ConstraintSurfacePair {
    char pad[0x3c];
    int field_3c;
    void sub_7AFF90(int);
};

extern "C" void* __cdecl sub_80B2EA(int, int, int, int, int);

void RBX_ConstraintSurfacePair::sub_7AFF90(int a) {
    void* p = sub_80B2EA(a, 0, 0xc38f68, 0xc0beec, 0);
    if (p) {
        field_3c = *(int*)((char*)p + 0x168);
    } else {
        field_3c = 0;
    }
}
