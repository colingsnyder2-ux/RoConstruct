// from server: 100% by Yeetserama
// roc 2011-06 00607dd0  unit: RBX::DuplicateSelectionVerb  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00607dd0
//
// 00607dd0  64a100000000         mov eax, dword ptr fs:[0]
// 00607dd6  6aff                 push -1
// 00607dd8  6809a09d00           push 0x9da009
// 00607ddd  50                   push eax
// 00607dde  64892500000000       mov dword ptr fs:[0], esp
// 00607de5  56                   push esi
// 00607de6  8bf1                 mov esi, ecx
// 00607de8  8b442418             mov eax, dword ptr [esp + 0x18]
// 00607dec  50                   push eax
// 00607ded  83ec1c               sub esp, 0x1c
// 00607df0  8d54243c             lea edx, [esp + 0x3c]
// 00607df4  8bcc                 mov ecx, esp
// 00607df6  89642438             mov dword ptr [esp + 0x38], esp
// 00607dfa  52                   push edx
// 00607dfb  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00607e03  ff15c804a400         call dword ptr [0xa404c8]
// 00607e09  8b442434             mov eax, dword ptr [esp + 0x34]
// 00607e0d  50                   push eax
// 00607e0e  8bce                 mov ecx, esi
// 00607e10  e86bfbffff           call 0x607980
// 00607e15  8d4c241c             lea ecx, [esp + 0x1c]
// 00607e19  c706c832a900         mov dword ptr [esi], 0xa932c8
// 00607e1f  c6462400             mov byte ptr [esi + 0x24], 0
// 00607e23  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 00607e2b  ff15d004a400         call dword ptr [0xa404d0]
// 00607e31  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00607e35  8bc6                 mov eax, esi
// 00607e37  64890d00000000       mov dword ptr fs:[0], ecx
// 00607e3e  5e                   pop esi
// 00607e3f  83c40c               add esp, 0xc
// 00607e42  c22400               ret 0x24
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