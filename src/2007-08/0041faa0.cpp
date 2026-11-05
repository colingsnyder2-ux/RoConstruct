// from server: 100% by colin
struct CSelectionTreeCtrl;

extern "C" int __stdcall func_00630430(int, int, int, int);

extern CSelectionTreeCtrl* G1_008bae2c;

struct CSelectionTreeCtrl
{
    int m(int, int, int, int);
};

int CSelectionTreeCtrl::m(int a, int b, int c, int d)
{
    if (func_00630430(a, b, c, d))
        return 1;
    CSelectionTreeCtrl* p = G1_008bae2c;
    if (!p)
        return 0;
    return ((int (__thiscall*)(CSelectionTreeCtrl*, int, int, int, int))(*(void***)p)[5])(p, a, b, c, d);
}
