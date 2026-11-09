// from server: 100% by tester
struct CXTPCommandBar;

struct CXTPCommandBarVtbl {
    char pad0[0x130];
    int (__thiscall *pfn_128)(CXTPCommandBar *);
};

struct CXTPCommandBar {
    CXTPCommandBarVtbl *m_pVtbl;
};

extern "C" CXTPCommandBar * __stdcall sub_00646570();

CXTPCommandBar * __stdcall sub_00647070()
{
    CXTPCommandBar *p = sub_00646570();
    if (p != 0) {
        if (p->m_pVtbl->pfn_128(p) != 0) {
            return p;
        }
    }
    return 0;
}
