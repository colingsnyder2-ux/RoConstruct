// from server: 100% by Xemicl
// roc 2012-06 00449400  unit: CObjectBrowser  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00449400
//
// 00449400  6aff                 push -1
// 00449402  6823e2a900           push 0xa9e223
// 00449407  64a100000000         mov eax, dword ptr fs:[0]
// 0044940d  50                   push eax
// 0044940e  64892500000000       mov dword ptr fs:[0], esp
// 00449415  51                   push ecx
// 00449416  56                   push esi
// 00449417  8bf1                 mov esi, ecx
// 00449419  89742404             mov dword ptr [esp + 4], esi
// 0044941d  e8a0965300           call 0x982ac2
// 00449422  8d4e58               lea ecx, [esi + 0x58]
// 00449425  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0044942d  c7062428b500         mov dword ptr [esi], 0xb52824
// 00449433  e8e8c25900           call 0x9e5720
// 00449438  8d8e70010000         lea ecx, [esi + 0x170]
// 0044943e  c644241001           mov byte ptr [esp + 0x10], 1
// 00449443  e8d8c25900           call 0x9e5720
// 00449448  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044944c  8bc6                 mov eax, esi
// 0044944e  5e                   pop esi
// 0044944f  64890d00000000       mov dword ptr fs:[0], ecx
// 00449456  83c410               add esp, 0x10
// 00449459  c3                   ret 
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