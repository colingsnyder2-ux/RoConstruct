// from server: 100% by EspClaude
// from server: 43% by colin
// roc 2007-08 004302c0  unit: CMainFrame  size: 261 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004302c0
//
// 004302c0  6aff                 push -1
// 004302c2  68c6d87300           push 0x73d8c6
// 004302c7  64a100000000         mov eax, dword ptr fs:[0]
// 004302cd  50                   push eax
// 004302ce  81ec74020000         sub esp, 0x274
// 004302d4  56                   push esi
// 004302d5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004302da  33c4                 xor eax, esp
// 004302dc  50                   push eax
// 004302dd  8d84247c020000       lea eax, [esp + 0x27c]
// 004302e4  64a300000000         mov dword ptr fs:[0], eax
// 004302ea  8b81d8000000         mov eax, dword ptr [ecx + 0xd8]
// 004302f0  85c0                 test eax, eax
// 004302f2  0f84b6000000         je 0x4303ae
// 004302f8  6a00                 push 0
// 004302fa  50                   push eax
// 004302fb  8d4c2410             lea ecx, [esp + 0x10]
// 004302ff  e89c4d2400           call 0x6750a0
// 00430304  8d442408             lea eax, [esp + 8]
// 00430308  50                   push eax
// 00430309  8d8c24d0000000       lea ecx, [esp + 0xd0]
// 00430310  c784248802000000000000 mov dword ptr [esp + 0x288], 0
// 0043031b  e8d05a2400           call 0x675df0
// 00430320  8d8c24cc000000       lea ecx, [esp + 0xcc]
// 00430327  51                   push ecx
// 00430328  8d4c240c             lea ecx, [esp + 0xc]
// 0043032c  c684248802000001     mov byte ptr [esp + 0x288], 1
// 00430334  e897302400           call 0x6733d0
// 00430339  8b8c24b8000000       mov ecx, dword ptr [esp + 0xb8]
// 00430340  6a00                 push 0
// 00430342  6881000000           push 0x81
// 00430347  8bf1                 mov esi, ecx
// 00430349  e8626c2400           call 0x676fb0
// 0043034e  6aff                 push -1
// 00430350  68d1230000           push 0x23d1
// 00430355  8bce                 mov ecx, esi
// 00430357  e8d4682400           call 0x676c30
// 0043035c  6aff                 push -1
// 0043035e  68d6230000           push 0x23d6
// 00430363  6881000000           push 0x81
// 00430368  8bce                 mov ecx, esi
// 0043036a  e881652400           call 0x6768f0
// 0043036f  6aff                 push -1
// 00430371  68ca230000           push 0x23ca
// 00430376  8bce                 mov ecx, esi
// 00430378  e8f3662400           call 0x676a70
// 0043037d  8d4c2408             lea ecx, [esp + 8]
// 00430381  e84a4f2400           call 0x6752d0
// 00430386  8d8c24cc000000       lea ecx, [esp + 0xcc]
// 0043038d  c684248402000000     mov byte ptr [esp + 0x284], 0
// 00430395  e856542400           call 0x6757f0
// 0043039a  8d4c2408             lea ecx, [esp + 8]
// 0043039e  c7842484020000ffffffff mov dword ptr [esp + 0x284], 0xffffffff
// 004303a9  e8622f2400           call 0x673310
// 004303ae  8b8c247c020000       mov ecx, dword ptr [esp + 0x27c]
// 004303b5  64890d00000000       mov dword ptr fs:[0], ecx
// 004303bc  59                   pop ecx
// 004303bd  5e                   pop esi
// 004303be  81c480020000         add esp, 0x280
// 004303c4  c3                   ret 

typedef unsigned int UINT;
typedef int BOOL;

class CXTPCommandBars;
class CXTPCustomizeSheet;

class CXTPCustomizeCommandsPage {
public:
    BOOL AddCategories(UINT nIDResource, BOOL bListSubItems = 0);
    void InsertAllCommandsCategory(UINT nIDCategory, int nIndex = -1);
    void InsertBuiltInMenus(UINT nIDResource, UINT nIDCategory, int nIndex = -1);
    void InsertNewMenuCategory(UINT nIDCategory, int nIndex = -1);
};

// sizeof 0xc4 and m_pCommandsPage at +0xb0: read off the frame ([esp+8] .. [esp+0xcc], [esp+0xb8]).
class CXTPCustomizeSheet {
public:
    CXTPCustomizeSheet(CXTPCommandBars* pCommandBars, UINT iSelectPage = 0);
    virtual ~CXTPCustomizeSheet();
    virtual int DoModal();
    void AddPage(void* pPage);
    CXTPCustomizeCommandsPage* GetCommandsPage() const { return m_pCommandsPage; }
    int pad_[(0xb0 - 4) / 4];
    CXTPCustomizeCommandsPage* m_pCommandsPage;
    int pad2_[(0xc4 - 0xb4) / 4];
};

// sizeof 0x1b0: [esp+0xcc] .. [esp+0x27c].
class CXTPCustomizeKeyboardPage {
public:
    CXTPCustomizeKeyboardPage(CXTPCustomizeSheet* pSheet);
    virtual ~CXTPCustomizeKeyboardPage();
    int pad_[(0x1b0 - 4) / 4];
};

class CMainFrame {
public:
    CXTPCommandBars* GetCommandBars() const { return m_pCommandBars; }
    void OnCustomize();
    int pad_[0xd8 / 4];
    CXTPCommandBars* m_pCommandBars;
};

void CMainFrame::OnCustomize()
{
    CXTPCommandBars* pCommandBars = GetCommandBars();
    if (pCommandBars != 0)
    {
        CXTPCustomizeSheet dlg(pCommandBars);

        CXTPCustomizeKeyboardPage pageKeyboard(&dlg);
        dlg.AddPage(&pageKeyboard);

        CXTPCustomizeCommandsPage* pCommands = dlg.GetCommandsPage();
        pCommands->AddCategories(0x81);
        pCommands->InsertAllCommandsCategory(0x23d1);
        pCommands->InsertBuiltInMenus(0x81, 0x23d6);
        pCommands->InsertNewMenuCategory(0x23ca);

        dlg.DoModal();
    }
}
