// from server: 75% by atomic.potato
extern "C" int __stdcall sub_007f3e30();

struct CRobloxWnd
{
    int f();
    char pad[241];
};

int CRobloxWnd::f()
{
    if (pad[240] != 0)
        return sub_007f3e30();
    return 1;
}
