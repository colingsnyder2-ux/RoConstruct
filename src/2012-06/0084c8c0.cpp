// from server: 52% by atomic.potato
struct LuaArguments
{
    int f(int, int);
};

extern "C" void __stdcall sub_008341b0(int, int, int, int, int);

int LuaArguments::f(int a, int b)
{
    int v[4];
    v[0] = *(int*)(a);
    v[1] = *(int*)(a + 4);
    v[2] = *(int*)(a + 8);
    v[3] = *(int*)(a + 12);
    sub_008341b0(*(int*)this, v[0], v[1], v[2], v[3]);
    return 1;
}
