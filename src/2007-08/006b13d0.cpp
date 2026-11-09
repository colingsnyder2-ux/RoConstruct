// from server: 68% by colin
// roc 2007-08 006b13d0  unit: CXTPRibbonTheme  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006b13d0
//
// 006b13d0  8911                 mov dword ptr [ecx], edx
// 006b13d2  8b5004               mov edx, dword ptr [eax + 4]
// 006b13d5  895104               mov dword ptr [ecx + 4], edx
// 006b13d8  8b5008               mov edx, dword ptr [eax + 8]
// 006b13db  8b400c               mov eax, dword ptr [eax + 0xc]
// 006b13de  895108               mov dword ptr [ecx + 8], edx
// 006b13e1  8b54246c             mov edx, dword ptr [esp + 0x6c]
// 006b13e5  89410c               mov dword ptr [ecx + 0xc], eax
// 006b13e8  8d4c2448             lea ecx, [esp + 0x48]
// 006b13ec  51                   push ecx
// 006b13ed  52                   push edx
// 006b13ee  8bcb                 mov ecx, ebx
// 006b13f0  e82bf10500           call 0x710520
// 006b13f5  5f                   pop edi
// 006b13f6  5e                   pop esi
// 006b13f7  5d                   pop ebp
// 006b13f8  5b                   pop ebx
// 006b13f9  83c440               add esp, 0x40
// 006b13fc  c20c00               ret 0xc

struct CXTPRibbonTheme {
    int m_field0;
    int m_field4;
    int m_field8;
    int m_fieldC;
    void CopyFrom(const CXTPRibbonTheme* other, int a, int b);
};

extern "C" void __stdcall Sub_710520(int a, void* p);

void CXTPRibbonTheme::CopyFrom(const CXTPRibbonTheme* other, int a, int b) {
    int local[16];
    m_field0 = other->m_field0;
    m_field4 = other->m_field4;
    m_field8 = other->m_field8;
    m_fieldC = other->m_fieldC;
    Sub_710520(a, local);
}
