// from server: 100% by Xemicl
// from server: 100% by tester
// roc 2012-06 004791e0  unit: CRobloxControlMaterialSelector  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004791e0
//
// 004791e0  56                   push esi
// 004791e1  8b742408             mov esi, dword ptr [esp + 8]
// 004791e5  57                   push edi
// 004791e6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004791ea  3bf7                 cmp esi, edi
// 004791ec  7412                 je 0x479200
// 004791ee  8bff                 mov edi, edi
// 004791f0  8d4e08               lea ecx, [esi + 8]
// 004791f3  ff15d047b200         call dword ptr [0xb247d0]
// 004791f9  83c60c               add esi, 0xc
// 004791fc  3bf7                 cmp esi, edi
// 004791fe  75f0                 jne 0x4791f0
// 00479200  5f                   pop edi
// 00479201  5e                   pop esi
// 00479202  c20800               ret 8

typedef void *(__thiscall *Fn)(void *);

extern Fn g_fn_009ecef0;

struct CRobloxControlMaterialSelector
{
    void f(void *, void *);
};

void CRobloxControlMaterialSelector::f(void *first, void *last)
{
    char *p = (char *)first;
    char *end = (char *)last;
    while (p != end)
    {
        g_fn_009ecef0(p + 8);
        p += 24;
    }
}
