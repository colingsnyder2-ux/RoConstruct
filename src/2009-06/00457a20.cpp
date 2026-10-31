// from server: 100% by EspClaude
// roc 2009-06 00457a20  unit: InsertModelFromRobloxVerb  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00457a20
//
// 00457a20  6aff                 push -1
// 00457a22  6818208500           push 0x852018
// 00457a27  64a100000000         mov eax, dword ptr fs:[0]
// 00457a2d  50                   push eax
// 00457a2e  64892500000000       mov dword ptr fs:[0], esp
// 00457a35  83ec08               sub esp, 8
// 00457a38  56                   push esi
// 00457a39  83ec1c               sub esp, 0x1c
// 00457a3c  8bf1                 mov esi, ecx
// 00457a3e  8bcc                 mov ecx, esp
// 00457a40  89642424             mov dword ptr [esp + 0x24], esp
// 00457a44  68a09a8b00           push 0x8b9aa0
// 00457a49  89742424             mov dword ptr [esp + 0x24], esi
// 00457a4d  ff15b4e48900         call dword ptr [0x89e4b4]
// 00457a53  8b442438             mov eax, dword ptr [esp + 0x38]
// 00457a57  50                   push eax
// 00457a58  8bce                 mov ecx, esi
// 00457a5a  e8618f1b00           call 0x6109c0
// 00457a5f  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00457a67  c7068c9a8b00         mov dword ptr [esi], 0x8b9a8c
// 00457a6d  e8de3f1100           call 0x56ba50
// 00457a72  dd5e10               fstp qword ptr [esi + 0x10]
// 00457a75  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00457a79  8bc6                 mov eax, esi
// 00457a7b  64890d00000000       mov dword ptr fs:[0], ecx
// 00457a82  5e                   pop esi
// 00457a83  83c414               add esp, 0x14
// 00457a86  c20400               ret 4
// copied from an identical function in another client (function ??0ToggleIDEModeVerb@@QAE@PAVVerbContainer@RBX@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>

namespace RBX {
class Debugable {
public:
    virtual ~Debugable() {}
};
class VerbContainer;
class Verb : public Debugable {
public:
    Verb(VerbContainer* container, std::string name);
    virtual ~Verb();
    int data[2];
};
}

double __cdecl readTime();

class ToggleIDEModeVerb : public RBX::Verb {
public:
    double lastToggle;
    ToggleIDEModeVerb(RBX::VerbContainer* container);
    virtual ~ToggleIDEModeVerb() {}
};

ToggleIDEModeVerb::ToggleIDEModeVerb(RBX::VerbContainer* container)
    : RBX::Verb(container, "TogglePlayMode")
{
    lastToggle = readTime();
}