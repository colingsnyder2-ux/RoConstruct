// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 82% by colin
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