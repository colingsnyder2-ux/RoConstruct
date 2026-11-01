// from server: 100% by colin
struct CXTShadowHook {
    char pad[0x10];
    int field_0x10;
    int method_7204e0(int, int, int);
    int method_712630(int, int*, int*);
    int target(int, int, int);
};

int CXTShadowHook::target(int a, int b, int c) {
    int result = method_7204e0(a, b, c);
    int local1;
    int local2;
    ((CXTShadowHook*)field_0x10)->method_712630(a, &local1, &local2);
    return result;
}
