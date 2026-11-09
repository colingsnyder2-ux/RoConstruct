// from server: 43% by atomic.potato
extern "C" int __cdecl sub_7F4CE6(int, int, int);

struct RBX_MeshPartSkinedKey {
    int f(int, int);
};

int RBX_MeshPartSkinedKey::f(int a, int b) {
    int v = 0x45;
    if ((unsigned)a > 0x45) {
        v = a;
    }
    return sub_7F4CE6(b, v, 0);
}
