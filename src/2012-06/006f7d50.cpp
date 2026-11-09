// from server: 100% by Yeetserama
// roc 2012-06 006f7d50  unit: RBX::DuplicateSelectionVerb  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f7d50
//
// 006f7d50  64a100000000         mov eax, dword ptr fs:[0]
// 006f7d56  6aff                 push -1
// 006f7d58  68c9b0a900           push 0xa9b0c9
// 006f7d5d  50                   push eax
// 006f7d5e  64892500000000       mov dword ptr fs:[0], esp
// 006f7d65  56                   push esi
// 006f7d66  8bf1                 mov esi, ecx
// 006f7d68  8b442418             mov eax, dword ptr [esp + 0x18]
// 006f7d6c  50                   push eax
// 006f7d6d  83ec1c               sub esp, 0x1c
// 006f7d70  8d54243c             lea edx, [esp + 0x3c]
// 006f7d74  8bcc                 mov ecx, esp
// 006f7d76  89642438             mov dword ptr [esp + 0x38], esp
// 006f7d7a  52                   push edx
// 006f7d7b  c744243000000000     mov dword ptr [esp + 0x30], 0
// 006f7d83  ff154426b200         call dword ptr [0xb22644]
// 006f7d89  8b442434             mov eax, dword ptr [esp + 0x34]
// 006f7d8d  50                   push eax
// 006f7d8e  8bce                 mov ecx, esi
// 006f7d90  e81bfbffff           call 0x6f78b0
// 006f7d95  8d4c241c             lea ecx, [esp + 0x1c]
// 006f7d99  c7062cc7b900         mov dword ptr [esi], 0xb9c72c
// 006f7d9f  c6462400             mov byte ptr [esi + 0x24], 0
// 006f7da3  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 006f7dab  ff153c26b200         call dword ptr [0xb2263c]
// 006f7db1  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006f7db5  8bc6                 mov eax, esi
// 006f7db7  64890d00000000       mov dword ptr fs:[0], ecx
// 006f7dbe  5e                   pop esi
// 006f7dbf  83c40c               add esp, 0xc
// 006f7dc2  c22400               ret 0x24
// copied from an identical function in another client (function ??0DuplicateSelectionVerb@@QAE@PAX0V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Base
{
    unsigned char storage[32];

    Base(void*, std::string, void*);
    virtual ~Base();
};

struct DuplicateSelectionVerb : Base
{
    bool flag;

    DuplicateSelectionVerb(void*, void*, std::string);
    virtual ~DuplicateSelectionVerb();
};

DuplicateSelectionVerb::DuplicateSelectionVerb(
    void* first, void* second, std::string text)
    : Base(first, text, second)
{
    flag = false;
}