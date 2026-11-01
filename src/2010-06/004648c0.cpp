// from server: 100% by Yeetserama
// roc 2010-06 004648c0  unit: InsertModelFromRobloxVerb  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004648c0
//
// 004648c0  6aff                 push -1
// 004648c2  68c8399800           push 0x9839c8
// 004648c7  64a100000000         mov eax, dword ptr fs:[0]
// 004648cd  50                   push eax
// 004648ce  64892500000000       mov dword ptr fs:[0], esp
// 004648d5  83ec08               sub esp, 8
// 004648d8  56                   push esi
// 004648d9  83ec1c               sub esp, 0x1c
// 004648dc  8bf1                 mov esi, ecx
// 004648de  8bcc                 mov ecx, esp
// 004648e0  89642424             mov dword ptr [esp + 0x24], esp
// 004648e4  6898eea000           push 0xa0ee98
// 004648e9  89742424             mov dword ptr [esp + 0x24], esi
// 004648ed  ff1510a49e00         call dword ptr [0x9ea410]
// 004648f3  8b442438             mov eax, dword ptr [esp + 0x38]
// 004648f7  50                   push eax
// 004648f8  8bce                 mov ecx, esi
// 004648fa  e821241800           call 0x5e6d20
// 004648ff  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00464907  c70684eea000         mov dword ptr [esi], 0xa0ee84
// 0046490d  e84e980e00           call 0x54e160
// 00464912  dd5e10               fstp qword ptr [esi + 0x10]
// 00464915  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00464919  8bc6                 mov eax, esi
// 0046491b  64890d00000000       mov dword ptr fs:[0], ecx
// 00464922  5e                   pop esi
// 00464923  83c414               add esp, 0x14
// 00464926  c20400               ret 4
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