// from server: 100% by EspClaude
// roc 2009-06 00454cd0  unit: CRobloxReportView::CStatsItemRecord::CValueItem  size: 1038 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00454cd0
//
// 00454cd0  6aff                 push -1
// 00454cd2  686a1d8500           push 0x851d6a
// 00454cd7  64a100000000         mov eax, dword ptr fs:[0]
// 00454cdd  50                   push eax
// 00454cde  64892500000000       mov dword ptr fs:[0], esp
// 00454ce5  83ec4c               sub esp, 0x4c
// 00454ce8  53                   push ebx
// 00454ce9  55                   push ebp
// 00454cea  56                   push esi
// 00454ceb  33c0                 xor eax, eax
// 00454ced  57                   push edi
// 00454cee  894c2450             mov dword ptr [esp + 0x50], ecx
// 00454cf2  89442414             mov dword ptr [esp + 0x14], eax
// 00454cf6  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 00454cfa  89442464             mov dword ptr [esp + 0x64], eax
// 00454cfe  89442418             mov dword ptr [esp + 0x18], eax
// 00454d02  e8a9d12f00           call 0x751eb0
// 00454d07  85c0                 test eax, eax
// 00454d09  0f8eab030000         jle 0x4550ba
// 00454d0f  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00454d13  8b442418             mov eax, dword ptr [esp + 0x18]
// 00454d17  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 00454d1b  50                   push eax
// 00454d1c  e89fd12f00           call 0x751ec0
// 00454d21  8bd8                 mov ebx, eax
// 00454d23  8b4328               mov eax, dword ptr [ebx + 0x28]
// 00454d26  33ed                 xor ebp, ebp
// 00454d28  895c244c             mov dword ptr [esp + 0x4c], ebx
// 00454d2c  85c0                 test eax, eax
// 00454d2e  0f8e94000000         jle 0x454dc8
// 00454d34  85ed                 test ebp, ebp
// 00454d36  7c18                 jl 0x454d50
// 00454d38  3be8                 cmp ebp, eax
// 00454d3a  7d14                 jge 0x454d50
// 00454d3c  3b6b28               cmp ebp, dword ptr [ebx + 0x28]
// 00454d3f  0f8d94030000         jge 0x4550d9
// 00454d45  8b4b24               mov ecx, dword ptr [ebx + 0x24]
// 00454d48  8b3ca9               mov edi, dword ptr [ecx + ebp*4]
// 00454d4b  8d04a9               lea eax, [ecx + ebp*4]
// 00454d4e  eb02                 jmp 0x454d52
// 00454d50  33ff                 xor edi, edi
// 00454d52  6a00                 push 0
// 00454d54  6814569e00           push 0x9e5614
// 00454d59  68dcf99d00           push 0x9df9dc
// 00454d5e  6a00                 push 0
// 00454d60  57                   push edi
// 00454d61  e8144f2c00           call 0x719c7a
// 00454d66  83c414               add esp, 0x14
// 00454d69  85c0                 test eax, eax
// 00454d6b  7419                 je 0x454d86
// 00454d6d  6a00                 push 0
// 00454d6f  6814569e00           push 0x9e5614
// 00454d74  68dcf99d00           push 0x9df9dc
// 00454d79  6a00                 push 0
// 00454d7b  57                   push edi
// 00454d7c  e8f94e2c00           call 0x719c7a
// 00454d81  83c414               add esp, 0x14
// 00454d84  8bf0                 mov esi, eax
// 00454d86  6a00                 push 0
// 00454d88  6868569e00           push 0x9e5668
// 00454d8d  68dcf99d00           push 0x9df9dc
// 00454d92  6a00                 push 0
// 00454d94  57                   push edi
// 00454d95  e8e04e2c00           call 0x719c7a
// 00454d9a  83c414               add esp, 0x14
// 00454d9d  85c0                 test eax, eax
// 00454d9f  741b                 je 0x454dbc
// 00454da1  6a00                 push 0
// 00454da3  6868569e00           push 0x9e5668
// 00454da8  68dcf99d00           push 0x9df9dc
// 00454dad  6a00                 push 0
// 00454daf  57                   push edi
// 00454db0  e8c54e2c00           call 0x719c7a
// 00454db5  83c414               add esp, 0x14
// 00454db8  89442420             mov dword ptr [esp + 0x20], eax
// 00454dbc  8b4328               mov eax, dword ptr [ebx + 0x28]
// 00454dbf  45                   inc ebp
// 00454dc0  3be8                 cmp ebp, eax
// 00454dc2  0f8c6cffffff         jl 0x454d34
// 00454dc8  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00454dcc  8b17                 mov edx, dword ptr [edi]
// 00454dce  8b526c               mov edx, dword ptr [edx + 0x6c]
// 00454dd1  6a00                 push 0
// 00454dd3  8d442430             lea eax, [esp + 0x30]
// 00454dd7  50                   push eax
// 00454dd8  8bcf                 mov ecx, edi
// 00454dda  ffd2                 call edx
// 00454ddc  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00454de0  83cb01               or ebx, 1
// 00454de3  6816d28a00           push 0x8ad216
// 00454de8  8bc8                 mov ecx, eax
// 00454dea  c644246801           mov byte ptr [esp + 0x68], 1
// 00454def  895c2418             mov dword ptr [esp + 0x18], ebx
// 00454df3  ff15d4fc8900         call dword ptr [0x89fcd4]
// 00454df9  85c0                 test eax, eax
// 00454dfb  7465                 je 0x454e62
// 00454dfd  8b06                 mov eax, dword ptr [esi]
// 00454dff  8b506c               mov edx, dword ptr [eax + 0x6c]
// 00454e02  6a00                 push 0
// 00454e04  8d4c242c             lea ecx, [esp + 0x2c]
// 00454e08  51                   push ecx
// 00454e09  8bce                 mov ecx, esi
// 00454e0b  ffd2                 call edx
// 00454e0d  83cb02               or ebx, 2
// 00454e10  6848938b00           push 0x8b9348
// 00454e15  8bc8                 mov ecx, eax
// 00454e17  c744246802000000     mov dword ptr [esp + 0x68], 2
// 00454e1f  895c2418             mov dword ptr [esp + 0x18], ebx
// 00454e23  ff15d4fc8900         call dword ptr [0x89fcd4]
// 00454e29  85c0                 test eax, eax
// 00454e2b  7435                 je 0x454e62
// 00454e2d  8b06                 mov eax, dword ptr [esi]
// 00454e2f  8b506c               mov edx, dword ptr [eax + 0x6c]
// 00454e32  6a00                 push 0
// 00454e34  8d4c2428             lea ecx, [esp + 0x28]
// 00454e38  51                   push ecx
// 00454e39  8bce                 mov ecx, esi
// 00454e3b  ffd2                 call edx
// 00454e3d  83cb04               or ebx, 4
// 00454e40  6840938b00           push 0x8b9340
// 00454e45  8bc8                 mov ecx, eax
// 00454e47  c744246803000000     mov dword ptr [esp + 0x68], 3
// 00454e4f  895c2418             mov dword ptr [esp + 0x18], ebx
// 00454e53  ff15d4fc8900         call dword ptr [0x89fcd4]
// 00454e59  c644241301           mov byte ptr [esp + 0x13], 1
// 00454e5e  85c0                 test eax, eax
// 00454e60  7505                 jne 0x454e67
// 00454e62  c644241300           mov byte ptr [esp + 0x13], 0
// 00454e67  f6c304               test bl, 4
// 00454e6a  740d                 je 0x454e79
// 00454e6c  8d4c2424             lea ecx, [esp + 0x24]
// 00454e70  83e3fb               and ebx, 0xfffffffb
// 00454e73  ff1510fd8900         call dword ptr [0x89fd10]
// 00454e79  f6c302               test bl, 2
// 00454e7c  740d                 je 0x454e8b
// 00454e7e  8d4c2428             lea ecx, [esp + 0x28]
// 00454e82  83e3fd               and ebx, 0xfffffffd
// 00454e85  ff1510fd8900         call dword ptr [0x89fd10]
// 00454e8b  c744246400000000     mov dword ptr [esp + 0x64], 0
// 00454e93  f6c301               test bl, 1
// 00454e96  740d                 je 0x454ea5
// 00454e98  8d4c242c             lea ecx, [esp + 0x2c]
// 00454e9c  83e3fe               and ebx, 0xfffffffe
// 00454e9f  ff1510fd8900         call dword ptr [0x89fd10]
// 00454ea5  807c241300           cmp byte ptr [esp + 0x13], 0
// 00454eaa  0f84e1000000         je 0x454f91
// 00454eb0  8b07                 mov eax, dword ptr [edi]
// 00454eb2  8b506c               mov edx, dword ptr [eax + 0x6c]
// 00454eb5  6a00                 push 0
// 00454eb7  8d4c2444             lea ecx, [esp + 0x44]
// 00454ebb  51                   push ecx
// 00454ebc  8bcf                 mov ecx, edi
// 00454ebe  ffd2                 call edx
// 00454ec0  8bf8                 mov edi, eax
// 00454ec2  8b06                 mov eax, dword ptr [esi]
// 00454ec4  8b506c               mov edx, dword ptr [eax + 0x6c]
// 00454ec7  6a00                 push 0
// 00454ec9  8d4c2440             lea ecx, [esp + 0x40]
// 00454ecd  51                   push ecx
// 00454ece  8bce                 mov ecx, esi
// 00454ed0  c644246c04           mov byte ptr [esp + 0x6c], 4
// 00454ed5  ffd2                 call edx
// 00454ed7  50                   push eax
// 00454ed8  8d442474             lea eax, [esp + 0x74]
// 00454edc  50                   push eax
// 00454edd  8d4c2440             lea ecx, [esp + 0x40]
// 00454ee1  51                   push ecx
// 00454ee2  c644247005           mov byte ptr [esp + 0x70], 5
// 00454ee7  e864f4ffff           call 0x454350
// 00454eec  68f4338b00           push 0x8b33f4
// 00454ef1  50                   push eax
// 00454ef2  8d542448             lea edx, [esp + 0x48]
// 00454ef6  52                   push edx
// 00454ef7  c644247c06           mov byte ptr [esp + 0x7c], 6
// 00454efc  e81f7ffbff           call 0x40ce20
// 00454f01  57                   push edi
// 00454f02  50                   push eax
// 00454f03  8d442450             lea eax, [esp + 0x50]
// 00454f07  50                   push eax
// 00454f08  c684248800000007     mov byte ptr [esp + 0x88], 7
// 00454f10  e83bf4ffff           call 0x454350
// 00454f15  683c938b00           push 0x8b933c
// 00454f1a  50                   push eax
// 00454f1b  8d4c2448             lea ecx, [esp + 0x48]
// 00454f1f  51                   push ecx
// 00454f20  c684249400000008     mov byte ptr [esp + 0x94], 8
// 00454f28  e8f37efbff           call 0x40ce20
// 00454f2d  83c430               add esp, 0x30
// 00454f30  8d4c2430             lea ecx, [esp + 0x30]
// 00454f34  ff1510fd8900         call dword ptr [0x89fd10]
// 00454f3a  8d4c2434             lea ecx, [esp + 0x34]
// 00454f3e  ff1510fd8900         call dword ptr [0x89fd10]
// 00454f44  8d4c2438             lea ecx, [esp + 0x38]
// 00454f48  ff1510fd8900         call dword ptr [0x89fd10]
// 00454f4e  8d4c243c             lea ecx, [esp + 0x3c]
// 00454f52  ff1510fd8900         call dword ptr [0x89fd10]
// 00454f58  8d4c2440             lea ecx, [esp + 0x40]
// 00454f5c  c644246400           mov byte ptr [esp + 0x64], 0
// 00454f61  ff1510fd8900         call dword ptr [0x89fd10]
// 00454f67  8d4c241c             lea ecx, [esp + 0x1c]
// 00454f6b  ff15d0fc8900         call dword ptr [0x89fcd0]
// 00454f71  8b15c4b3a300         mov edx, dword ptr [0xa3b3c4]
// 00454f77  50                   push eax
// 00454f78  68400b8b00           push 0x8b0b40
// 00454f7d  52                   push edx
// 00454f7e  ff1518e98900         call dword ptr [0x89e918]
// 00454f84  83c40c               add esp, 0xc
// 00454f87  8d4c241c             lea ecx, [esp + 0x1c]
// 00454f8b  ff1510fd8900         call dword ptr [0x89fd10]
// 00454f91  8b06                 mov eax, dword ptr [esi]
// 00454f93  8b506c               mov edx, dword ptr [eax + 0x6c]
// 00454f96  6a00                 push 0
// 00454f98  8d4c244c             lea ecx, [esp + 0x4c]
// 00454f9c  51                   push ecx
// 00454f9d  8bce                 mov ecx, esi
// 00454f9f  ffd2                 call edx
// 00454fa1  83cb08               or ebx, 8
// 00454fa4  6848938b00           push 0x8b9348
// 00454fa9  8bc8                 mov ecx, eax
// 00454fab  c644246809           mov byte ptr [esp + 0x68], 9
// 00454fb0  895c2418             mov dword ptr [esp + 0x18], ebx
// 00454fb4  ff15d4fc8900         call dword ptr [0x89fcd4]
// 00454fba  85c0                 test eax, eax
// 00454fbc  7434                 je 0x454ff2
// 00454fbe  8b06                 mov eax, dword ptr [esi]
// 00454fc0  8b506c               mov edx, dword ptr [eax + 0x6c]
// 00454fc3  6a00                 push 0
// 00454fc5  8d4c2448             lea ecx, [esp + 0x48]
// 00454fc9  51                   push ecx
// 00454fca  8bce                 mov ecx, esi
// 00454fcc  ffd2                 call edx
// 00454fce  83cb10               or ebx, 0x10
// 00454fd1  6840938b00           push 0x8b9340
// 00454fd6  8bc8                 mov ecx, eax
// 00454fd8  c74424680a000000     mov dword ptr [esp + 0x68], 0xa
// 00454fe0  895c2418             mov dword ptr [esp + 0x18], ebx
// 00454fe4  ff15d4fc8900         call dword ptr [0x89fcd4]
// 00454fea  85c0                 test eax, eax
// 00454fec  7404                 je 0x454ff2
// 00454fee  b301                 mov bl, 1
// 00454ff0  eb02                 jmp 0x454ff4
// 00454ff2  32db                 xor bl, bl
// 00454ff4  f644241410           test byte ptr [esp + 0x14], 0x10
// 00454ff9  740f                 je 0x45500a
// 00454ffb  83642414ef           and dword ptr [esp + 0x14], 0xffffffef
// 00455000  8d4c2444             lea ecx, [esp + 0x44]
// 00455004  ff1510fd8900         call dword ptr [0x89fd10]
// 0045500a  f644241408           test byte ptr [esp + 0x14], 8
// 0045500f  c744246400000000     mov dword ptr [esp + 0x64], 0
// 00455017  740f                 je 0x455028
// 00455019  83642414f7           and dword ptr [esp + 0x14], 0xfffffff7
// 0045501e  8d4c2448             lea ecx, [esp + 0x48]
// 00455022  ff1510fd8900         call dword ptr [0x89fd10]
// 00455028  84db                 test bl, bl
// 0045502a  7474                 je 0x4550a0
// 0045502c  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00455030  e87bb12f00           call 0x7501b0
// 00455035  8bf8                 mov edi, eax
// 00455037  85ff                 test edi, edi
// 00455039  7465                 je 0x4550a0
// 0045503b  8b06                 mov eax, dword ptr [esi]
// 0045503d  8b506c               mov edx, dword ptr [eax + 0x6c]
// 00455040  6a00                 push 0
// 00455042  8d4c245c             lea ecx, [esp + 0x5c]
// 00455046  51                   push ecx
// 00455047  8bce                 mov ecx, esi
// 00455049  ffd2                 call edx
// 0045504b  50                   push eax
// 0045504c  8d442474             lea eax, [esp + 0x74]
// 00455050  50                   push eax
// 00455051  8d4c245c             lea ecx, [esp + 0x5c]
// 00455055  51                   push ecx
// 00455056  c64424700b           mov byte ptr [esp + 0x70], 0xb
// 0045505b  e8f0f2ffff           call 0x454350
// 00455060  83c408               add esp, 8
// 00455063  8bd4                 mov edx, esp
// 00455065  89642450             mov dword ptr [esp + 0x50], esp
// 00455069  6838938b00           push 0x8b9338
// 0045506e  50                   push eax
// 0045506f  52                   push edx
// 00455070  c64424740c           mov byte ptr [esp + 0x74], 0xc
// 00455075  e8a67dfbff           call 0x40ce20
// 0045507a  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0045507e  83c40c               add esp, 0xc
// 00455081  57                   push edi
// 00455082  e849fcffff           call 0x454cd0
// 00455087  8d4c2454             lea ecx, [esp + 0x54]
// 0045508b  ff1510fd8900         call dword ptr [0x89fd10]
// 00455091  8d4c2458             lea ecx, [esp + 0x58]
// 00455095  c644246400           mov byte ptr [esp + 0x64], 0
// 0045509a  ff1510fd8900         call dword ptr [0x89fd10]
// 004550a0  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004550a4  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 004550a8  47                   inc edi
// 004550a9  897c2418             mov dword ptr [esp + 0x18], edi
// 004550ad  e8fecd2f00           call 0x751eb0
// 004550b2  3bf8                 cmp edi, eax
// 004550b4  0f8c59fcffff         jl 0x454d13
// 004550ba  8d4c2470             lea ecx, [esp + 0x70]
// 004550be  ff1510fd8900         call dword ptr [0x89fd10]
// 004550c4  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 004550c8  5f                   pop edi
// 004550c9  5e                   pop esi
// 004550ca  5d                   pop ebp
// 004550cb  64890d00000000       mov dword ptr fs:[0], ecx
// 004550d2  5b                   pop ebx
// 004550d3  83c458               add esp, 0x58
// 004550d6  c20800               ret 8
// 004550d9  e8063c2c00           call 0x718ce4
// copied from an identical function in another client (function ?dumpStats@CRobloxReportView@@QAEXPAVCXTPReportRecords@@V?$CStringT_@D@@@Z)

// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
#include <stdio.h>

template <class T> class CStringT_ {
public:
    __declspec(noinline) CStringT_(const CStringT_& p) { m_pszData = p.m_pszData; }
    __declspec(noinline) ~CStringT_() throw() { m_pszData = 0; }
    __declspec(noinline) int Compare(const T* p) const { return p == m_pszData; }
    __declspec(noinline) operator const T*() const throw() { return m_pszData; }
    T* m_pszData;
};
extern template class __declspec(dllimport) CStringT_<char>;
typedef CStringT_<char> CString;

CString __cdecl operator+(const CString& a, const CString& b);
CString __cdecl operator+(const CString& a, const char* b);

inline bool operator!=(const CString& a, const char* b) { return a.Compare(b) != 0; }

__declspec(noreturn) void __stdcall AfxThrowInvalidArgException();

class CXTPReportColumn;
class CXTPReportRecordItem {
public:
    virtual ~CXTPReportRecordItem();
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26();
    virtual CString GetCaption(CXTPReportColumn* pColumn);
};

class CXTPReportRecords;
template <class TYPE> class CArray_ {
public:
    virtual ~CArray_();
    TYPE* m_pData;
    int m_nSize;
    int GetSize() const { return m_nSize; }
    const TYPE& GetAt(int nIndex) const
    {
        if (nIndex >= 0 && nIndex < m_nSize)
            return m_pData[nIndex];
        AfxThrowInvalidArgException();
    }
};

class CXTPReportRecord {
public:
    char pad[0x20];
    CArray_<CXTPReportRecordItem*> m_arrItems;
    int GetItemCount() const { return (int)m_arrItems.GetSize(); }
    CXTPReportRecordItem* GetItem(int nIndex) const
    {
        return nIndex >= 0 && nIndex < GetItemCount() ? m_arrItems.GetAt(nIndex) : 0;
    }
    CXTPReportRecords* GetChilds();
};

class CXTPReportRecords {
public:
    int GetCount() const;
    CXTPReportRecord* GetAt(int nIndex) const;
};

extern FILE* statsFile;

class CRobloxReportView {
public:
    class CStatsItemRecord {
    public:
        class CNameItem : public CXTPReportRecordItem {};
        class CValueItem : public CXTPReportRecordItem {};
    };
    void dumpStats(CXTPReportRecords* records, CString prefix);
};

void CRobloxReportView::dumpStats(CXTPReportRecords* records, CString prefix)
{
    for (int i = 0; i < records->GetCount(); i++) {
        CXTPReportRecord* record = records->GetAt(i);
        CStatsItemRecord::CNameItem* nameItem;
        CStatsItemRecord::CValueItem* valueItem;
        for (int j = 0; j < record->GetItemCount(); j++) {
            CXTPReportRecordItem* item = record->GetItem(j);
            if (dynamic_cast<CStatsItemRecord::CNameItem*>(item))
                nameItem = dynamic_cast<CStatsItemRecord::CNameItem*>(item);
            if (dynamic_cast<CStatsItemRecord::CValueItem*>(item))
                valueItem = dynamic_cast<CStatsItemRecord::CValueItem*>(item);
        }
        if (valueItem->GetCaption(0) != "" && nameItem->GetCaption(0) != "Render" && nameItem->GetCaption(0) != "Sound") {
            CString line = prefix + nameItem->GetCaption(0) + " = " + valueItem->GetCaption(0) + "\n";
            fprintf(statsFile, "%s", (const char*)line);
        }
        if (nameItem->GetCaption(0) != "Render" && nameItem->GetCaption(0) != "Sound") {
            CXTPReportRecords* children = record->GetChilds();
            if (children)
                dumpStats(children, prefix + nameItem->GetCaption(0) + "::");
        }
    }
}