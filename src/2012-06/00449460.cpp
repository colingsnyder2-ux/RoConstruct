// from server: 100% by Xemicl
// roc 2012-06 00449460  unit: CObjectBrowser  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00449460
//
// 00449460  6aff                 push -1
// 00449462  6823e2a900           push 0xa9e223
// 00449467  64a100000000         mov eax, dword ptr fs:[0]
// 0044946d  50                   push eax
// 0044946e  64892500000000       mov dword ptr fs:[0], esp
// 00449475  51                   push ecx
// 00449476  56                   push esi
// 00449477  8bf1                 mov esi, ecx
// 00449479  89742404             mov dword ptr [esp + 4], esi
// 0044947d  c7062428b500         mov dword ptr [esi], 0xb52824
// 00449483  8d8e70010000         lea ecx, [esi + 0x170]
// 00449489  c744241001000000     mov dword ptr [esp + 0x10], 1
// 00449491  e8cab85900           call 0x9e4d60
// 00449496  8d4e58               lea ecx, [esi + 0x58]
// 00449499  c644241000           mov byte ptr [esp + 0x10], 0
// 0044949e  e8bdb85900           call 0x9e4d60
// 004494a3  8bce                 mov ecx, esi
// 004494a5  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004494ad  e80a965300           call 0x982abc
// 004494b2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004494b6  5e                   pop esi
// 004494b7  64890d00000000       mov dword ptr fs:[0], ecx
// 004494be  83c410               add esp, 0x10
// 004494c1  c3                   ret 
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