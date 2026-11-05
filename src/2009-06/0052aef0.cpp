// from server: 23% by atomic.potato
extern "C" int __cdecl sub_719EB6(int, int, int);

struct RBX_MeshFaceKey
{
    int sub_52AEF0(int a, int b);
};

int RBX_MeshFaceKey::sub_52AEF0(int a, int b)
{
    int local = 0x24;
    if ((unsigned)a <= 0x24)
        return 0;
    int *p = &a;
    if ((unsigned)a > 0x24)
        p = &local;
    int v = *p;
    sub_719EB6(a, b, v);
    return v;
}
