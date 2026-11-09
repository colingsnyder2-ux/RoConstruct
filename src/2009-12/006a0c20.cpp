// from server: 72% by atomic.potato
extern "C" {
    int __cdecl sub_78A660(int, int, int);
    void __cdecl sub_788F50(int, int);
}

extern int dword_B62B44;

struct Vec3 {
    float x;
    float y;
    float z;
};

int __cdecl sub_6A0C20(int a1) {
    int v1 = sub_78A660(dword_B62B44, 2, a1);
    int v2 = sub_78A660(dword_B62B44, 1, a1);
    Vec3* p2 = (Vec3*)v2;
    Vec3* p1 = (Vec3*)v1;
    bool eq = (p2->x == p1->x) && (p2->y == p1->y) && (p2->z == p1->z);
    sub_788F50(a1, eq);
    return 1;
}
