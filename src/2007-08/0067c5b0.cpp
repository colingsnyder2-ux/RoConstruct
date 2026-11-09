// from server: 100% by colin
struct CXTPControls
{
    int sub_0067C560(int, int);
    int sub_0067C5B0(int, int, int);
};

int CXTPControls::sub_0067C5B0(int a1, int a2, int a3)
{
    int v = (*(int (__thiscall **)(int, int))(*(int *)a1 + 0x13c))(a1, a3);
    return sub_0067C560(v, a2);
}
