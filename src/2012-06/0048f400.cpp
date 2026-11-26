// from server: 100% by Xemicl
// roc 2012-06 0048f400  unit: CRobloxReportPaneView  size: 1038 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0048f400
//
// 0048f400  6aff                 push -1
// 0048f402  68ea2aaa00           push 0xaa2aea
// 0048f407  64a100000000         mov eax, dword ptr fs:[0]
// 0048f40d  50                   push eax
// 0048f40e  64892500000000       mov dword ptr fs:[0], esp
// 0048f415  83ec4c               sub esp, 0x4c
// 0048f418  53                   push ebx
// 0048f419  55                   push ebp
// 0048f41a  56                   push esi
// 0048f41b  33c0                 xor eax, eax
// 0048f41d  57                   push edi
// 0048f41e  894c2450             mov dword ptr [esp + 0x50], ecx
// 0048f422  89442414             mov dword ptr [esp + 0x14], eax
// 0048f426  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 0048f42a  89442464             mov dword ptr [esp + 0x64], eax
// 0048f42e  89442418             mov dword ptr [esp + 0x18], eax
// 0048f432  e839b85200           call 0x9bac70
// 0048f437  85c0                 test eax, eax
// 0048f439  0f8eab030000         jle 0x48f7ea
// 0048f43f  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0048f443  8b442418             mov eax, dword ptr [esp + 0x18]
// 0048f447  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 0048f44b  50                   push eax
// 0048f44c  e82fb85200           call 0x9bac80
// 0048f451  8bd8                 mov ebx, eax
// 0048f453  8b4328               mov eax, dword ptr [ebx + 0x28]
// 0048f456  33ed                 xor ebp, ebp
// 0048f458  895c244c             mov dword ptr [esp + 0x4c], ebx
// 0048f45c  85c0                 test eax, eax
// 0048f45e  0f8e94000000         jle 0x48f4f8
// 0048f464  85ed                 test ebp, ebp
// 0048f466  7c18                 jl 0x48f480
// 0048f468  3be8                 cmp ebp, eax
// 0048f46a  7d14                 jge 0x48f480
// 0048f46c  3b6b28               cmp ebp, dword ptr [ebx + 0x28]
// 0048f46f  0f8d94030000         jge 0x48f809
// 0048f475  8b4b24               mov ecx, dword ptr [ebx + 0x24]
// 0048f478  8b3ca9               mov edi, dword ptr [ecx + ebp*4]
// 0048f47b  8d04a9               lea eax, [ecx + ebp*4]
// 0048f47e  eb02                 jmp 0x48f482
// 0048f480  33ff                 xor edi, edi
// 0048f482  6a00                 push 0
// 0048f484  68b0fdd600           push 0xd6fdb0
// 0048f489  68244dd600           push 0xd64d24
// 0048f48e  6a00                 push 0
// 0048f490  57                   push edi
// 0048f491  e8b23f4f00           call 0x983448
// 0048f496  83c414               add esp, 0x14
// 0048f499  85c0                 test eax, eax
// 0048f49b  7419                 je 0x48f4b6
// 0048f49d  6a00                 push 0
// 0048f49f  68b0fdd600           push 0xd6fdb0
// 0048f4a4  68244dd600           push 0xd64d24
// 0048f4a9  6a00                 push 0
// 0048f4ab  57                   push edi
// 0048f4ac  e8973f4f00           call 0x983448
// 0048f4b1  83c414               add esp, 0x14
// 0048f4b4  8bf0                 mov esi, eax
// 0048f4b6  6a00                 push 0
// 0048f4b8  6874fdd600           push 0xd6fd74
// 0048f4bd  68244dd600           push 0xd64d24
// 0048f4c2  6a00                 push 0
// 0048f4c4  57                   push edi
// 0048f4c5  e87e3f4f00           call 0x983448
// 0048f4ca  83c414               add esp, 0x14
// 0048f4cd  85c0                 test eax, eax
// 0048f4cf  741b                 je 0x48f4ec
// 0048f4d1  6a00                 push 0
// 0048f4d3  6874fdd600           push 0xd6fd74
// 0048f4d8  68244dd600           push 0xd64d24
// 0048f4dd  6a00                 push 0
// 0048f4df  57                   push edi
// 0048f4e0  e8633f4f00           call 0x983448
// 0048f4e5  83c414               add esp, 0x14
// 0048f4e8  89442420             mov dword ptr [esp + 0x20], eax
// 0048f4ec  8b4328               mov eax, dword ptr [ebx + 0x28]
// 0048f4ef  45                   inc ebp
// 0048f4f0  3be8                 cmp ebp, eax
// 0048f4f2  0f8c6cffffff         jl 0x48f464
// 0048f4f8  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0048f4fc  8b17                 mov edx, dword ptr [edi]
// 0048f4fe  8b526c               mov edx, dword ptr [edx + 0x6c]
// 0048f501  6a00                 push 0
// 0048f503  8d442430             lea eax, [esp + 0x30]
// 0048f507  50                   push eax
// 0048f508  8bcf                 mov ecx, edi
// 0048f50a  ffd2                 call edx
// 0048f50c  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0048f510  83cb01               or ebx, 1
// 0048f513  68e83bb400           push 0xb43be8
// 0048f518  8bc8                 mov ecx, eax
// 0048f51a  c644246801           mov byte ptr [esp + 0x68], 1
// 0048f51f  895c2418             mov dword ptr [esp + 0x18], ebx
// 0048f523  ff159c47b200         call dword ptr [0xb2479c]
// 0048f529  85c0                 test eax, eax
// 0048f52b  7465                 je 0x48f592
// 0048f52d  8b06                 mov eax, dword ptr [esi]
// 0048f52f  8b506c               mov edx, dword ptr [eax + 0x6c]
// 0048f532  6a00                 push 0
// 0048f534  8d4c242c             lea ecx, [esp + 0x2c]
// 0048f538  51                   push ecx
// 0048f539  8bce                 mov ecx, esi
// 0048f53b  ffd2                 call edx
// 0048f53d  83cb02               or ebx, 2
// 0048f540  6854d8b500           push 0xb5d854
// 0048f545  8bc8                 mov ecx, eax
// 0048f547  c744246802000000     mov dword ptr [esp + 0x68], 2
// 0048f54f  895c2418             mov dword ptr [esp + 0x18], ebx
// 0048f553  ff159c47b200         call dword ptr [0xb2479c]
// 0048f559  85c0                 test eax, eax
// 0048f55b  7435                 je 0x48f592
// 0048f55d  8b06                 mov eax, dword ptr [esi]
// 0048f55f  8b506c               mov edx, dword ptr [eax + 0x6c]
// 0048f562  6a00                 push 0
// 0048f564  8d4c2428             lea ecx, [esp + 0x28]
// 0048f568  51                   push ecx
// 0048f569  8bce                 mov ecx, esi
// 0048f56b  ffd2                 call edx
// 0048f56d  83cb04               or ebx, 4
// 0048f570  684cd8b500           push 0xb5d84c
// 0048f575  8bc8                 mov ecx, eax
// 0048f577  c744246803000000     mov dword ptr [esp + 0x68], 3
// 0048f57f  895c2418             mov dword ptr [esp + 0x18], ebx
// 0048f583  ff159c47b200         call dword ptr [0xb2479c]
// 0048f589  c644241301           mov byte ptr [esp + 0x13], 1
// 0048f58e  85c0                 test eax, eax
// 0048f590  7505                 jne 0x48f597
// 0048f592  c644241300           mov byte ptr [esp + 0x13], 0
// 0048f597  f6c304               test bl, 4
// 0048f59a  740d                 je 0x48f5a9
// 0048f59c  8d4c2424             lea ecx, [esp + 0x24]
// 0048f5a0  83e3fb               and ebx, 0xfffffffb
// 0048f5a3  ff15d047b200         call dword ptr [0xb247d0]
// 0048f5a9  f6c302               test bl, 2
// 0048f5ac  740d                 je 0x48f5bb
// 0048f5ae  8d4c2428             lea ecx, [esp + 0x28]
// 0048f5b2  83e3fd               and ebx, 0xfffffffd
// 0048f5b5  ff15d047b200         call dword ptr [0xb247d0]
// 0048f5bb  c744246400000000     mov dword ptr [esp + 0x64], 0
// 0048f5c3  f6c301               test bl, 1
// 0048f5c6  740d                 je 0x48f5d5
// 0048f5c8  8d4c242c             lea ecx, [esp + 0x2c]
// 0048f5cc  83e3fe               and ebx, 0xfffffffe
// 0048f5cf  ff15d047b200         call dword ptr [0xb247d0]
// 0048f5d5  807c241300           cmp byte ptr [esp + 0x13], 0
// 0048f5da  0f84e1000000         je 0x48f6c1
// 0048f5e0  8b07                 mov eax, dword ptr [edi]
// 0048f5e2  8b506c               mov edx, dword ptr [eax + 0x6c]
// 0048f5e5  6a00                 push 0
// 0048f5e7  8d4c2444             lea ecx, [esp + 0x44]
// 0048f5eb  51                   push ecx
// 0048f5ec  8bcf                 mov ecx, edi
// 0048f5ee  ffd2                 call edx
// 0048f5f0  8bf8                 mov edi, eax
// 0048f5f2  8b06                 mov eax, dword ptr [esi]
// 0048f5f4  8b506c               mov edx, dword ptr [eax + 0x6c]
// 0048f5f7  6a00                 push 0
// 0048f5f9  8d4c2440             lea ecx, [esp + 0x40]
// 0048f5fd  51                   push ecx
// 0048f5fe  8bce                 mov ecx, esi
// 0048f600  c644246c04           mov byte ptr [esp + 0x6c], 4
// 0048f605  ffd2                 call edx
// 0048f607  50                   push eax
// 0048f608  8d442474             lea eax, [esp + 0x74]
// 0048f60c  50                   push eax
// 0048f60d  8d4c2440             lea ecx, [esp + 0x40]
// 0048f611  51                   push ecx
// 0048f612  c644247005           mov byte ptr [esp + 0x70], 5
// 0048f617  e8d45ffcff           call 0x4555f0
// 0048f61c  68442fb500           push 0xb52f44
// 0048f621  50                   push eax
// 0048f622  8d542448             lea edx, [esp + 0x48]
// 0048f626  52                   push edx
// 0048f627  c644247c06           mov byte ptr [esp + 0x7c], 6
// 0048f62c  e86f63f8ff           call 0x4159a0
// 0048f631  57                   push edi
// 0048f632  50                   push eax
// 0048f633  8d442450             lea eax, [esp + 0x50]
// 0048f637  50                   push eax
// 0048f638  c684248800000007     mov byte ptr [esp + 0x88], 7
// 0048f640  e8ab5ffcff           call 0x4555f0
// 0048f645  6848d8b500           push 0xb5d848
// 0048f64a  50                   push eax
// 0048f64b  8d4c2448             lea ecx, [esp + 0x48]
// 0048f64f  51                   push ecx
// 0048f650  c684249400000008     mov byte ptr [esp + 0x94], 8
// 0048f658  e84363f8ff           call 0x4159a0
// 0048f65d  83c430               add esp, 0x30
// 0048f660  8d4c2430             lea ecx, [esp + 0x30]
// 0048f664  ff15d047b200         call dword ptr [0xb247d0]
// 0048f66a  8d4c2434             lea ecx, [esp + 0x34]
// 0048f66e  ff15d047b200         call dword ptr [0xb247d0]
// 0048f674  8d4c2438             lea ecx, [esp + 0x38]
// 0048f678  ff15d047b200         call dword ptr [0xb247d0]
// 0048f67e  8d4c243c             lea ecx, [esp + 0x3c]
// 0048f682  ff15d047b200         call dword ptr [0xb247d0]
// 0048f688  8d4c2440             lea ecx, [esp + 0x40]
// 0048f68c  c644246400           mov byte ptr [esp + 0x64], 0
// 0048f691  ff15d047b200         call dword ptr [0xb247d0]
// 0048f697  8d4c241c             lea ecx, [esp + 0x1c]
// 0048f69b  ff159847b200         call dword ptr [0xb24798]
// 0048f6a1  8b158ca6e100         mov edx, dword ptr [0xe1a68c]
// 0048f6a7  50                   push eax
// 0048f6a8  68c0f3b400           push 0xb4f3c0
// 0048f6ad  52                   push edx
// 0048f6ae  ff15a829b200         call dword ptr [0xb229a8]
// 0048f6b4  83c40c               add esp, 0xc
// 0048f6b7  8d4c241c             lea ecx, [esp + 0x1c]
// 0048f6bb  ff15d047b200         call dword ptr [0xb247d0]
// 0048f6c1  8b06                 mov eax, dword ptr [esi]
// 0048f6c3  8b506c               mov edx, dword ptr [eax + 0x6c]
// 0048f6c6  6a00                 push 0
// 0048f6c8  8d4c244c             lea ecx, [esp + 0x4c]
// 0048f6cc  51                   push ecx
// 0048f6cd  8bce                 mov ecx, esi
// 0048f6cf  ffd2                 call edx
// 0048f6d1  83cb08               or ebx, 8
// 0048f6d4  6854d8b500           push 0xb5d854
// 0048f6d9  8bc8                 mov ecx, eax
// 0048f6db  c644246809           mov byte ptr [esp + 0x68], 9
// 0048f6e0  895c2418             mov dword ptr [esp + 0x18], ebx
// 0048f6e4  ff159c47b200         call dword ptr [0xb2479c]
// 0048f6ea  85c0                 test eax, eax
// 0048f6ec  7434                 je 0x48f722
// 0048f6ee  8b06                 mov eax, dword ptr [esi]
// 0048f6f0  8b506c               mov edx, dword ptr [eax + 0x6c]
// 0048f6f3  6a00                 push 0
// 0048f6f5  8d4c2448             lea ecx, [esp + 0x48]
// 0048f6f9  51                   push ecx
// 0048f6fa  8bce                 mov ecx, esi
// 0048f6fc  ffd2                 call edx
// 0048f6fe  83cb10               or ebx, 0x10
// 0048f701  684cd8b500           push 0xb5d84c
// 0048f706  8bc8                 mov ecx, eax
// 0048f708  c74424680a000000     mov dword ptr [esp + 0x68], 0xa
// 0048f710  895c2418             mov dword ptr [esp + 0x18], ebx
// 0048f714  ff159c47b200         call dword ptr [0xb2479c]
// 0048f71a  85c0                 test eax, eax
// 0048f71c  7404                 je 0x48f722
// 0048f71e  b301                 mov bl, 1
// 0048f720  eb02                 jmp 0x48f724
// 0048f722  32db                 xor bl, bl
// 0048f724  f644241410           test byte ptr [esp + 0x14], 0x10
// 0048f729  740f                 je 0x48f73a
// 0048f72b  83642414ef           and dword ptr [esp + 0x14], 0xffffffef
// 0048f730  8d4c2444             lea ecx, [esp + 0x44]
// 0048f734  ff15d047b200         call dword ptr [0xb247d0]
// 0048f73a  f644241408           test byte ptr [esp + 0x14], 8
// 0048f73f  c744246400000000     mov dword ptr [esp + 0x64], 0
// 0048f747  740f                 je 0x48f758
// 0048f749  83642414f7           and dword ptr [esp + 0x14], 0xfffffff7
// 0048f74e  8d4c2448             lea ecx, [esp + 0x48]
// 0048f752  ff15d047b200         call dword ptr [0xb247d0]
// 0048f758  84db                 test bl, bl
// 0048f75a  7474                 je 0x48f7d0
// 0048f75c  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0048f760  e89b985200           call 0x9b9000
// 0048f765  8bf8                 mov edi, eax
// 0048f767  85ff                 test edi, edi
// 0048f769  7465                 je 0x48f7d0
// 0048f76b  8b06                 mov eax, dword ptr [esi]
// 0048f76d  8b506c               mov edx, dword ptr [eax + 0x6c]
// 0048f770  6a00                 push 0
// 0048f772  8d4c245c             lea ecx, [esp + 0x5c]
// 0048f776  51                   push ecx
// 0048f777  8bce                 mov ecx, esi
// 0048f779  ffd2                 call edx
// 0048f77b  50                   push eax
// 0048f77c  8d442474             lea eax, [esp + 0x74]
// 0048f780  50                   push eax
// 0048f781  8d4c245c             lea ecx, [esp + 0x5c]
// 0048f785  51                   push ecx
// 0048f786  c64424700b           mov byte ptr [esp + 0x70], 0xb
// 0048f78b  e8605efcff           call 0x4555f0
// 0048f790  83c408               add esp, 8
// 0048f793  8bd4                 mov edx, esp
// 0048f795  89642450             mov dword ptr [esp + 0x50], esp
// 0048f799  6844d8b500           push 0xb5d844
// 0048f79e  50                   push eax
// 0048f79f  52                   push edx
// 0048f7a0  c64424740c           mov byte ptr [esp + 0x74], 0xc
// 0048f7a5  e8f661f8ff           call 0x4159a0
// 0048f7aa  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0048f7ae  83c40c               add esp, 0xc
// 0048f7b1  57                   push edi
// 0048f7b2  e849fcffff           call 0x48f400
// 0048f7b7  8d4c2454             lea ecx, [esp + 0x54]
// 0048f7bb  ff15d047b200         call dword ptr [0xb247d0]
// 0048f7c1  8d4c2458             lea ecx, [esp + 0x58]
// 0048f7c5  c644246400           mov byte ptr [esp + 0x64], 0
// 0048f7ca  ff15d047b200         call dword ptr [0xb247d0]
// 0048f7d0  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0048f7d4  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 0048f7d8  47                   inc edi
// 0048f7d9  897c2418             mov dword ptr [esp + 0x18], edi
// 0048f7dd  e88eb45200           call 0x9bac70
// 0048f7e2  3bf8                 cmp edi, eax
// 0048f7e4  0f8c59fcffff         jl 0x48f443
// 0048f7ea  8d4c2470             lea ecx, [esp + 0x70]
// 0048f7ee  ff15d047b200         call dword ptr [0xb247d0]
// 0048f7f4  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0048f7f8  5f                   pop edi
// 0048f7f9  5e                   pop esi
// 0048f7fa  5d                   pop ebp
// 0048f7fb  64890d00000000       mov dword ptr fs:[0], ecx
// 0048f802  5b                   pop ebx
// 0048f803  83c458               add esp, 0x58
// 0048f806  c20800               ret 8
// 0048f809  e8b22b4f00           call 0x9823c0
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