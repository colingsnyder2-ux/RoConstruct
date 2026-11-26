// from server: 100% by Xemicl
// roc 2012-06 00419230  unit: CutVerb  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00419230
//
// 00419230  6aff                 push -1
// 00419232  68c9b0a900           push 0xa9b0c9
// 00419237  64a100000000         mov eax, dword ptr fs:[0]
// 0041923d  50                   push eax
// 0041923e  64892500000000       mov dword ptr fs:[0], esp
// 00419245  51                   push ecx
// 00419246  56                   push esi
// 00419247  8bf1                 mov esi, ecx
// 00419249  83ec1c               sub esp, 0x1c
// 0041924c  8d44243c             lea eax, [esp + 0x3c]
// 00419250  8bcc                 mov ecx, esp
// 00419252  89642420             mov dword ptr [esp + 0x20], esp
// 00419256  50                   push eax
// 00419257  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0041925f  ff154426b200         call dword ptr [0xb22644]
// 00419265  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00419269  8b542434             mov edx, dword ptr [esp + 0x34]
// 0041926d  51                   push ecx
// 0041926e  52                   push edx
// 0041926f  8bce                 mov ecx, esi
// 00419271  e8daea2d00           call 0x6f7d50
// 00419276  8d4c2420             lea ecx, [esp + 0x20]
// 0041927a  c706506db400         mov dword ptr [esi], 0xb46d50
// 00419280  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00419288  ff153c26b200         call dword ptr [0xb2263c]
// 0041928e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00419292  8bc6                 mov eax, esi
// 00419294  64890d00000000       mov dword ptr fs:[0], ecx
// 0041929b  5e                   pop esi
// 0041929c  83c410               add esp, 0x10
// 0041929f  c22400               ret 0x24
// copied from an identical function in another client (function ??0CutVerb@@QAE@HHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Base {
    Base(int, int, std::string);
    virtual void execute();
};

struct CutVerb : Base {
    CutVerb(int, int, std::string);
    virtual void execute();
};

CutVerb::CutVerb(int a, int b, std::string name)
    : Base(a, b, name)
{
}