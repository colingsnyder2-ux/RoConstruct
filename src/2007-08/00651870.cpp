// from server: 35% by colin
// roc 2007-08 00651870  size: 208 bytes
// Minimal reconstruction.

extern "C" int __cdecl sub_62FF02(void*);
extern "C" int __cdecl sub_62FF20(void);
extern "C" int __cdecl sub_63044E(int);

struct CXTPToolBar {
    char pad0[0x3c];
    int (__stdcall *m_pfn)(int, int, int, int, int, int);
    int sub_651840(void*);
    int sub_651946(void);
    int func(int, int, int, int, int, int);
};

int CXTPToolBar::func(int a1, int a2, int a3, int a4, int a5, int a6)
{
    int local20 = 0;
    int local24;
    int local28;
    int result;

    sub_62FF02(&local20);
    local24 = sub_63044E(*(int*)((char*)&local20 + 0x9c));
    if (local24 == 0)
        return 0;

    sub_651840(&local28);

    if (m_pfn == 0)
        sub_62FF20();

    result = m_pfn(a1, a2, a3, a4, a5, a6);
    sub_651946();
    return result;
}
