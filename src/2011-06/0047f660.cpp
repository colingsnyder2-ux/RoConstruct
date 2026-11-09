// from server: 100% by Yeetserama
// roc 2011-06 0047f660  unit: CRobloxReportPaneView  size: 1038 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0047f660
//
// 0047f660  6aff                 push -1
// 0047f662  687a4f9d00           push 0x9d4f7a
// 0047f667  64a100000000         mov eax, dword ptr fs:[0]
// 0047f66d  50                   push eax
// 0047f66e  64892500000000       mov dword ptr fs:[0], esp
// 0047f675  83ec4c               sub esp, 0x4c
// 0047f678  53                   push ebx
// 0047f679  55                   push ebp
// 0047f67a  56                   push esi
// 0047f67b  33c0                 xor eax, eax
// 0047f67d  57                   push edi
// 0047f67e  894c2450             mov dword ptr [esp + 0x50], ecx
// 0047f682  89442414             mov dword ptr [esp + 0x14], eax
// 0047f686  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 0047f68a  89442464             mov dword ptr [esp + 0x64], eax
// 0047f68e  89442418             mov dword ptr [esp + 0x18], eax
// 0047f692  e8493a3c00           call 0x8430e0
// 0047f697  85c0                 test eax, eax
// 0047f699  0f8eab030000         jle 0x47fa4a
// 0047f69f  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0047f6a3  8b442418             mov eax, dword ptr [esp + 0x18]
// 0047f6a7  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 0047f6ab  50                   push eax
// 0047f6ac  e88f313c00           call 0x842840
// 0047f6b1  8bd8                 mov ebx, eax
// 0047f6b3  8b4328               mov eax, dword ptr [ebx + 0x28]
// 0047f6b6  33ed                 xor ebp, ebp
// 0047f6b8  895c244c             mov dword ptr [esp + 0x4c], ebx
// 0047f6bc  85c0                 test eax, eax
// 0047f6be  0f8e94000000         jle 0x47f758
// 0047f6c4  85ed                 test ebp, ebp
// 0047f6c6  7c18                 jl 0x47f6e0
// 0047f6c8  3be8                 cmp ebp, eax
// 0047f6ca  7d14                 jge 0x47f6e0
// 0047f6cc  3b6b28               cmp ebp, dword ptr [ebx + 0x28]
// 0047f6cf  0f8d94030000         jge 0x47fa69
// 0047f6d5  8b4b24               mov ecx, dword ptr [ebx + 0x24]
// 0047f6d8  8b3ca9               mov edi, dword ptr [ecx + ebp*4]
// 0047f6db  8d04a9               lea eax, [ecx + ebp*4]
// 0047f6de  eb02                 jmp 0x47f6e2
// 0047f6e0  33ff                 xor edi, edi
// 0047f6e2  6a00                 push 0
// 0047f6e4  683875c100           push 0xc17538
// 0047f6e9  68fcbfc000           push 0xc0bffc
// 0047f6ee  6a00                 push 0
// 0047f6f0  57                   push edi
// 0047f6f1  e8f4bb3800           call 0x80b2ea
// 0047f6f6  83c414               add esp, 0x14
// 0047f6f9  85c0                 test eax, eax
// 0047f6fb  7419                 je 0x47f716
// 0047f6fd  6a00                 push 0
// 0047f6ff  683875c100           push 0xc17538
// 0047f704  68fcbfc000           push 0xc0bffc
// 0047f709  6a00                 push 0
// 0047f70b  57                   push edi
// 0047f70c  e8d9bb3800           call 0x80b2ea
// 0047f711  83c414               add esp, 0x14
// 0047f714  8bf0                 mov esi, eax
// 0047f716  6a00                 push 0
// 0047f718  68fc74c100           push 0xc174fc
// 0047f71d  68fcbfc000           push 0xc0bffc
// 0047f722  6a00                 push 0
// 0047f724  57                   push edi
// 0047f725  e8c0bb3800           call 0x80b2ea
// 0047f72a  83c414               add esp, 0x14
// 0047f72d  85c0                 test eax, eax
// 0047f72f  741b                 je 0x47f74c
// 0047f731  6a00                 push 0
// 0047f733  68fc74c100           push 0xc174fc
// 0047f738  68fcbfc000           push 0xc0bffc
// 0047f73d  6a00                 push 0
// 0047f73f  57                   push edi
// 0047f740  e8a5bb3800           call 0x80b2ea
// 0047f745  83c414               add esp, 0x14
// 0047f748  89442420             mov dword ptr [esp + 0x20], eax
// 0047f74c  8b4328               mov eax, dword ptr [ebx + 0x28]
// 0047f74f  45                   inc ebp
// 0047f750  3be8                 cmp ebp, eax
// 0047f752  0f8c6cffffff         jl 0x47f6c4
// 0047f758  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0047f75c  8b17                 mov edx, dword ptr [edi]
// 0047f75e  8b526c               mov edx, dword ptr [edx + 0x6c]
// 0047f761  6a00                 push 0
// 0047f763  8d442430             lea eax, [esp + 0x30]
// 0047f767  50                   push eax
// 0047f768  8bcf                 mov ecx, edi
// 0047f76a  ffd2                 call edx
// 0047f76c  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0047f770  83cb01               or ebx, 1
// 0047f773  68cabea500           push 0xa5beca
// 0047f778  8bc8                 mov ecx, eax
// 0047f77a  c644246801           mov byte ptr [esp + 0x68], 1
// 0047f77f  895c2418             mov dword ptr [esp + 0x18], ebx
// 0047f783  ff15cc2da400         call dword ptr [0xa42dcc]
// 0047f789  85c0                 test eax, eax
// 0047f78b  7465                 je 0x47f7f2
// 0047f78d  8b06                 mov eax, dword ptr [esi]
// 0047f78f  8b506c               mov edx, dword ptr [eax + 0x6c]
// 0047f792  6a00                 push 0
// 0047f794  8d4c242c             lea ecx, [esp + 0x2c]
// 0047f798  51                   push ecx
// 0047f799  8bce                 mov ecx, esi
// 0047f79b  ffd2                 call edx
// 0047f79d  83cb02               or ebx, 2
// 0047f7a0  68dcf1a600           push 0xa6f1dc
// 0047f7a5  8bc8                 mov ecx, eax
// 0047f7a7  c744246802000000     mov dword ptr [esp + 0x68], 2
// 0047f7af  895c2418             mov dword ptr [esp + 0x18], ebx
// 0047f7b3  ff15cc2da400         call dword ptr [0xa42dcc]
// 0047f7b9  85c0                 test eax, eax
// 0047f7bb  7435                 je 0x47f7f2
// 0047f7bd  8b06                 mov eax, dword ptr [esi]
// 0047f7bf  8b506c               mov edx, dword ptr [eax + 0x6c]
// 0047f7c2  6a00                 push 0
// 0047f7c4  8d4c2428             lea ecx, [esp + 0x28]
// 0047f7c8  51                   push ecx
// 0047f7c9  8bce                 mov ecx, esi
// 0047f7cb  ffd2                 call edx
// 0047f7cd  83cb04               or ebx, 4
// 0047f7d0  683819a700           push 0xa71938
// 0047f7d5  8bc8                 mov ecx, eax
// 0047f7d7  c744246803000000     mov dword ptr [esp + 0x68], 3
// 0047f7df  895c2418             mov dword ptr [esp + 0x18], ebx
// 0047f7e3  ff15cc2da400         call dword ptr [0xa42dcc]
// 0047f7e9  c644241301           mov byte ptr [esp + 0x13], 1
// 0047f7ee  85c0                 test eax, eax
// 0047f7f0  7505                 jne 0x47f7f7
// 0047f7f2  c644241300           mov byte ptr [esp + 0x13], 0
// 0047f7f7  f6c304               test bl, 4
// 0047f7fa  740d                 je 0x47f809
// 0047f7fc  8d4c2424             lea ecx, [esp + 0x24]
// 0047f800  83e3fb               and ebx, 0xfffffffb
// 0047f803  ff15082ea400         call dword ptr [0xa42e08]
// 0047f809  f6c302               test bl, 2
// 0047f80c  740d                 je 0x47f81b
// 0047f80e  8d4c2428             lea ecx, [esp + 0x28]
// 0047f812  83e3fd               and ebx, 0xfffffffd
// 0047f815  ff15082ea400         call dword ptr [0xa42e08]
// 0047f81b  c744246400000000     mov dword ptr [esp + 0x64], 0
// 0047f823  f6c301               test bl, 1
// 0047f826  740d                 je 0x47f835
// 0047f828  8d4c242c             lea ecx, [esp + 0x2c]
// 0047f82c  83e3fe               and ebx, 0xfffffffe
// 0047f82f  ff15082ea400         call dword ptr [0xa42e08]
// 0047f835  807c241300           cmp byte ptr [esp + 0x13], 0
// 0047f83a  0f84e1000000         je 0x47f921
// 0047f840  8b07                 mov eax, dword ptr [edi]
// 0047f842  8b506c               mov edx, dword ptr [eax + 0x6c]
// 0047f845  6a00                 push 0
// 0047f847  8d4c2444             lea ecx, [esp + 0x44]
// 0047f84b  51                   push ecx
// 0047f84c  8bcf                 mov ecx, edi
// 0047f84e  ffd2                 call edx
// 0047f850  8bf8                 mov edi, eax
// 0047f852  8b06                 mov eax, dword ptr [esi]
// 0047f854  8b506c               mov edx, dword ptr [eax + 0x6c]
// 0047f857  6a00                 push 0
// 0047f859  8d4c2440             lea ecx, [esp + 0x40]
// 0047f85d  51                   push ecx
// 0047f85e  8bce                 mov ecx, esi
// 0047f860  c644246c04           mov byte ptr [esp + 0x6c], 4
// 0047f865  ffd2                 call edx
// 0047f867  50                   push eax
// 0047f868  8d442474             lea eax, [esp + 0x74]
// 0047f86c  50                   push eax
// 0047f86d  8d4c2440             lea ecx, [esp + 0x40]
// 0047f871  51                   push ecx
// 0047f872  c644247005           mov byte ptr [esp + 0x70], 5
// 0047f877  e81448fcff           call 0x444090
// 0047f87c  68ec88a600           push 0xa688ec
// 0047f881  50                   push eax
// 0047f882  8d542448             lea edx, [esp + 0x48]
// 0047f886  52                   push edx
// 0047f887  c644247c06           mov byte ptr [esp + 0x7c], 6
// 0047f88c  e85f30f9ff           call 0x4128f0
// 0047f891  57                   push edi
// 0047f892  50                   push eax
// 0047f893  8d442450             lea eax, [esp + 0x50]
// 0047f897  50                   push eax
// 0047f898  c684248800000007     mov byte ptr [esp + 0x88], 7
// 0047f8a0  e8eb47fcff           call 0x444090
// 0047f8a5  687442a600           push 0xa64274
// 0047f8aa  50                   push eax
// 0047f8ab  8d4c2448             lea ecx, [esp + 0x48]
// 0047f8af  51                   push ecx
// 0047f8b0  c684249400000008     mov byte ptr [esp + 0x94], 8
// 0047f8b8  e83330f9ff           call 0x4128f0
// 0047f8bd  83c430               add esp, 0x30
// 0047f8c0  8d4c2430             lea ecx, [esp + 0x30]
// 0047f8c4  ff15082ea400         call dword ptr [0xa42e08]
// 0047f8ca  8d4c2434             lea ecx, [esp + 0x34]
// 0047f8ce  ff15082ea400         call dword ptr [0xa42e08]
// 0047f8d4  8d4c2438             lea ecx, [esp + 0x38]
// 0047f8d8  ff15082ea400         call dword ptr [0xa42e08]
// 0047f8de  8d4c243c             lea ecx, [esp + 0x3c]
// 0047f8e2  ff15082ea400         call dword ptr [0xa42e08]
// 0047f8e8  8d4c2440             lea ecx, [esp + 0x40]
// 0047f8ec  c644246400           mov byte ptr [esp + 0x64], 0
// 0047f8f1  ff15082ea400         call dword ptr [0xa42e08]
// 0047f8f7  8d4c241c             lea ecx, [esp + 0x1c]
// 0047f8fb  ff15c82da400         call dword ptr [0xa42dc8]
// 0047f901  8b15f83ecb00         mov edx, dword ptr [0xcb3ef8]
// 0047f907  50                   push eax
// 0047f908  683456a600           push 0xa65634
// 0047f90d  52                   push edx
// 0047f90e  ff159009a400         call dword ptr [0xa40990]
// 0047f914  83c40c               add esp, 0xc
// 0047f917  8d4c241c             lea ecx, [esp + 0x1c]
// 0047f91b  ff15082ea400         call dword ptr [0xa42e08]
// 0047f921  8b06                 mov eax, dword ptr [esi]
// 0047f923  8b506c               mov edx, dword ptr [eax + 0x6c]
// 0047f926  6a00                 push 0
// 0047f928  8d4c244c             lea ecx, [esp + 0x4c]
// 0047f92c  51                   push ecx
// 0047f92d  8bce                 mov ecx, esi
// 0047f92f  ffd2                 call edx
// 0047f931  83cb08               or ebx, 8
// 0047f934  68dcf1a600           push 0xa6f1dc
// 0047f939  8bc8                 mov ecx, eax
// 0047f93b  c644246809           mov byte ptr [esp + 0x68], 9
// 0047f940  895c2418             mov dword ptr [esp + 0x18], ebx
// 0047f944  ff15cc2da400         call dword ptr [0xa42dcc]
// 0047f94a  85c0                 test eax, eax
// 0047f94c  7434                 je 0x47f982
// 0047f94e  8b06                 mov eax, dword ptr [esi]
// 0047f950  8b506c               mov edx, dword ptr [eax + 0x6c]
// 0047f953  6a00                 push 0
// 0047f955  8d4c2448             lea ecx, [esp + 0x48]
// 0047f959  51                   push ecx
// 0047f95a  8bce                 mov ecx, esi
// 0047f95c  ffd2                 call edx
// 0047f95e  83cb10               or ebx, 0x10
// 0047f961  683819a700           push 0xa71938
// 0047f966  8bc8                 mov ecx, eax
// 0047f968  c74424680a000000     mov dword ptr [esp + 0x68], 0xa
// 0047f970  895c2418             mov dword ptr [esp + 0x18], ebx
// 0047f974  ff15cc2da400         call dword ptr [0xa42dcc]
// 0047f97a  85c0                 test eax, eax
// 0047f97c  7404                 je 0x47f982
// 0047f97e  b301                 mov bl, 1
// 0047f980  eb02                 jmp 0x47f984
// 0047f982  32db                 xor bl, bl
// 0047f984  f644241410           test byte ptr [esp + 0x14], 0x10
// 0047f989  740f                 je 0x47f99a
// 0047f98b  83642414ef           and dword ptr [esp + 0x14], 0xffffffef
// 0047f990  8d4c2444             lea ecx, [esp + 0x44]
// 0047f994  ff15082ea400         call dword ptr [0xa42e08]
// 0047f99a  f644241408           test byte ptr [esp + 0x14], 8
// 0047f99f  c744246400000000     mov dword ptr [esp + 0x64], 0
// 0047f9a7  740f                 je 0x47f9b8
// 0047f9a9  83642414f7           and dword ptr [esp + 0x14], 0xfffffff7
// 0047f9ae  8d4c2448             lea ecx, [esp + 0x48]
// 0047f9b2  ff15082ea400         call dword ptr [0xa42e08]
// 0047f9b8  84db                 test bl, bl
// 0047f9ba  7474                 je 0x47fa30
// 0047f9bc  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0047f9c0  e8db113c00           call 0x840ba0
// 0047f9c5  8bf8                 mov edi, eax
// 0047f9c7  85ff                 test edi, edi
// 0047f9c9  7465                 je 0x47fa30
// 0047f9cb  8b06                 mov eax, dword ptr [esi]
// 0047f9cd  8b506c               mov edx, dword ptr [eax + 0x6c]
// 0047f9d0  6a00                 push 0
// 0047f9d2  8d4c245c             lea ecx, [esp + 0x5c]
// 0047f9d6  51                   push ecx
// 0047f9d7  8bce                 mov ecx, esi
// 0047f9d9  ffd2                 call edx
// 0047f9db  50                   push eax
// 0047f9dc  8d442474             lea eax, [esp + 0x74]
// 0047f9e0  50                   push eax
// 0047f9e1  8d4c245c             lea ecx, [esp + 0x5c]
// 0047f9e5  51                   push ecx
// 0047f9e6  c64424700b           mov byte ptr [esp + 0x70], 0xb
// 0047f9eb  e8a046fcff           call 0x444090
// 0047f9f0  83c408               add esp, 8
// 0047f9f3  8bd4                 mov edx, esp
// 0047f9f5  89642450             mov dword ptr [esp + 0x50], esp
// 0047f9f9  683419a700           push 0xa71934
// 0047f9fe  50                   push eax
// 0047f9ff  52                   push edx
// 0047fa00  c64424740c           mov byte ptr [esp + 0x74], 0xc
// 0047fa05  e8e62ef9ff           call 0x4128f0
// 0047fa0a  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0047fa0e  83c40c               add esp, 0xc
// 0047fa11  57                   push edi
// 0047fa12  e849fcffff           call 0x47f660
// 0047fa17  8d4c2454             lea ecx, [esp + 0x54]
// 0047fa1b  ff15082ea400         call dword ptr [0xa42e08]
// 0047fa21  8d4c2458             lea ecx, [esp + 0x58]
// 0047fa25  c644246400           mov byte ptr [esp + 0x64], 0
// 0047fa2a  ff15082ea400         call dword ptr [0xa42e08]
// 0047fa30  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0047fa34  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 0047fa38  47                   inc edi
// 0047fa39  897c2418             mov dword ptr [esp + 0x18], edi
// 0047fa3d  e89e363c00           call 0x8430e0
// 0047fa42  3bf8                 cmp edi, eax
// 0047fa44  0f8c59fcffff         jl 0x47f6a3
// 0047fa4a  8d4c2470             lea ecx, [esp + 0x70]
// 0047fa4e  ff15082ea400         call dword ptr [0xa42e08]
// 0047fa54  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0047fa58  5f                   pop edi
// 0047fa59  5e                   pop esi
// 0047fa5a  5d                   pop ebp
// 0047fa5b  64890d00000000       mov dword ptr fs:[0], ecx
// 0047fa62  5b                   pop ebx
// 0047fa63  83c458               add esp, 0x58
// 0047fa66  c20800               ret 8
// 0047fa69  e89ca83800           call 0x80a30a
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