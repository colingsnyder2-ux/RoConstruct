// from server: 93% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00430ae0  unit: CMainFrame  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00430ae0
//
// 00430ae0  56                   push esi
// 00430ae1  57                   push edi
// 00430ae2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00430ae6  8bf1                 mov esi, ecx
// 00430ae8  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00430aee  57                   push edi
// 00430aef  e81c2f2700           call 0x6a3a10
// 00430af4  33c0                 xor eax, eax
// 00430af6  85ff                 test edi, edi
// 00430af8  7509                 jne 0x430b03
// 00430afa  388604010000         cmp byte ptr [esi + 0x104], al
// 00430b00  0f94c0               sete al
// 00430b03  50                   push eax
// 00430b04  8d8e84020000         lea ecx, [esi + 0x284]
// 00430b0a  e831492d00           call 0x705440
// 00430b0f  57                   push edi
// 00430b10  8d8e38010000         lea ecx, [esi + 0x138]
// 00430b16  e8d55d2b00           call 0x6e68f0
// 00430b1b  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00430b21  85c9                 test ecx, ecx
// 00430b23  7406                 je 0x430b2b
// 00430b25  57                   push edi
// 00430b26  e8e52e2700           call 0x6a3a10
// 00430b2b  8b442410             mov eax, dword ptr [esp + 0x10]
// 00430b2f  50                   push eax
// 00430b30  57                   push edi
// 00430b31  8bce                 mov ecx, esi
// 00430b33  e880022700           call 0x6a0db8
// 00430b38  5f                   pop edi
// 00430b39  5e                   pop esi
// 00430b3a  c20800               ret 8

struct CommandBars {
    void sub_6a3a10(int);
};

struct TabClient {
    void sub_705440(int);
};

struct CXTPDockingPaneManager {
    char pad[0x128];
    int field_128;
    void func(int);
};

struct CMainFrame {
    char pad0[0xec];
    CommandBars* field_ec;
    char pad1[0x104 - 0xf0];
    char field_104;
    char pad2[0x138 - 0x105];
    char field_138[0x284 - 0x138];
    TabClient field_284;

    void sub_6a0db8(int, int);
    void sub_430ae0(int, int);
};

void CMainFrame::sub_430ae0(int a, int b)
{
    field_ec->sub_6a3a10(a);
    int flag = 0;
    if (a == 0)
        flag = (field_104 == 0);
    field_284.sub_705440(flag);
    ((CXTPDockingPaneManager*)field_138)->func(a);
    if (field_ec != 0)
        field_ec->sub_6a3a10(a);
    sub_6a0db8(a, b);
}
