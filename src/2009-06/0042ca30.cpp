// from server: 100% by EspClaude
// roc 2009-06 0042ca30  unit: CObjectBrowser  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042ca30
//
// 0042ca30  6aff                 push -1
// 0042ca32  6893f38400           push 0x84f393
// 0042ca37  64a100000000         mov eax, dword ptr fs:[0]
// 0042ca3d  50                   push eax
// 0042ca3e  64892500000000       mov dword ptr fs:[0], esp
// 0042ca45  51                   push ecx
// 0042ca46  56                   push esi
// 0042ca47  8bf1                 mov esi, ecx
// 0042ca49  89742404             mov dword ptr [esp + 4], esi
// 0042ca4d  e8bec92e00           call 0x719410
// 0042ca52  8d4e58               lea ecx, [esi + 0x58]
// 0042ca55  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0042ca5d  c7061c2d8b00         mov dword ptr [esi], 0x8b2d1c
// 0042ca63  e828673500           call 0x783190
// 0042ca68  8d8e70010000         lea ecx, [esi + 0x170]
// 0042ca6e  c644241001           mov byte ptr [esp + 0x10], 1
// 0042ca73  e818673500           call 0x783190
// 0042ca78  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042ca7c  8bc6                 mov eax, esi
// 0042ca7e  5e                   pop esi
// 0042ca7f  64890d00000000       mov dword ptr fs:[0], ecx
// 0042ca86  83c410               add esp, 0x10
// 0042ca89  c3                   ret 
// copied from an identical function in another client (function ??0CObjectBrowser@ns_ROCX000031@@QAE@XZ)

namespace ns_ROCX000031 {
struct Window
{
    virtual ~Window();
    Window();

    char storage[0x54];
};

struct Splitter
{
    Splitter();
    ~Splitter();

    char storage[0x118];
};

struct CObjectBrowser : Window
{
    Splitter first;
    Splitter second;

    CObjectBrowser();
    virtual ~CObjectBrowser();
};

CObjectBrowser::CObjectBrowser()
{
}
}
