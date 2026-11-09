// from server: 75% by atomic.potato
extern "C" int __cdecl sub_80B5DC(int, int, int);

struct MeshPrismPartKey {
    int compare(unsigned int a, unsigned int b);
};

int MeshPrismPartKey::compare(unsigned int a, unsigned int b) {
    unsigned int v = 0x3d;
    if (a > 0) {
        unsigned int x = a;
        unsigned int *p = (a > 0x3d) ? &v : &x;
        unsigned int r = *p;
        sub_80B5DC(x, (int)&v, r);
        return r;
    }
    return 0;
}
