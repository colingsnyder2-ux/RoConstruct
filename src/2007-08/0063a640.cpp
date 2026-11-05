// from server: 100% by colin
// roc 2007-08 0063a640  unit: seg_00630000  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0063a640
//
// 0063a640  8b442408             mov eax, dword ptr [esp + 8]
// 0063a644  56                   push esi
// 0063a645  8b742408             mov esi, dword ptr [esp + 8]
// 0063a649  6a00                 push 0
// 0063a64b  51                   push ecx
// 0063a64c  50                   push eax
// 0063a64d  56                   push esi
// 0063a64e  e8adf9ffff           call 0x63a000
// 0063a653  8bc8                 mov ecx, eax
// 0063a655  e8f62d0000           call 0x63d450
// 0063a65a  8bc6                 mov eax, esi
// 0063a65c  5e                   pop esi
// 0063a65d  c20800               ret 8

struct CXTPControl
{
    CXTPControl* sub_63A000(CXTPControl* p, int a, int b, int c);
    void sub_63D450();
    CXTPControl* func_0063A640(CXTPControl* p, int a);
};

CXTPControl* CXTPControl::func_0063A640(CXTPControl* p, int a)
{
    CXTPControl* r = this->sub_63A000(p, a, (int)this, 0);
    r->sub_63D450();
    return p;
}
