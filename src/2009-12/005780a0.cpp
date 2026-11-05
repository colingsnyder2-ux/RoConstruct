// from server: 46% by atomic.potato
extern "C" int __cdecl sub_7f4ce6(int, int, int);

struct MeshTrussPartKey {
    int compare(unsigned int a, unsigned int b);
};

int MeshTrussPartKey::compare(unsigned int a, unsigned int b) {
    unsigned int v = 0x39;
    if (a == 0)
        return v;
    if (a <= 0x39)
        v = a;
    return sub_7f4ce6(v, b, a);
}
