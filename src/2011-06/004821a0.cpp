// from server: 100% by Yeetserama
// roc 2011-06 004821a0  unit: InsertModelFromRobloxVerb  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004821a0
//
// 004821a0  6aff                 push -1
// 004821a2  6878529d00           push 0x9d5278
// 004821a7  64a100000000         mov eax, dword ptr fs:[0]
// 004821ad  50                   push eax
// 004821ae  64892500000000       mov dword ptr fs:[0], esp
// 004821b5  83ec08               sub esp, 8
// 004821b8  56                   push esi
// 004821b9  83ec1c               sub esp, 0x1c
// 004821bc  8bf1                 mov esi, ecx
// 004821be  8bcc                 mov ecx, esp
// 004821c0  89642424             mov dword ptr [esp + 0x24], esp
// 004821c4  685023a700           push 0xa72350
// 004821c9  89742424             mov dword ptr [esp + 0x24], esi
// 004821cd  ff15c404a400         call dword ptr [0xa404c4]
// 004821d3  8b442438             mov eax, dword ptr [esp + 0x38]
// 004821d7  50                   push eax
// 004821d8  8bce                 mov ecx, esi
// 004821da  e811871800           call 0x60a8f0
// 004821df  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004821e7  c7063423a700         mov dword ptr [esi], 0xa72334
// 004821ed  e80ed50b00           call 0x53f700
// 004821f2  dd5e10               fstp qword ptr [esi + 0x10]
// 004821f5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004821f9  8bc6                 mov eax, esi
// 004821fb  64890d00000000       mov dword ptr fs:[0], ecx
// 00482202  5e                   pop esi
// 00482203  83c414               add esp, 0x14
// 00482206  c20400               ret 4
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