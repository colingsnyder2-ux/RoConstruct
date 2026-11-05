// from server: 100% by colin
// roc 2010-06 00857110  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00857110
//
// 00857110  8b442404             mov eax, dword ptr [esp + 4]
// 00857114  85c0                 test eax, eax
// 00857116  7c0e                 jl 0x857126
// 00857118  3b4128               cmp eax, dword ptr [ecx + 0x28]
// 0085711b  7d09                 jge 0x857126
// 0085711d  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 00857120  8d0481               lea eax, [ecx + eax*4]
// 00857123  c20400               ret 4
// 00857126  e8210bf5ff           call 0x7a7c4c
// bounds-checked element accessor; m_pData at +0x24, m_nSize at +0x28

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD

struct S_func_00857110 {
    char pad0[36];
    void** m_pData;
    int m_nSize;
    void*& GetAt(int nIndex) const;
};

__declspec(noreturn) void thrower_00857110();

void*& S_func_00857110::GetAt(int nIndex) const
{
    if (nIndex < 0 || nIndex >= m_nSize)
        thrower_00857110();
    return m_pData[nIndex];
}
