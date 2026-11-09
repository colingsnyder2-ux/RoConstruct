// from server: 52% by atomic.potato
struct S_func_00459d40 {
    char pad0[0x58];
    int field_58;
    int field_5c;
};

int __stdcall func_00459d40(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    int *p = (int *)a5;
    int *q = (int *)a6;
    if (p == 0 || q == 0)
        return (int)0x80004003;
    S_func_00459d40 *obj;
    if (a1 == 0)
        obj = 0;
    else
        obj = (S_func_00459d40 *)((char *)a1 - 0x14);
    if (a2 != 1)
        return (int)0x80004005;
    if (*(int *)((char *)p + 4) != 0)
        return (int)0x80004005;
    q[0] = obj->field_58;
    q[1] = obj->field_5c;
    return 0;
}
