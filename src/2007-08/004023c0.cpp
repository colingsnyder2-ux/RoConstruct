// from server: 100% by Yeetserama
// roc 2007-08 004023c0  unit: VCWorkspace::?$CComObject  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004023c0
//
// 004023c0  56                   push esi
// 004023c1  8bf1                 mov esi, ecx
// 004023c3  837e0400             cmp dword ptr [esi + 4], 0
// 004023c7  752b                 jne 0x4023f4
// 004023c9  6a04                 push 4
// 004023cb  6a04                 push 4
// 004023cd  ff15e0e67700         call dword ptr [0x77e6e0]
// 004023d3  83c408               add esp, 8
// 004023d6  85c0                 test eax, eax
// 004023d8  7504                 jne 0x4023de
// 004023da  5e                   pop esi
// 004023db  c20400               ret 4
// 004023de  33c9                 xor ecx, ecx
// 004023e0  8908                 mov dword ptr [eax], ecx
// 004023e2  894804               mov dword ptr [eax + 4], ecx
// 004023e5  894808               mov dword ptr [eax + 8], ecx
// 004023e8  89480c               mov dword ptr [eax + 0xc], ecx
// 004023eb  8906                 mov dword ptr [esi], eax
// 004023ed  c7460404000000       mov dword ptr [esi + 4], 4
// 004023f4  8b0e                 mov ecx, dword ptr [esi]
// 004023f6  8b5604               mov edx, dword ptr [esi + 4]
// 004023f9  53                   push ebx
// 004023fa  57                   push edi
// 004023fb  8bf9                 mov edi, ecx
// 004023fd  8d3c97               lea edi, [edi + edx*4]
// 00402400  3bcf                 cmp ecx, edi
// 00402402  b801000000           mov eax, 1
// 00402407  731d                 jae 0x402426
// 00402409  8da42400000000       lea esp, [esp]
// 00402410  833900               cmp dword ptr [ecx], 0
// 00402413  742d                 je 0x402442
// 00402415  8b1e                 mov ebx, dword ptr [esi]
// 00402417  8bfa                 mov edi, edx
// 00402419  83c104               add ecx, 4
// 0040241c  8d3cbb               lea edi, [ebx + edi*4]
// 0040241f  83c001               add eax, 1
// 00402422  3bcf                 cmp ecx, edi
// 00402424  72ea                 jb 0x402410
// 00402426  8b06                 mov eax, dword ptr [esi]
// 00402428  8d3c12               lea edi, [edx + edx]
// 0040242b  57                   push edi
// 0040242c  6a04                 push 4
// 0040242e  50                   push eax
// 0040242f  ff15dce67700         call dword ptr [0x77e6dc]
// 00402435  83c40c               add esp, 0xc
// 00402438  85c0                 test eax, eax
// 0040243a  7512                 jne 0x40244e
// 0040243c  5f                   pop edi
// 0040243d  5b                   pop ebx
// 0040243e  5e                   pop esi
// 0040243f  c20400               ret 4
// 00402442  8b542410             mov edx, dword ptr [esp + 0x10]
// 00402446  5f                   pop edi
// 00402447  5b                   pop ebx
// 00402448  8911                 mov dword ptr [ecx], edx
// 0040244a  5e                   pop esi
// 0040244b  c20400               ret 4
// 0040244e  8b4e04               mov ecx, dword ptr [esi + 4]
// 00402451  03c9                 add ecx, ecx
// 00402453  03c9                 add ecx, ecx
// 00402455  51                   push ecx
// 00402456  03c8                 add ecx, eax
// 00402458  6a00                 push 0
// 0040245a  51                   push ecx
// 0040245b  8906                 mov dword ptr [esi], eax
// 0040245d  e82ae72200           call 0x630b8c
// 00402462  8b4e04               mov ecx, dword ptr [esi + 4]
// 00402465  8b16                 mov edx, dword ptr [esi]
// 00402467  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0040246b  89048a               mov dword ptr [edx + ecx*4], eax
// 0040246e  8b4604               mov eax, dword ptr [esi + 4]
// 00402471  83c40c               add esp, 0xc
// 00402474  897e04               mov dword ptr [esi + 4], edi
// 00402477  5f                   pop edi
// 00402478  5b                   pop ebx
// 00402479  83c001               add eax, 1
// 0040247c  5e                   pop esi
// 0040247d  c20400               ret 4
// copied from an identical function in another client (function ?Add@S@ns_ROCX00000a@@QAEKPAX@Z)

namespace ns_ROCX00000a {
typedef unsigned int size_t;
typedef unsigned long DWORD;

extern "C" {
    extern void* (__cdecl *calloc)(size_t, size_t);
    extern void* (__cdecl *_recalloc)(void*, size_t, size_t);
    void* __cdecl memset(void*, int, size_t);
}

struct S {
    void** m_ppUnk;
    int m_nSize;

    void** begin() { return m_ppUnk; }
    void** end() { return &m_ppUnk[m_nSize]; }
    DWORD Add(void* pUnk);
};

DWORD S::Add(void* pUnk)
{
    void** pp = 0;
    if (m_nSize == 0) {
        pp = (void**)calloc(sizeof(void*), 4);
        if (pp == 0)
            return 0;
        memset(pp, 0, sizeof(void*) * 4);
        m_ppUnk = pp;
        m_nSize = 4;
    }
    DWORD dwCookie = 1;
    for (pp = begin(); pp < end(); pp++) {
        if (*pp == 0) {
            *pp = pUnk;
            return dwCookie;
        }
        dwCookie++;
    }
    int nAlloc = m_nSize * 2;
    pp = (void**)_recalloc(m_ppUnk, sizeof(void*), nAlloc);
    if (pp == 0)
        return 0;
    m_ppUnk = pp;
    memset(&m_ppUnk[m_nSize], 0, sizeof(void*) * m_nSize);
    m_ppUnk[m_nSize] = pUnk;
    dwCookie = m_nSize + 1;
    m_nSize = nAlloc;
    return dwCookie;
}
}
