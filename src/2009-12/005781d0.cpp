// from server: 89% by atomic.potato
extern "C" int __cdecl sub_7F4CE6(int, int, int);

struct RBX_MeshPartCustomizableKey {
    int compute(int, int);
};

int RBX_MeshPartCustomizableKey::compute(int a, int b) {
    int v = 0x7d;
    if ((unsigned)b > 0) {
        int t = b;
        int *p;
        if ((unsigned)b > 0x7d)
            p = &v;
        else
            p = &t;
        int r = *p;
        sub_7F4CE6(a, v, r);
        return r;
    }
    return 0;
}
