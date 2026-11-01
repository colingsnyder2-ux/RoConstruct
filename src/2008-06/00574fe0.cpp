// from server: 100% by colin
extern "C" {
    bool __cdecl sub_495E60(int, int);
    bool __cdecl sub_495E70(int, int);
    int __cdecl sub_49AC80(int);
}

struct RBX_UnifiedWidget {
};

int __cdecl f(int a)
{
    bool v1 = sub_495E60(a, 1);
    bool v2 = sub_495E70(a, 1);
    int v3 = sub_49AC80(a);
    bool v4 = (v3 != 0);
    if (v2)
        return 0;
    if (v1)
        return v4 ? 1 : 2;
    return v4 ? 3 : 4;
}
