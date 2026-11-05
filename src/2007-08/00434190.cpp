// from server: 100% by Yeetserama
// roc 2007-08 00434190  unit: CObjectBrowser  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434190
//
// 00434190  6aff                 push -1
// 00434192  6883df7300           push 0x73df83
// 00434197  64a100000000         mov eax, dword ptr fs:[0]
// 0043419d  50                   push eax
// 0043419e  51                   push ecx
// 0043419f  56                   push esi
// 004341a0  a188518b00           mov eax, dword ptr [0x8b5188]
// 004341a5  33c4                 xor eax, esp
// 004341a7  50                   push eax
// 004341a8  8d44240c             lea eax, [esp + 0xc]
// 004341ac  64a300000000         mov dword ptr fs:[0], eax
// 004341b2  8bf1                 mov esi, ecx
// 004341b4  89742408             mov dword ptr [esp + 8], esi
// 004341b8  e84bc31f00           call 0x630508
// 004341bd  8d4e58               lea ecx, [esi + 0x58]
// 004341c0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004341c8  c706acc57800         mov dword ptr [esi], 0x78c5ac
// 004341ce  e83dca2500           call 0x690c10
// 004341d3  8d8e70010000         lea ecx, [esi + 0x170]
// 004341d9  c644241401           mov byte ptr [esp + 0x14], 1
// 004341de  e82dca2500           call 0x690c10
// 004341e3  8bc6                 mov eax, esi
// 004341e5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004341e9  64890d00000000       mov dword ptr fs:[0], ecx
// 004341f0  59                   pop ecx
// 004341f1  5e                   pop esi
// 004341f2  83c410               add esp, 0x10
// 004341f5  c3                   ret 
// copied from an identical function in another client (function ??0CObjectBrowser@ns_ROCX000001@@QAE@XZ)

namespace ns_ROCX000001 {
// from server: 100% by king_originala
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
