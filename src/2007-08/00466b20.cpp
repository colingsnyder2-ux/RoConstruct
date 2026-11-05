// from server: 100% by Yeetserama
// roc 2007-08 00466b20  unit: VCWorkspace::?$CComObject  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00466b20
//
// 00466b20  6aff                 push -1
// 00466b22  68db327400           push 0x7432db
// 00466b27  64a100000000         mov eax, dword ptr fs:[0]
// 00466b2d  50                   push eax
// 00466b2e  51                   push ecx
// 00466b2f  56                   push esi
// 00466b30  57                   push edi
// 00466b31  a188518b00           mov eax, dword ptr [0x8b5188]
// 00466b36  33c4                 xor eax, esp
// 00466b38  50                   push eax
// 00466b39  8d442410             lea eax, [esp + 0x10]
// 00466b3d  64a300000000         mov dword ptr fs:[0], eax
// 00466b43  8bf9                 mov edi, ecx
// 00466b45  897c240c             mov dword ptr [esp + 0xc], edi
// 00466b49  8b7704               mov esi, dword ptr [edi + 4]
// 00466b4c  8b4708               mov eax, dword ptr [edi + 8]
// 00466b4f  8bce                 mov ecx, esi
// 00466b51  8d1481               lea edx, [ecx + eax*4]
// 00466b54  3bf2                 cmp esi, edx
// 00466b56  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00466b5e  731e                 jae 0x466b7e
// 00466b60  8b06                 mov eax, dword ptr [esi]
// 00466b62  85c0                 test eax, eax
// 00466b64  7408                 je 0x466b6e
// 00466b66  8b08                 mov ecx, dword ptr [eax]
// 00466b68  8b5108               mov edx, dword ptr [ecx + 8]
// 00466b6b  50                   push eax
// 00466b6c  ffd2                 call edx
// 00466b6e  8b4708               mov eax, dword ptr [edi + 8]
// 00466b71  8b4f04               mov ecx, dword ptr [edi + 4]
// 00466b74  83c604               add esi, 4
// 00466b77  8d1481               lea edx, [ecx + eax*4]
// 00466b7a  3bf2                 cmp esi, edx
// 00466b7c  72e2                 jb 0x466b60
// 00466b7e  837f0800             cmp dword ptr [edi + 8], 0
// 00466b82  7e0d                 jle 0x466b91
// 00466b84  8b4704               mov eax, dword ptr [edi + 4]
// 00466b87  50                   push eax
// 00466b88  ff15c4e67700         call dword ptr [0x77e6c4]
// 00466b8e  83c404               add esp, 4
// 00466b91  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00466b95  64890d00000000       mov dword ptr fs:[0], ecx
// 00466b9c  59                   pop ecx
// 00466b9d  5f                   pop edi
// 00466b9e  5e                   pop esi
// 00466b9f  83c410               add esp, 0x10
// 00466ba2  c3                   ret 
// copied from an identical function in another client (function ??1CBrowserView@ns_ROCX000007@@QAE@XZ)

namespace ns_ROCX000007 {
// from server: 81% by king_originala
// roc 2008-06 0040e990  unit: CBrowserView  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040e990
//
// 0040e990  6aff                 push -1
// 0040e992  684bd47b00           push 0x7bd44b
// 0040e997  64a100000000         mov eax, dword ptr fs:[0]
// 0040e99d  50                   push eax
// 0040e99e  64892500000000       mov dword ptr fs:[0], esp
// 0040e9a5  51                   push ecx
// 0040e9a6  56                   push esi
// 0040e9a7  57                   push edi
// 0040e9a8  8bf9                 mov edi, ecx
// 0040e9aa  897c2408             mov dword ptr [esp + 8], edi
// 0040e9ae  8b7704               mov esi, dword ptr [edi + 4]
// 0040e9b1  8b4708               mov eax, dword ptr [edi + 8]
// 0040e9b4  8bce                 mov ecx, esi
// 0040e9b6  8d1481               lea edx, [ecx + eax*4]
// 0040e9b9  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0040e9c1  3bf2                 cmp esi, edx
// 0040e9c3  731e                 jae 0x40e9e3
// 0040e9c5  8b06                 mov eax, dword ptr [esi]
// 0040e9c7  85c0                 test eax, eax
// 0040e9c9  7408                 je 0x40e9d3
// 0040e9cb  8b08                 mov ecx, dword ptr [eax]
// 0040e9cd  8b5108               mov edx, dword ptr [ecx + 8]
// 0040e9d0  50                   push eax
// 0040e9d1  ffd2                 call edx
// 0040e9d3  8b4708               mov eax, dword ptr [edi + 8]
// 0040e9d6  8b4f04               mov ecx, dword ptr [edi + 4]
// 0040e9d9  83c604               add esi, 4
// 0040e9dc  8d1481               lea edx, [ecx + eax*4]
// 0040e9df  3bf2                 cmp esi, edx
// 0040e9e1  72e2                 jb 0x40e9c5
// 0040e9e3  837f0800             cmp dword ptr [edi + 8], 0
// 0040e9e7  7e0d                 jle 0x40e9f6
// 0040e9e9  8b4704               mov eax, dword ptr [edi + 4]
// 0040e9ec  50                   push eax
// 0040e9ed  ff15c0288000         call dword ptr [0x8028c0]
// 0040e9f3  83c404               add esp, 4
// 0040e9f6  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040e9fa  5f                   pop edi
// 0040e9fb  5e                   pop esi
// 0040e9fc  64890d00000000       mov dword ptr fs:[0], ecx
// 0040ea03  83c410               add esp, 0x10
// 0040ea06  c3                   ret 

extern "C" __declspec(dllimport) void __cdecl free(void*);

struct IUnknown {
    virtual long __stdcall QueryInterface(const void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct Storage {
    IUnknown** m_ppUnk;
    int m_nSize;
    IUnknown** begin() { return m_ppUnk; }
    IUnknown** end() { return &m_ppUnk[m_nSize]; }
    ~Storage() {
        if (m_nSize > 0)
            free(m_ppUnk);
    }
};

struct CBrowserView {
    int field0;
    Storage m_vec;
    ~CBrowserView();
};

CBrowserView::~CBrowserView() {
    IUnknown** pp = m_vec.begin();
    while (pp < m_vec.end()) {
        if (*pp != 0)
            (*pp)->Release();
        pp++;
    }
}
}
