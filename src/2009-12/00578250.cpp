// from server: 78% by atomic.potato
extern "C" int __cdecl sub_7F4CE6(int, int, int);

struct RBX_MeshTrussFaceKey
{
    int compare(int a, int b);
};

int RBX_MeshTrussFaceKey::compare(int a, int b)
{
    int local = 0x3c;
    if ((unsigned int)a > 0)
    {
        int *p;
        if ((unsigned int)a > 0x3c)
            p = &local;
        else
            p = &a;
        int v = *p;
        sub_7F4CE6(b, local, v);
        return v;
    }
    return 0;
}
