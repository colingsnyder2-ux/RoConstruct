// from server: 100% by EspClaude
// roc 2009-06 00428c50  unit: MyXTPCommandBars  size: 246 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00428c50
//
// 00428c50  64a100000000         mov eax, dword ptr fs:[0]
// 00428c56  6aff                 push -1
// 00428c58  6866ef8400           push 0x84ef66
// 00428c5d  50                   push eax
// 00428c5e  64892500000000       mov dword ptr fs:[0], esp
// 00428c65  8b81ec000000         mov eax, dword ptr [ecx + 0xec]
// 00428c6b  81ec7c020000         sub esp, 0x27c
// 00428c71  85c0                 test eax, eax
// 00428c73  0f84b8000000         je 0x428d31
// 00428c79  56                   push esi
// 00428c7a  6a00                 push 0
// 00428c7c  50                   push eax
// 00428c7d  8d4c240c             lea ecx, [esp + 0xc]
// 00428c81  e83abc3300           call 0x7648c0
// 00428c86  8d442404             lea eax, [esp + 4]
// 00428c8a  50                   push eax
// 00428c8b  8d8c24cc000000       lea ecx, [esp + 0xcc]
// 00428c92  c784248c02000000000000 mov dword ptr [esp + 0x28c], 0
// 00428c9d  e87ec93300           call 0x765620
// 00428ca2  8d8c24c8000000       lea ecx, [esp + 0xc8]
// 00428ca9  51                   push ecx
// 00428caa  8d4c2408             lea ecx, [esp + 8]
// 00428cae  c684248c02000001     mov byte ptr [esp + 0x28c], 1
// 00428cb6  e8259f3300           call 0x762be0
// 00428cbb  8b8c24b4000000       mov ecx, dword ptr [esp + 0xb4]
// 00428cc2  6a00                 push 0
// 00428cc4  6881000000           push 0x81
// 00428cc9  8bf1                 mov esi, ecx
// 00428ccb  e800db3300           call 0x7667d0
// 00428cd0  6aff                 push -1
// 00428cd2  68d1230000           push 0x23d1
// 00428cd7  8bce                 mov ecx, esi
// 00428cd9  e882d73300           call 0x766460
// 00428cde  6aff                 push -1
// 00428ce0  68d6230000           push 0x23d6
// 00428ce5  6881000000           push 0x81
// 00428cea  8bce                 mov ecx, esi
// 00428cec  e83fd43300           call 0x766130
// 00428cf1  6aff                 push -1
// 00428cf3  68ca230000           push 0x23ca
// 00428cf8  8bce                 mov ecx, esi
// 00428cfa  e8a1d53300           call 0x7662a0
// 00428cff  8d4c2404             lea ecx, [esp + 4]
// 00428d03  e8e8bd3300           call 0x764af0
// 00428d08  8d8c24c8000000       lea ecx, [esp + 0xc8]
// 00428d0f  c684248802000000     mov byte ptr [esp + 0x288], 0
// 00428d17  e8f4c23300           call 0x765010
// 00428d1c  8d4c2404             lea ecx, [esp + 4]
// 00428d20  c7842488020000ffffffff mov dword ptr [esp + 0x288], 0xffffffff
// 00428d2b  e8b09d3300           call 0x762ae0
// 00428d30  5e                   pop esi
// 00428d31  8b8c247c020000       mov ecx, dword ptr [esp + 0x27c]
// 00428d38  64890d00000000       mov dword ptr fs:[0], ecx
// 00428d3f  81c488020000         add esp, 0x288
// 00428d45  c3                   ret 
// copied from an identical function in another client (function ?Customize@CMainFrame@ns_ROCX0000f7@@QAEXXZ)

namespace ns_ROCX0000f7 {
struct CommandBars;

struct CommandsPage
{
    void Initialize(int resource, int category);
    void AddCategories(int resource, int position);
    void AddMenuCategory(int menu, int resource, int position);
    void AddAllCommandsCategory(int resource, int position);
};

struct OptionsPage;

struct CustomizeSheet
{
    unsigned char reserved0[176];
    CommandsPage* commandsPage;
    unsigned char reserved1[16];

    CustomizeSheet(CommandBars* bars, int flags);
    ~CustomizeSheet();
    void AddPage(OptionsPage* page);
    int DoModal();
};

struct OptionsPage
{
    int reserved[110];

    OptionsPage(CustomizeSheet* sheet);
    ~OptionsPage();
};

struct CMainFrame
{
    unsigned char reserved[236];
    CommandBars* commandBars;

    void Customize();
};

void CMainFrame::Customize()
{
    if (commandBars)
    {
        CustomizeSheet sheet(commandBars, 0);
        OptionsPage options(&sheet);
        sheet.AddPage(&options);

        CommandsPage* page = sheet.commandsPage;
        page->Initialize(0x81, 0);
        page->AddCategories(0x23d1, -1);
        page->AddMenuCategory(0x81, 0x23d6, -1);
        page->AddAllCommandsCategory(0x23ca, -1);

        sheet.DoModal();
    }
}
}
