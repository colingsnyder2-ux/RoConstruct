// from server: 100% by EspClaude
// roc 2009-06 0060d3a0  unit: RBX::VModelInstance::?$FilteredSelection  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0060d3a0
//
// 0060d3a0  8b442404             mov eax, dword ptr [esp + 4]
// 0060d3a4  56                   push esi
// 0060d3a5  50                   push eax
// 0060d3a6  83ec1c               sub esp, 0x1c
// 0060d3a9  8bf1                 mov esi, ecx
// 0060d3ab  8bcc                 mov ecx, esp
// 0060d3ad  89642428             mov dword ptr [esp + 0x28], esp
// 0060d3b1  6838898b00           push 0x8b8938
// 0060d3b6  ff15b4e48900         call dword ptr [0x89e4b4]
// 0060d3bc  8bce                 mov ecx, esi
// 0060d3be  e85dfdffff           call 0x60d120
// 0060d3c3  c706b8868d00         mov dword ptr [esi], 0x8d86b8
// 0060d3c9  8bc6                 mov eax, esi
// 0060d3cb  5e                   pop esi
// 0060d3cc  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("SelectionDown",p){}