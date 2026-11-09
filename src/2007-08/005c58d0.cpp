// from server: 0% by colin
struct lua_exception {
    void func_005c58d0(int a, int b, int c);
};

void lua_exception::func_005c58d0(int a, int b, int c)
{
    int *p = (int *)this;
    int old = p[0x1c];
    p[0x1c] = (int)&a;
    ((void (__cdecl *)(int *, int))b)(p, c);
    p[0x1c] = old;
}
