// from server: 100% by colin
// roc 2007-08 0055ff20  unit: RBX::VModelInstance::?$FilteredSelection  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055ff20
//
// 0055ff20  8b442404             mov eax, dword ptr [esp + 4]
// 0055ff24  56                   push esi
// 0055ff25  50                   push eax
// 0055ff26  83ec1c               sub esp, 0x1c
// 0055ff29  8bf1                 mov esi, ecx
// 0055ff2b  8bcc                 mov ecx, esp
// 0055ff2d  89642428             mov dword ptr [esp + 0x28], esp
// 0055ff31  68d8187900           push 0x7918d8
// 0055ff36  ff1598e67700         call dword ptr [0x77e698]
// 0055ff3c  8bce                 mov ecx, esi
// 0055ff3e  e8fdfcffff           call 0x55fc40
// 0055ff43  c706a8947a00         mov dword ptr [esi], 0x7a94a8
// 0055ff49  8bc6                 mov eax, esi
// 0055ff4b  5e                   pop esi
// 0055ff4c  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("SelectionDown",p){}