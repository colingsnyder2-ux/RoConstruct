// from server: 100% by Yeetserama
// roc 2007-08 00434200  unit: CObjectBrowser  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434200
//
// 00434200  6aff                 push -1
// 00434202  6883df7300           push 0x73df83
// 00434207  64a100000000         mov eax, dword ptr fs:[0]
// 0043420d  50                   push eax
// 0043420e  51                   push ecx
// 0043420f  56                   push esi
// 00434210  a188518b00           mov eax, dword ptr [0x8b5188]
// 00434215  33c4                 xor eax, esp
// 00434217  50                   push eax
// 00434218  8d44240c             lea eax, [esp + 0xc]
// 0043421c  64a300000000         mov dword ptr fs:[0], eax
// 00434222  8bf1                 mov esi, ecx
// 00434224  89742408             mov dword ptr [esp + 8], esi
// 00434228  c706acc57800         mov dword ptr [esi], 0x78c5ac
// 0043422e  8d8e70010000         lea ecx, [esi + 0x170]
// 00434234  c744241401000000     mov dword ptr [esp + 0x14], 1
// 0043423c  e85fc02500           call 0x6902a0
// 00434241  8d4e58               lea ecx, [esi + 0x58]
// 00434244  c644241400           mov byte ptr [esp + 0x14], 0
// 00434249  e852c02500           call 0x6902a0
// 0043424e  8bce                 mov ecx, esi
// 00434250  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00434258  e8a5c21f00           call 0x630502
// 0043425d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00434261  64890d00000000       mov dword ptr fs:[0], ecx
// 00434268  59                   pop ecx
// 00434269  5e                   pop esi
// 0043426a  83c410               add esp, 0x10
// 0043426d  c3                   ret 
// copied from an identical function in another client (function ??1CObjectBrowser@ns_ROCX000002@@UAE@XZ)

namespace ns_ROCX000002 {
// from server: 100% by king_originala
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
