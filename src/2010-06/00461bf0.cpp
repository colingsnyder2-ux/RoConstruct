// from server: 100% by Yeetserama
// roc 2010-06 00461bf0  unit: CRobloxReportView::CStatsItemRecord::CValueItem  size: 1038 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00461bf0
//
// 00461bf0  6aff                 push -1
// 00461bf2  683a379800           push 0x98373a
// 00461bf7  64a100000000         mov eax, dword ptr fs:[0]
// 00461bfd  50                   push eax
// 00461bfe  64892500000000       mov dword ptr fs:[0], esp
// 00461c05  83ec4c               sub esp, 0x4c
// 00461c08  53                   push ebx
// 00461c09  55                   push ebp
// 00461c0a  56                   push esi
// 00461c0b  33c0                 xor eax, eax
// 00461c0d  57                   push edi
// 00461c0e  894c2450             mov dword ptr [esp + 0x50], ecx
// 00461c12  89442414             mov dword ptr [esp + 0x14], eax
// 00461c16  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 00461c1a  89442464             mov dword ptr [esp + 0x64], eax
// 00461c1e  89442418             mov dword ptr [esp + 0x18], eax
// 00461c22  e859fb3700           call 0x7e1780
// 00461c27  85c0                 test eax, eax
// 00461c29  0f8eab030000         jle 0x461fda
// 00461c2f  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 00461c33  8b442418             mov eax, dword ptr [esp + 0x18]
// 00461c37  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 00461c3b  50                   push eax
// 00461c3c  e86ff03700           call 0x7e0cb0
// 00461c41  8bd8                 mov ebx, eax
// 00461c43  8b4328               mov eax, dword ptr [ebx + 0x28]
// 00461c46  33ed                 xor ebp, ebp
// 00461c48  895c244c             mov dword ptr [esp + 0x4c], ebx
// 00461c4c  85c0                 test eax, eax
// 00461c4e  0f8e94000000         jle 0x461ce8
// 00461c54  85ed                 test ebp, ebp
// 00461c56  7c18                 jl 0x461c70
// 00461c58  3be8                 cmp ebp, eax
// 00461c5a  7d14                 jge 0x461c70
// 00461c5c  3b6b28               cmp ebp, dword ptr [ebx + 0x28]
// 00461c5f  0f8d94030000         jge 0x461ff9
// 00461c65  8b4b24               mov ecx, dword ptr [ebx + 0x24]
// 00461c68  8b3ca9               mov edi, dword ptr [ecx + ebp*4]
// 00461c6b  8d04a9               lea eax, [ecx + ebp*4]
// 00461c6e  eb02                 jmp 0x461c72
// 00461c70  33ff                 xor edi, edi
// 00461c72  6a00                 push 0
// 00461c74  688c3bb800           push 0xb83b8c
// 00461c79  684cc9b700           push 0xb7c94c
// 00461c7e  6a00                 push 0
// 00461c80  57                   push edi
// 00461c81  e8646f3400           call 0x7a8bea
// 00461c86  83c414               add esp, 0x14
// 00461c89  85c0                 test eax, eax
// 00461c8b  7419                 je 0x461ca6
// 00461c8d  6a00                 push 0
// 00461c8f  688c3bb800           push 0xb83b8c
// 00461c94  684cc9b700           push 0xb7c94c
// 00461c99  6a00                 push 0
// 00461c9b  57                   push edi
// 00461c9c  e8496f3400           call 0x7a8bea
// 00461ca1  83c414               add esp, 0x14
// 00461ca4  8bf0                 mov esi, eax
// 00461ca6  6a00                 push 0
// 00461ca8  68e03bb800           push 0xb83be0
// 00461cad  684cc9b700           push 0xb7c94c
// 00461cb2  6a00                 push 0
// 00461cb4  57                   push edi
// 00461cb5  e8306f3400           call 0x7a8bea
// 00461cba  83c414               add esp, 0x14
// 00461cbd  85c0                 test eax, eax
// 00461cbf  741b                 je 0x461cdc
// 00461cc1  6a00                 push 0
// 00461cc3  68e03bb800           push 0xb83be0
// 00461cc8  684cc9b700           push 0xb7c94c
// 00461ccd  6a00                 push 0
// 00461ccf  57                   push edi
// 00461cd0  e8156f3400           call 0x7a8bea
// 00461cd5  83c414               add esp, 0x14
// 00461cd8  89442420             mov dword ptr [esp + 0x20], eax
// 00461cdc  8b4328               mov eax, dword ptr [ebx + 0x28]
// 00461cdf  45                   inc ebp
// 00461ce0  3be8                 cmp ebp, eax
// 00461ce2  0f8c6cffffff         jl 0x461c54
// 00461ce8  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00461cec  8b17                 mov edx, dword ptr [edi]
// 00461cee  8b526c               mov edx, dword ptr [edx + 0x6c]
// 00461cf1  6a00                 push 0
// 00461cf3  8d442430             lea eax, [esp + 0x30]
// 00461cf7  50                   push eax
// 00461cf8  8bcf                 mov ecx, edi
// 00461cfa  ffd2                 call edx
// 00461cfc  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00461d00  83cb01               or ebx, 1
// 00461d03  68fe08a000           push 0xa008fe
// 00461d08  8bc8                 mov ecx, eax
// 00461d0a  c644246801           mov byte ptr [esp + 0x68], 1
// 00461d0f  895c2418             mov dword ptr [esp + 0x18], ebx
// 00461d13  ff15b4ce9e00         call dword ptr [0x9eceb4]
// 00461d19  85c0                 test eax, eax
// 00461d1b  7465                 je 0x461d82
// 00461d1d  8b06                 mov eax, dword ptr [esi]
// 00461d1f  8b506c               mov edx, dword ptr [eax + 0x6c]
// 00461d22  6a00                 push 0
// 00461d24  8d4c242c             lea ecx, [esp + 0x2c]
// 00461d28  51                   push ecx
// 00461d29  8bce                 mov ecx, esi
// 00461d2b  ffd2                 call edx
// 00461d2d  83cb02               or ebx, 2
// 00461d30  6828e7a000           push 0xa0e728
// 00461d35  8bc8                 mov ecx, eax
// 00461d37  c744246802000000     mov dword ptr [esp + 0x68], 2
// 00461d3f  895c2418             mov dword ptr [esp + 0x18], ebx
// 00461d43  ff15b4ce9e00         call dword ptr [0x9eceb4]
// 00461d49  85c0                 test eax, eax
// 00461d4b  7435                 je 0x461d82
// 00461d4d  8b06                 mov eax, dword ptr [esi]
// 00461d4f  8b506c               mov edx, dword ptr [eax + 0x6c]
// 00461d52  6a00                 push 0
// 00461d54  8d4c2428             lea ecx, [esp + 0x28]
// 00461d58  51                   push ecx
// 00461d59  8bce                 mov ecx, esi
// 00461d5b  ffd2                 call edx
// 00461d5d  83cb04               or ebx, 4
// 00461d60  6820e7a000           push 0xa0e720
// 00461d65  8bc8                 mov ecx, eax
// 00461d67  c744246803000000     mov dword ptr [esp + 0x68], 3
// 00461d6f  895c2418             mov dword ptr [esp + 0x18], ebx
// 00461d73  ff15b4ce9e00         call dword ptr [0x9eceb4]
// 00461d79  c644241301           mov byte ptr [esp + 0x13], 1
// 00461d7e  85c0                 test eax, eax
// 00461d80  7505                 jne 0x461d87
// 00461d82  c644241300           mov byte ptr [esp + 0x13], 0
// 00461d87  f6c304               test bl, 4
// 00461d8a  740d                 je 0x461d99
// 00461d8c  8d4c2424             lea ecx, [esp + 0x24]
// 00461d90  83e3fb               and ebx, 0xfffffffb
// 00461d93  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00461d99  f6c302               test bl, 2
// 00461d9c  740d                 je 0x461dab
// 00461d9e  8d4c2428             lea ecx, [esp + 0x28]
// 00461da2  83e3fd               and ebx, 0xfffffffd
// 00461da5  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00461dab  c744246400000000     mov dword ptr [esp + 0x64], 0
// 00461db3  f6c301               test bl, 1
// 00461db6  740d                 je 0x461dc5
// 00461db8  8d4c242c             lea ecx, [esp + 0x2c]
// 00461dbc  83e3fe               and ebx, 0xfffffffe
// 00461dbf  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00461dc5  807c241300           cmp byte ptr [esp + 0x13], 0
// 00461dca  0f84e1000000         je 0x461eb1
// 00461dd0  8b07                 mov eax, dword ptr [edi]
// 00461dd2  8b506c               mov edx, dword ptr [eax + 0x6c]
// 00461dd5  6a00                 push 0
// 00461dd7  8d4c2444             lea ecx, [esp + 0x44]
// 00461ddb  51                   push ecx
// 00461ddc  8bcf                 mov ecx, edi
// 00461dde  ffd2                 call edx
// 00461de0  8bf8                 mov edi, eax
// 00461de2  8b06                 mov eax, dword ptr [esi]
// 00461de4  8b506c               mov edx, dword ptr [eax + 0x6c]
// 00461de7  6a00                 push 0
// 00461de9  8d4c2440             lea ecx, [esp + 0x40]
// 00461ded  51                   push ecx
// 00461dee  8bce                 mov ecx, esi
// 00461df0  c644246c04           mov byte ptr [esp + 0x6c], 4
// 00461df5  ffd2                 call edx
// 00461df7  50                   push eax
// 00461df8  8d442474             lea eax, [esp + 0x74]
// 00461dfc  50                   push eax
// 00461dfd  8d4c2440             lea ecx, [esp + 0x40]
// 00461e01  51                   push ecx
// 00461e02  c644247005           mov byte ptr [esp + 0x70], 5
// 00461e07  e864f4ffff           call 0x461270
// 00461e0c  68e46ea000           push 0xa06ee4
// 00461e11  50                   push eax
// 00461e12  8d542448             lea edx, [esp + 0x48]
// 00461e16  52                   push edx
// 00461e17  c644247c06           mov byte ptr [esp + 0x7c], 6
// 00461e1c  e8efb4faff           call 0x40d310
// 00461e21  57                   push edi
// 00461e22  50                   push eax
// 00461e23  8d442450             lea eax, [esp + 0x50]
// 00461e27  50                   push eax
// 00461e28  c684248800000007     mov byte ptr [esp + 0x88], 7
// 00461e30  e83bf4ffff           call 0x461270
// 00461e35  681ce7a000           push 0xa0e71c
// 00461e3a  50                   push eax
// 00461e3b  8d4c2448             lea ecx, [esp + 0x48]
// 00461e3f  51                   push ecx
// 00461e40  c684249400000008     mov byte ptr [esp + 0x94], 8
// 00461e48  e8c3b4faff           call 0x40d310
// 00461e4d  83c430               add esp, 0x30
// 00461e50  8d4c2430             lea ecx, [esp + 0x30]
// 00461e54  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00461e5a  8d4c2434             lea ecx, [esp + 0x34]
// 00461e5e  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00461e64  8d4c2438             lea ecx, [esp + 0x38]
// 00461e68  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00461e6e  8d4c243c             lea ecx, [esp + 0x3c]
// 00461e72  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00461e78  8d4c2440             lea ecx, [esp + 0x40]
// 00461e7c  c644246400           mov byte ptr [esp + 0x64], 0
// 00461e81  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00461e87  8d4c241c             lea ecx, [esp + 0x1c]
// 00461e8b  ff15b0ce9e00         call dword ptr [0x9eceb0]
// 00461e91  8b152c1ec000         mov edx, dword ptr [0xc01e2c]
// 00461e97  50                   push eax
// 00461e98  68e444a000           push 0xa044e4
// 00461e9d  52                   push edx
// 00461e9e  ff151ca79e00         call dword ptr [0x9ea71c]
// 00461ea4  83c40c               add esp, 0xc
// 00461ea7  8d4c241c             lea ecx, [esp + 0x1c]
// 00461eab  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00461eb1  8b06                 mov eax, dword ptr [esi]
// 00461eb3  8b506c               mov edx, dword ptr [eax + 0x6c]
// 00461eb6  6a00                 push 0
// 00461eb8  8d4c244c             lea ecx, [esp + 0x4c]
// 00461ebc  51                   push ecx
// 00461ebd  8bce                 mov ecx, esi
// 00461ebf  ffd2                 call edx
// 00461ec1  83cb08               or ebx, 8
// 00461ec4  6828e7a000           push 0xa0e728
// 00461ec9  8bc8                 mov ecx, eax
// 00461ecb  c644246809           mov byte ptr [esp + 0x68], 9
// 00461ed0  895c2418             mov dword ptr [esp + 0x18], ebx
// 00461ed4  ff15b4ce9e00         call dword ptr [0x9eceb4]
// 00461eda  85c0                 test eax, eax
// 00461edc  7434                 je 0x461f12
// 00461ede  8b06                 mov eax, dword ptr [esi]
// 00461ee0  8b506c               mov edx, dword ptr [eax + 0x6c]
// 00461ee3  6a00                 push 0
// 00461ee5  8d4c2448             lea ecx, [esp + 0x48]
// 00461ee9  51                   push ecx
// 00461eea  8bce                 mov ecx, esi
// 00461eec  ffd2                 call edx
// 00461eee  83cb10               or ebx, 0x10
// 00461ef1  6820e7a000           push 0xa0e720
// 00461ef6  8bc8                 mov ecx, eax
// 00461ef8  c74424680a000000     mov dword ptr [esp + 0x68], 0xa
// 00461f00  895c2418             mov dword ptr [esp + 0x18], ebx
// 00461f04  ff15b4ce9e00         call dword ptr [0x9eceb4]
// 00461f0a  85c0                 test eax, eax
// 00461f0c  7404                 je 0x461f12
// 00461f0e  b301                 mov bl, 1
// 00461f10  eb02                 jmp 0x461f14
// 00461f12  32db                 xor bl, bl
// 00461f14  f644241410           test byte ptr [esp + 0x14], 0x10
// 00461f19  740f                 je 0x461f2a
// 00461f1b  83642414ef           and dword ptr [esp + 0x14], 0xffffffef
// 00461f20  8d4c2444             lea ecx, [esp + 0x44]
// 00461f24  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00461f2a  f644241408           test byte ptr [esp + 0x14], 8
// 00461f2f  c744246400000000     mov dword ptr [esp + 0x64], 0
// 00461f37  740f                 je 0x461f48
// 00461f39  83642414f7           and dword ptr [esp + 0x14], 0xfffffff7
// 00461f3e  8d4c2448             lea ecx, [esp + 0x48]
// 00461f42  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00461f48  84db                 test bl, bl
// 00461f4a  7474                 je 0x461fc0
// 00461f4c  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00461f50  e89bd03700           call 0x7deff0
// 00461f55  8bf8                 mov edi, eax
// 00461f57  85ff                 test edi, edi
// 00461f59  7465                 je 0x461fc0
// 00461f5b  8b06                 mov eax, dword ptr [esi]
// 00461f5d  8b506c               mov edx, dword ptr [eax + 0x6c]
// 00461f60  6a00                 push 0
// 00461f62  8d4c245c             lea ecx, [esp + 0x5c]
// 00461f66  51                   push ecx
// 00461f67  8bce                 mov ecx, esi
// 00461f69  ffd2                 call edx
// 00461f6b  50                   push eax
// 00461f6c  8d442474             lea eax, [esp + 0x74]
// 00461f70  50                   push eax
// 00461f71  8d4c245c             lea ecx, [esp + 0x5c]
// 00461f75  51                   push ecx
// 00461f76  c64424700b           mov byte ptr [esp + 0x70], 0xb
// 00461f7b  e8f0f2ffff           call 0x461270
// 00461f80  83c408               add esp, 8
// 00461f83  8bd4                 mov edx, esp
// 00461f85  89642450             mov dword ptr [esp + 0x50], esp
// 00461f89  6818e7a000           push 0xa0e718
// 00461f8e  50                   push eax
// 00461f8f  52                   push edx
// 00461f90  c64424740c           mov byte ptr [esp + 0x74], 0xc
// 00461f95  e876b3faff           call 0x40d310
// 00461f9a  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 00461f9e  83c40c               add esp, 0xc
// 00461fa1  57                   push edi
// 00461fa2  e849fcffff           call 0x461bf0
// 00461fa7  8d4c2454             lea ecx, [esp + 0x54]
// 00461fab  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00461fb1  8d4c2458             lea ecx, [esp + 0x58]
// 00461fb5  c644246400           mov byte ptr [esp + 0x64], 0
// 00461fba  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00461fc0  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00461fc4  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 00461fc8  47                   inc edi
// 00461fc9  897c2418             mov dword ptr [esp + 0x18], edi
// 00461fcd  e8aef73700           call 0x7e1780
// 00461fd2  3bf8                 cmp edi, eax
// 00461fd4  0f8c59fcffff         jl 0x461c33
// 00461fda  8d4c2470             lea ecx, [esp + 0x70]
// 00461fde  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00461fe4  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 00461fe8  5f                   pop edi
// 00461fe9  5e                   pop esi
// 00461fea  5d                   pop ebp
// 00461feb  64890d00000000       mov dword ptr fs:[0], ecx
// 00461ff2  5b                   pop ebx
// 00461ff3  83c458               add esp, 0x58
// 00461ff6  c20800               ret 8
// 00461ff9  e84e5c3400           call 0x7a7c4c
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