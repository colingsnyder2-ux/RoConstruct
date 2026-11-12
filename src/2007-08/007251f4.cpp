// from server: 97% by EspClaude
// roc-flags: /O1 /GS- /EHsc /MD
// from server: 56% by colin
// roc 2007-08 007251f4  unit: CXTIconHandle  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 007251f4
//
// 007251f4  55                   push ebp
// 007251f5  8bec                 mov ebp, esp
// 007251f7  56                   push esi
// 007251f8  8b7508               mov esi, dword ptr [ebp + 8]
// 007251fb  57                   push edi
// 007251fc  ff750c               push dword ptr [ebp + 0xc]
// 007251ff  83c608               add esi, 8
// 00725202  83e6f8               and esi, 0xfffffff8
// 00725205  8d4508               lea eax, [ebp + 8]
// 00725208  56                   push esi
// 00725209  50                   push eax
// 0072520a  8bf9                 mov edi, ecx
// 0072520c  e88fc5cdff           call 0x4017a0
// 00725211  83c40c               add esp, 0xc
// 00725214  85c0                 test eax, eax
// 00725216  7c36                 jl 0x72524e
// 00725218  ff7508               push dword ptr [ebp + 8]
// 0072521b  8d4508               lea eax, [ebp + 8]
// 0072521e  6a10                 push 0x10
// 00725220  50                   push eax
// 00725221  e88ad6cdff           call 0x4028b0
// 00725226  83c40c               add esp, 0xc
// 00725229  85c0                 test eax, eax
// 0072522b  7c21                 jl 0x72524e
// 0072522d  8b4f04               mov ecx, dword ptr [edi + 4]
// 00725230  ff7508               push dword ptr [ebp + 8]
// 00725233  8b01                 mov eax, dword ptr [ecx]
// 00725235  ff10                 call dword ptr [eax]
// 00725237  85c0                 test eax, eax
// 00725239  7413                 je 0x72524e
// 0072523b  4e                   dec esi
// 0072523c  83600400             and dword ptr [eax + 4], 0
// 00725240  8938                 mov dword ptr [eax], edi
// 00725242  c7400c01000000       mov dword ptr [eax + 0xc], 1
// 00725249  897008               mov dword ptr [eax + 8], esi
// 0072524c  eb02                 jmp 0x725250
// 0072524e  33c0                 xor eax, eax
// 00725250  5f                   pop edi
// 00725251  5e                   pop esi
// 00725252  5d                   pop ebp

typedef long HRESULT;

template <typename T> HRESULT AtlMultiply(T* pResult, T nOperand1, T nOperand2);
template <typename T> HRESULT AtlAdd(T* pResult, T nLeft, T nRight);

struct IAtlMemMgr {
    virtual void* Allocate(unsigned int nBytes) = 0;
};

struct CStringMgr;

struct CStringData {
    CStringMgr* pStringMgr;
    int nDataLength;
    int nAllocLength;
    long nRefs;
};

struct CStringMgr {
    void* vtbl_pad;
    IAtlMemMgr* m_pMemMgr;
    CStringData* Allocate(int nChars, int nCharSize);
};

CStringData* CStringMgr::Allocate(int nChars, int nCharSize)
{
    unsigned int nTotalSize;
    CStringData* pData;
    unsigned int nDataBytes;

    nChars = (nChars + 8) & ~7;
    if (AtlMultiply<unsigned int>(&nDataBytes, nChars, nCharSize) < 0 ||
        AtlAdd<unsigned int>(&nTotalSize, sizeof(CStringData), nDataBytes) < 0)
    {
        return 0;
    }
    pData = static_cast<CStringData*>(m_pMemMgr->Allocate(nTotalSize));
    if (pData == 0)
        return 0;
    pData->pStringMgr = this;
    pData->nRefs = 1;
    pData->nAllocLength = nChars - 1;
    pData->nDataLength = 0;
    return pData;
}
