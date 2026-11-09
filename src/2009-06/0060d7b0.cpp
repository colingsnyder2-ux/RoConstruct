// from server: 100% by EspClaude
// roc 2009-06 0060d7b0  unit: RBX::VModelInstance::?$FilteredSelection  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0060d7b0
//
// 0060d7b0  8b442404             mov eax, dword ptr [esp + 4]
// 0060d7b4  56                   push esi
// 0060d7b5  50                   push eax
// 0060d7b6  83ec1c               sub esp, 0x1c
// 0060d7b9  8bf1                 mov esi, ecx
// 0060d7bb  8bcc                 mov ecx, esp
// 0060d7bd  89642428             mov dword ptr [esp + 0x28], esp
// 0060d7c1  6880898b00           push 0x8b8980
// 0060d7c6  ff15b4e48900         call dword ptr [0x89e4b4]
// 0060d7cc  8bce                 mov ecx, esi
// 0060d7ce  e8fdfeffff           call 0x60d6d0
// 0060d7d3  c70604878d00         mov dword ptr [esi], 0x8d8704
// 0060d7d9  8bc6                 mov eax, esi
// 0060d7db  5e                   pop esi
// 0060d7dc  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("SelectionRotate",p){}