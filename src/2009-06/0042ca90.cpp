// from server: 100% by EspClaude
// roc 2009-06 0042ca90  unit: CObjectBrowser  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042ca90
//
// 0042ca90  6aff                 push -1
// 0042ca92  6893f38400           push 0x84f393
// 0042ca97  64a100000000         mov eax, dword ptr fs:[0]
// 0042ca9d  50                   push eax
// 0042ca9e  64892500000000       mov dword ptr fs:[0], esp
// 0042caa5  51                   push ecx
// 0042caa6  56                   push esi
// 0042caa7  8bf1                 mov esi, ecx
// 0042caa9  89742404             mov dword ptr [esp + 4], esi
// 0042caad  c7061c2d8b00         mov dword ptr [esi], 0x8b2d1c
// 0042cab3  8d8e70010000         lea ecx, [esi + 0x170]
// 0042cab9  c744241001000000     mov dword ptr [esp + 0x10], 1
// 0042cac1  e80a5d3500           call 0x7827d0
// 0042cac6  8d4e58               lea ecx, [esi + 0x58]
// 0042cac9  c644241000           mov byte ptr [esp + 0x10], 0
// 0042cace  e8fd5c3500           call 0x7827d0
// 0042cad3  8bce                 mov ecx, esi
// 0042cad5  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0042cadd  e828c92e00           call 0x71940a
// 0042cae2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042cae6  5e                   pop esi
// 0042cae7  64890d00000000       mov dword ptr fs:[0], ecx
// 0042caee  83c410               add esp, 0x10
// 0042caf1  c3                   ret 
// copied from an identical function in another client (function ??1CObjectBrowser@ns_ROCX000032@@UAE@XZ)

namespace ns_ROCX000032 {
struct Base
{
    virtual ~Base();
    char padding[0x54];
};

struct Member
{
    char storage[0x118];
    ~Member();
};

struct CObjectBrowser : Base
{
    Member first;
    Member second;
    virtual ~CObjectBrowser();
};

CObjectBrowser::~CObjectBrowser()
{
}
}
