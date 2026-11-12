// from server: 100% by EspClaude
// from server: 57% by colin
// roc 2007-08 006d9360  unit: CXTPDockingPaneAutoHidePanel  size: 353 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d9360
//
// 006d9360  81ec10010000         sub esp, 0x110
// 006d9366  a188518b00           mov eax, dword ptr [0x8b5188]
// 006d936b  33c4                 xor eax, esp
// 006d936d  8984240c010000       mov dword ptr [esp + 0x10c], eax
// 006d9374  53                   push ebx
// 006d9375  55                   push ebp
// 006d9376  56                   push esi
// 006d9377  57                   push edi
// 006d9378  8bbc2424010000       mov edi, dword ptr [esp + 0x124]
// 006d937f  57                   push edi
// 006d9380  8be9                 mov ebp, ecx
// 006d9382  e809e8ffff           call 0x6d7b90
// 006d9387  8b4558               mov eax, dword ptr [ebp + 0x58]
// 006d938a  8d4c2414             lea ecx, [esp + 0x14]
// 006d938e  51                   push ecx
// 006d938f  68588d7d00           push 0x7d8d58
// 006d9394  57                   push edi
// 006d9395  89442420             mov dword ptr [esp + 0x20], eax
// 006d9399  e8a2c3faff           call 0x685740
// 006d939e  33f6                 xor esi, esi
// 006d93a0  83c40c               add esp, 0xc
// 006d93a3  397724               cmp dword ptr [edi + 0x24], esi
// 006d93a6  89742410             mov dword ptr [esp + 0x10], esi
// 006d93aa  755e                 jne 0x6d940a
// 006d93ac  8b5544               mov edx, dword ptr [ebp + 0x44]
// 006d93af  8d442410             lea eax, [esp + 0x10]
// 006d93b3  50                   push eax
// 006d93b4  68f48b7d00           push 0x7d8bf4
// 006d93b9  57                   push edi
// 006d93ba  8954241c             mov dword ptr [esp + 0x1c], edx
// 006d93be  e87dc3faff           call 0x685740
// 006d93c3  8d5e01               lea ebx, [esi + 1]
// 006d93c6  8b753c               mov esi, dword ptr [ebp + 0x3c]
// 006d93c9  83c40c               add esp, 0xc
// 006d93cc  85f6                 test esi, esi
// 006d93ce  0f84c9000000         je 0x6d949d
// 006d93d4  53                   push ebx
// 006d93d5  8bc6                 mov eax, esi
// 006d93d7  8b36                 mov esi, dword ptr [esi]
// 006d93d9  8b6808               mov ebp, dword ptr [eax + 8]
// 006d93dc  8d4c2420             lea ecx, [esp + 0x20]
// 006d93e0  68ec8b7d00           push 0x7d8bec
// 006d93e5  51                   push ecx
// 006d93e6  ff1520ee7700         call dword ptr [0x77ee20]
// 006d93ec  83c534               add ebp, 0x34
// 006d93ef  55                   push ebp
// 006d93f0  8d54242c             lea edx, [esp + 0x2c]
// 006d93f4  52                   push edx
// 006d93f5  57                   push edi
// 006d93f6  83c301               add ebx, 1
// 006d93f9  e842c3faff           call 0x685740
// 006d93fe  83c418               add esp, 0x18
// 006d9401  85f6                 test esi, esi
// 006d9403  75cf                 jne 0x6d93d4
// 006d9405  e993000000           jmp 0x6d949d
// 006d940a  8b442414             mov eax, dword ptr [esp + 0x14]
// 006d940e  56                   push esi
// 006d940f  8d4c2414             lea ecx, [esp + 0x14]
// 006d9413  51                   push ecx
// 006d9414  68f48b7d00           push 0x7d8bf4
// 006d9419  57                   push edi
// 006d941a  894558               mov dword ptr [ebp + 0x58], eax
// 006d941d  e8fec2faff           call 0x685720
// 006d9422  8b5f20               mov ebx, dword ptr [edi + 0x20]
// 006d9425  89742428             mov dword ptr [esp + 0x28], esi
// 006d9429  be01000000           mov esi, 1
// 006d942e  83c410               add esp, 0x10
// 006d9431  39742410             cmp dword ptr [esp + 0x10], esi
// 006d9435  7c59                 jl 0x6d9490
// 006d9437  eb07                 jmp 0x6d9440
// 006d9439  8da42400000000       lea esp, [esp]
// 006d9440  56                   push esi
// 006d9441  8d542420             lea edx, [esp + 0x20]
// 006d9445  68ec8b7d00           push 0x7d8bec
// 006d944a  52                   push edx
// 006d944b  ff1520ee7700         call dword ptr [0x77ee20]
// 006d9451  6a00                 push 0
// 006d9453  8d442428             lea eax, [esp + 0x28]
// 006d9457  50                   push eax
// 006d9458  8d4c2430             lea ecx, [esp + 0x30]
// 006d945c  51                   push ecx
// 006d945d  57                   push edi
// 006d945e  e8bdc2faff           call 0x685720
// 006d9463  8b542434             mov edx, dword ptr [esp + 0x34]
// 006d9467  83c41c               add esp, 0x1c
// 006d946a  52                   push edx
// 006d946b  8bcb                 mov ecx, ebx
// 006d946d  e82ebff5ff           call 0x6353a0
// 006d9472  8b00                 mov eax, dword ptr [eax]
// 006d9474  85c0                 test eax, eax
// 006d9476  7445                 je 0x6d94bd
// 006d9478  8b55ac               mov edx, dword ptr [ebp - 0x54]
// 006d947b  8d4dac               lea ecx, [ebp - 0x54]
// 006d947e  50                   push eax
// 006d947f  8b8240010000         mov eax, dword ptr [edx + 0x140]
// 006d9485  ffd0                 call eax
// 006d9487  83c601               add esi, 1
// 006d948a  3b742410             cmp esi, dword ptr [esp + 0x10]
// 006d948e  7eb0                 jle 0x6d9440
// 006d9490  8b5558               mov edx, dword ptr [ebp + 0x58]
// 006d9493  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006d9496  8d4dac               lea ecx, [ebp - 0x54]
// 006d9499  894c9060             mov dword ptr [eax + edx*4 + 0x60], ecx
// 006d949d  b801000000           mov eax, 1
// 006d94a2  8b8c241c010000       mov ecx, dword ptr [esp + 0x11c]
// 006d94a9  5f                   pop edi
// 006d94aa  5e                   pop esi
// 006d94ab  5d                   pop ebp
// 006d94ac  5b                   pop ebx
// 006d94ad  33cc                 xor ecx, esp
// 006d94af  e86a75f5ff           call 0x630a1e
// 006d94b4  81c410010000         add esp, 0x110
// 006d94ba  c20400               ret 4
// 006d94bd  33c0                 xor eax, eax
// 006d94bf  ebe1                 jmp 0x6d94a2

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* lpOut, const char* lpFmt, ...);

class CXTPDockingPaneBase;

class CXTPPropExchange {
public:
    char pad0[0x20];
    unsigned long m_dwData;
    int m_bLoading;
    int IsLoading() const { return m_bLoading; }
};

int __cdecl PX_Int(CXTPPropExchange* pPX, const char* pszPropName, int& nValue);
int __cdecl PX_Int(CXTPPropExchange* pPX, const char* pszPropName, int& nValue, int nDefault);

extern const char _xtPanes[];
extern const char _xtPaneSection[];

class CXTPPaneIndexToPaneMap {
public:
    CXTPDockingPaneBase*& operator[](int key);
};

struct __POSITION {};
typedef __POSITION* POSITION;

class CPaneList {
public:
    struct CNode {
        CNode* pNext;
        CNode* pPrev;
        CXTPDockingPaneBase* data;
    };
    virtual ~CPaneList();
    CNode* m_pNodeHead;
    CNode* m_pNodeTail;
    int m_nCount;
    int GetCount() const { return m_nCount; }
    POSITION GetHeadPosition() const { return (POSITION)m_pNodeHead; }
    CXTPDockingPaneBase*& GetNext(POSITION& rPosition)
    {
        CNode* pNode = (CNode*)rPosition;
        rPosition = (POSITION)pNode->pNext;
        return pNode->data;
    }
};

class CXTPDockingPaneLayout;
class CXTPDockingPaneAutoHidePanel;

class CXTPDockingPaneBase {
public:
    virtual ~CXTPDockingPaneBase();
    virtual int DoPropExchange(CXTPPropExchange* pPX);
    char pad4[0xc - 4];
    CXTPDockingPaneLayout* m_pLayout;
    char pad10[0x34 - 0x10];
    int m_nIndex;
};

class CXTPDockingPaneLayout {
public:
    char pad0[0x60];
    CXTPDockingPaneAutoHidePanel* m_wndPanels[4];
};

class CWndPart {
public:
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void _InsertPane(CXTPDockingPaneBase* pPane);
    char data[0x50];
};

class CXTPDockingPaneAutoHidePanel : public CWndPart, public CXTPDockingPaneBase {
public:
    int DoPropExchange(CXTPPropExchange* pPX);
    CPaneList m_lstPanes;
    char pad48[0x58 - 0x48];
    int m_direction;
};

int CXTPDockingPaneAutoHidePanel::DoPropExchange(CXTPPropExchange* pPX)
{
    CXTPDockingPaneBase::DoPropExchange(pPX);

    int direction = m_direction;
    PX_Int(pPX, "Direction", direction);

    int nCount = 0;

    if (!pPX->IsLoading())
    {
        nCount = (int)m_lstPanes.GetCount();
        PX_Int(pPX, _xtPanes, nCount);

        int nIndex = 1;
        char szPane[256];
        POSITION pos = m_lstPanes.GetHeadPosition();
        while (pos)
        {
            CXTPDockingPaneBase* pPane = m_lstPanes.GetNext(pos);
            wsprintfA(szPane, _xtPaneSection, nIndex++);
            PX_Int(pPX, szPane, pPane->m_nIndex);
        }
    }
    else
    {
        m_direction = direction;

        PX_Int(pPX, _xtPanes, nCount, 0);

        int nIndex = 0;
        char szPane[256];
        CXTPPaneIndexToPaneMap* pMap = (CXTPPaneIndexToPaneMap*)pPX->m_dwData;

        for (int i = 1; i <= nCount; i++)
        {
            wsprintfA(szPane, _xtPaneSection, i);
            PX_Int(pPX, szPane, nIndex, 0);

            CXTPDockingPaneBase* pPane = 0;
            pPane = (CXTPDockingPaneBase*)((*pMap)[nIndex]);
            if (!pPane) return 0;

            _InsertPane(pPane);
        }

        m_pLayout->m_wndPanels[m_direction] = this;
    }
    return 1;
}
