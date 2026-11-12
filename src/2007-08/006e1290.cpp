// from server: 70% by EspClaude
// from server: 46% by colin
// roc 2007-08 006e1290  unit: CXTPDockingPaneTabbedContainer  size: 360 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006e1290
//
// 006e1290  6aff                 push -1
// 006e1292  68827a7600           push 0x767a82
// 006e1297  64a100000000         mov eax, dword ptr fs:[0]
// 006e129d  50                   push eax
// 006e129e  83ec0c               sub esp, 0xc
// 006e12a1  53                   push ebx
// 006e12a2  55                   push ebp
// 006e12a3  56                   push esi
// 006e12a4  57                   push edi
// 006e12a5  a188518b00           mov eax, dword ptr [0x8b5188]
// 006e12aa  33c4                 xor eax, esp
// 006e12ac  50                   push eax
// 006e12ad  8d442420             lea eax, [esp + 0x20]
// 006e12b1  64a300000000         mov dword ptr fs:[0], eax
// 006e12b7  8bd9                 mov ebx, ecx
// 006e12b9  837b2000             cmp dword ptr [ebx + 0x20], 0
// 006e12bd  0f8421010000         je 0x6e13e4
// 006e12c3  83839801000001       add dword ptr [ebx + 0x198], 1
// 006e12ca  8daba8000000         lea ebp, [ebx + 0xa8]
// 006e12d0  8bcd                 mov ecx, ebp
// 006e12d2  e869d30100           call 0x6fe640
// 006e12d7  8d4b54               lea ecx, [ebx + 0x54]
// 006e12da  e881d2f7ff           call 0x65e560
// 006e12df  85c0                 test eax, eax
// 006e12e1  89442414             mov dword ptr [esp + 0x14], eax
// 006e12e5  0f84e0000000         je 0x6e13cb
// 006e12eb  8d442414             lea eax, [esp + 0x14]
// 006e12ef  50                   push eax
// 006e12f0  8d4b54               lea ecx, [ebx + 0x54]
// 006e12f3  e868e70300           call 0x71fa60
// 006e12f8  85c0                 test eax, eax
// 006e12fa  7405                 je 0x6e1301
// 006e12fc  8d70e0               lea esi, [eax - 0x20]
// 006e12ff  eb02                 jmp 0x6e1303
// 006e1301  33f6                 xor esi, esi
// 006e1303  8b8304010000         mov eax, dword ptr [ebx + 0x104]
// 006e1309  6a00                 push 0
// 006e130b  50                   push eax
// 006e130c  8bcd                 mov ecx, ebp
// 006e130e  e89dd30100           call 0x6fe6b0
// 006e1313  39b3a0010000         cmp dword ptr [ebx + 0x1a0], esi
// 006e1319  8bf8                 mov edi, eax
// 006e131b  750b                 jne 0x6e1328
// 006e131d  8b5500               mov edx, dword ptr [ebp]
// 006e1320  8b4220               mov eax, dword ptr [edx + 0x20]
// 006e1323  57                   push edi
// 006e1324  8bcd                 mov ecx, ebp
// 006e1326  ffd0                 call eax
// 006e1328  8b16                 mov edx, dword ptr [esi]
// 006e132a  8b5260               mov edx, dword ptr [edx + 0x60]
// 006e132d  8d442418             lea eax, [esp + 0x18]
// 006e1331  50                   push eax
// 006e1332  8bce                 mov ecx, esi
// 006e1334  ffd2                 call edx
// 006e1336  8bc8                 mov ecx, eax
// 006e1338  c744242800000000     mov dword ptr [esp + 0x28], 0
// 006e1340  ff1598dd7700         call dword ptr [0x77dd98]
// 006e1346  50                   push eax
// 006e1347  8bcf                 mov ecx, edi
// 006e1349  e842c20100           call 0x6fd590
// 006e134e  8d4c2418             lea ecx, [esp + 0x18]
// 006e1352  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 006e135a  ff15bcdd7700         call dword ptr [0x77ddbc]
// 006e1360  8b06                 mov eax, dword ptr [esi]
// 006e1362  8b5068               mov edx, dword ptr [eax + 0x68]
// 006e1365  8bce                 mov ecx, esi
// 006e1367  ffd2                 call edx
// 006e1369  50                   push eax
// 006e136a  8bcf                 mov ecx, edi
// 006e136c  e84fc20100           call 0x6fd5c0
// 006e1371  8b06                 mov eax, dword ptr [esi]
// 006e1373  8b505c               mov edx, dword ptr [eax + 0x5c]
// 006e1376  8d4c241c             lea ecx, [esp + 0x1c]
// 006e137a  51                   push ecx
// 006e137b  8bce                 mov ecx, esi
// 006e137d  ffd2                 call edx
// 006e137f  8bc8                 mov ecx, eax
// 006e1381  c744242801000000     mov dword ptr [esp + 0x28], 1
// 006e1389  ff1598dd7700         call dword ptr [0x77dd98]
// 006e138f  50                   push eax
// 006e1390  8d4f58               lea ecx, [edi + 0x58]
// 006e1393  ff156cdd7700         call dword ptr [0x77dd6c]
// 006e1399  8d4c241c             lea ecx, [esp + 0x1c]
// 006e139d  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 006e13a5  ff15bcdd7700         call dword ptr [0x77ddbc]
// 006e13ab  8bce                 mov ecx, esi
// 006e13ad  e8feddfaff           call 0x68f1b0
// 006e13b2  83e001               and eax, 1
// 006e13b5  50                   push eax
// 006e13b6  8bcf                 mov ecx, edi
// 006e13b8  e8e3bd0100           call 0x6fd1a0
// 006e13bd  897740               mov dword ptr [edi + 0x40], esi
// 006e13c0  837c241400           cmp dword ptr [esp + 0x14], 0
// 006e13c5  0f8520ffffff         jne 0x6e12eb
// 006e13cb  83c8ff               or eax, 0xffffffff
// 006e13ce  0bc8                 or ecx, eax
// 006e13d0  51                   push ecx
// 006e13d1  8b8b80000000         mov ecx, dword ptr [ebx + 0x80]
// 006e13d7  50                   push eax
// 006e13d8  e8a3f1ffff           call 0x6e0580
// 006e13dd  838398010000ff       add dword ptr [ebx + 0x198], -1
// 006e13e4  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 006e13e8  64890d00000000       mov dword ptr fs:[0], ecx
// 006e13ef  59                   pop ecx
// 006e13f0  5f                   pop edi
// 006e13f1  5e                   pop esi
// 006e13f2  5d                   pop ebp
// 006e13f3  5b                   pop ebx
// 006e13f4  83c418               add esp, 0x18

typedef void* POSITION;
typedef unsigned long COLORREF;
typedef int BOOL;

class CString {
public:
    __declspec(dllimport) ~CString() throw();
    __declspec(dllimport) operator const char*() const throw();
    __declspec(dllimport) CString& operator=(const char* psz);
    char* m_pszData;
};

class CXTPDockingPaneBase;

// Pane: CCmdTarget part (0x20 bytes, vptr at 0) followed by CXTPDockingPaneBase at +0x20
// (target: lea esi,[eax-0x20] with null check). Virtual slots 0x5c/0x60 return CString through
// a hidden pointer, slot 0x68 returns a value; 0x68f1b0 is a plain thiscall member.
class CXTPDockingPane {
public:
    // slots 0x00-0x58: not referenced here (padding to the proven slot offsets)
    virtual void _vslot_00();
    virtual void _vslot_04();
    virtual void _vslot_08();
    virtual void _vslot_0c();
    virtual void _vslot_10();
    virtual void _vslot_14();
    virtual void _vslot_18();
    virtual void _vslot_1c();
    virtual void _vslot_20();
    virtual void _vslot_24();
    virtual void _vslot_28();
    virtual void _vslot_2c();
    virtual void _vslot_30();
    virtual void _vslot_34();
    virtual void _vslot_38();
    virtual void _vslot_3c();
    virtual void _vslot_40();
    virtual void _vslot_44();
    virtual void _vslot_48();
    virtual void _vslot_4c();
    virtual void _vslot_50();
    virtual void _vslot_54();
    virtual void _vslot_58();
    virtual CString GetTitle() const;            // slot 0x5c
    virtual CString GetTabCaption() const;       // slot 0x60
    virtual void _vslot_64();
    virtual COLORREF GetItemColor();             // slot 0x68
    int GetOptions();           // 0x68f1b0
};

class CXTPTabManagerItem {
public:
    void SetCaption(const char* lpszCaption);   // 0x6fd590
    void SetColor(COLORREF clr);                // 0x6fd5c0
    void SetEnabled(BOOL bEnabled);             // 0x6fd1a0
    void SetData(void* p) { m_pData = p; }
    char _p0[0x40];
    void* m_pData;            // +0x40
    char _p1[0x58 - 0x44];
    CString m_strToolTip;     // +0x58
};

class CXTPTabManager {
public:
    void DeleteAllItems();                                   // 0x6fe640
    CXTPTabManagerItem* AddItem(int nItem, void* pItem);     // 0x6fe6b0
};

class CXTPDockingPaneList {
public:
    POSITION GetHeadPosition() const;           // 0x65e560
    CXTPDockingPaneBase* GetNext(POSITION& pos);// 0x71fa60
};

class CXTPDockingPaneLayoutTarget {
public:
    void Update(int a, int b);                  // 0x6e0580
};

class CXTPDockingPaneTabbedContainer {
public:
    char pad0[0x20];
    void* m_hWnd;                               // +0x20
    char pad1[0x54 - 0x24];
    CXTPDockingPaneList m_lstPanes;             // +0x54
    char pad2[0x80 - 0x55];
    CXTPDockingPaneLayoutTarget* m_pLayout;     // +0x80
    char pad3[0xa8 - 0x84];
    CXTPTabManager m_tabManager;                // +0xa8
    char pad4[0x104 - 0xa9];
    int m_nItemCount;                           // +0x104
    char pad5[0x198 - 0x108];
    int m_nLockReposition;                      // +0x198
    char pad6[0x1a0 - 0x19c];
    CXTPDockingPane* m_pSelectedPane;           // +0x1a0
    void UpdateTabs();
};

static inline CXTPDockingPane* PaneFromBase(CXTPDockingPaneBase* p)
{
    return p ? (CXTPDockingPane*)((char*)p - 0x20) : 0;
}

typedef CString (__thiscall *StrFn)(CXTPDockingPane*);
typedef COLORREF (__thiscall *ClrFn)(CXTPDockingPane*);
typedef void (__thiscall *SelFn)(CXTPTabManager*, CXTPTabManagerItem*);

void CXTPDockingPaneTabbedContainer::UpdateTabs()
{
    if (m_hWnd == 0)
        return;

    m_nLockReposition++;
    m_tabManager.DeleteAllItems();

    POSITION pos = m_lstPanes.GetHeadPosition();
    while (pos) {
        CXTPDockingPane* pPane = PaneFromBase(m_lstPanes.GetNext(pos));
        CXTPTabManagerItem* pItem = m_tabManager.AddItem(m_nItemCount, 0);
        if (m_pSelectedPane == pPane)
            (*(SelFn*)(*(char**)&m_tabManager + 0x20))(&m_tabManager, pItem);

        pItem->SetCaption(pPane->GetTabCaption());
        pItem->SetColor(pPane->GetItemColor());
        pItem->m_strToolTip = pPane->GetTitle();
        pItem->SetEnabled(pPane->GetOptions() & 1);
        pItem->SetData(pPane);
    }

    m_pLayout->Update(-1, -1);
    m_nLockReposition--;
}
