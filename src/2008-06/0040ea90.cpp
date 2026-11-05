// from server: 100% by EspClaude
// from server: 80% by king_originala
// roc 2008-06 0040ea90  unit: VCBrowserViewExternal::?$CProxy_IBrowserViewExternalEvents  size: 188 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040ea90
//
// 0040ea90  56                   push esi
// 0040ea91  8bf1                 mov esi, ecx
// 0040ea93  837e0400             cmp dword ptr [esi + 4], 0
// 0040ea97  752b                 jne 0x40eac4
// 0040ea99  6a04                 push 4
// 0040ea9b  6a04                 push 4
// 0040ea9d  ff1558288000         call dword ptr [0x802858]
// 0040eaa3  83c408               add esp, 8
// 0040eaa6  85c0                 test eax, eax
// 0040eaa8  7504                 jne 0x40eaae
// 0040eaaa  5e                   pop esi
// 0040eaab  c20400               ret 4
// 0040eaae  33c9                 xor ecx, ecx
// 0040eab0  8908                 mov dword ptr [eax], ecx
// 0040eab2  894804               mov dword ptr [eax + 4], ecx
// 0040eab5  894808               mov dword ptr [eax + 8], ecx
// 0040eab8  89480c               mov dword ptr [eax + 0xc], ecx
// 0040eabb  8906                 mov dword ptr [esi], eax
// 0040eabd  c7460404000000       mov dword ptr [esi + 4], 4
// 0040eac4  8b0e                 mov ecx, dword ptr [esi]
// 0040eac6  8b5604               mov edx, dword ptr [esi + 4]
// 0040eac9  53                   push ebx
// 0040eaca  57                   push edi
// 0040eacb  8bf9                 mov edi, ecx
// 0040eacd  8d3c97               lea edi, [edi + edx*4]
// 0040ead0  b801000000           mov eax, 1
// 0040ead5  3bcf                 cmp ecx, edi
// 0040ead7  731b                 jae 0x40eaf4
// 0040ead9  8da42400000000       lea esp, [esp]
// 0040eae0  833900               cmp dword ptr [ecx], 0
// 0040eae3  742b                 je 0x40eb10
// 0040eae5  8b1e                 mov ebx, dword ptr [esi]
// 0040eae7  8bfa                 mov edi, edx
// 0040eae9  83c104               add ecx, 4
// 0040eaec  8d3cbb               lea edi, [ebx + edi*4]
// 0040eaef  40                   inc eax
// 0040eaf0  3bcf                 cmp ecx, edi
// 0040eaf2  72ec                 jb 0x40eae0
// 0040eaf4  8b06                 mov eax, dword ptr [esi]
// 0040eaf6  8d3c12               lea edi, [edx + edx]
// 0040eaf9  57                   push edi
// 0040eafa  6a04                 push 4
// 0040eafc  50                   push eax
// 0040eafd  ff1580288000         call dword ptr [0x802880]
// 0040eb03  83c40c               add esp, 0xc
// 0040eb06  85c0                 test eax, eax
// 0040eb08  7512                 jne 0x40eb1c
// 0040eb0a  5f                   pop edi
// 0040eb0b  5b                   pop ebx
// 0040eb0c  5e                   pop esi
// 0040eb0d  c20400               ret 4
// 0040eb10  8b542410             mov edx, dword ptr [esp + 0x10]
// 0040eb14  5f                   pop edi
// 0040eb15  5b                   pop ebx
// 0040eb16  8911                 mov dword ptr [ecx], edx
// 0040eb18  5e                   pop esi
// 0040eb19  c20400               ret 4
// 0040eb1c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0040eb1f  03c9                 add ecx, ecx
// 0040eb21  03c9                 add ecx, ecx
// 0040eb23  51                   push ecx
// 0040eb24  03c8                 add ecx, eax
// 0040eb26  6a00                 push 0
// 0040eb28  51                   push ecx
// 0040eb29  8906                 mov dword ptr [esi], eax
// 0040eb2b  e8d42b2900           call 0x6a1704
// 0040eb30  8b4e04               mov ecx, dword ptr [esi + 4]
// 0040eb33  8b16                 mov edx, dword ptr [esi]
// 0040eb35  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0040eb39  89048a               mov dword ptr [edx + ecx*4], eax
// 0040eb3c  8b4604               mov eax, dword ptr [esi + 4]
// 0040eb3f  83c40c               add esp, 0xc
// 0040eb42  897e04               mov dword ptr [esi + 4], edi
// 0040eb45  5f                   pop edi
// 0040eb46  5b                   pop ebx
// 0040eb47  40                   inc eax
// 0040eb48  5e                   pop esi
// 0040eb49  c20400               ret 4

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
