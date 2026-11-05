// from server: 100% by colin
// roc 2007-08 006485e0  unit: CXTPCommandBar  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006485e0
//
// 006485e0  8bc1                 mov eax, ecx
// 006485e2  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006485e6  8b11                 mov edx, dword ptr [ecx]
// 006485e8  8910                 mov dword ptr [eax], edx
// 006485ea  8b4904               mov ecx, dword ptr [ecx + 4]
// 006485ed  894804               mov dword ptr [eax + 4], ecx
// 006485f0  33c9                 xor ecx, ecx
// 006485f2  89480c               mov dword ptr [eax + 0xc], ecx
// 006485f5  894808               mov dword ptr [eax + 8], ecx
// 006485f8  c20400               ret 4

struct CXTPCommandBar
{
    int field0;
    int field4;
    int field8;
    int fieldC;
    CXTPCommandBar* assign(const CXTPCommandBar* other);
};

CXTPCommandBar* CXTPCommandBar::assign(const CXTPCommandBar* other)
{
    field0 = other->field0;
    field4 = other->field4;
    fieldC = 0;
    field8 = 0;
    return this;
}
