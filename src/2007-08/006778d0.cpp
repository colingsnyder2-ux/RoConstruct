// from server: 100% by colin
// roc 2007-08 006778d0  unit: CXTPPopupToolBar  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006778d0
//
// 006778d0  8b0db0868c00         mov ecx, dword ptr [0x8c86b0]
// 006778d6  e8518cfbff           call 0x63052c
// 006778db  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006778df  898800010000         mov dword ptr [eax + 0x100], ecx
// 006778e5  c3                   ret

struct S_63052c {
    char pad0[0x100];
    int m_field100;
};

extern S_63052c* g_8c86b0;

S_63052c* __fastcall get_63052c(S_63052c* self);

void set_6778d0(int value)
{
    S_63052c* p = get_63052c(g_8c86b0);
    p->m_field100 = value;
}
