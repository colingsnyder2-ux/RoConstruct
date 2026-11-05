// from server: 100% by colin
// roc 2007-08 00560b10  unit: RBX::VModelInstance::?$FilteredSelection  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00560b10
//
// 00560b10  8b442404             mov eax, dword ptr [esp + 4]
// 00560b14  56                   push esi
// 00560b15  50                   push eax
// 00560b16  83ec1c               sub esp, 0x1c
// 00560b19  8bf1                 mov esi, ecx
// 00560b1b  8bcc                 mov ecx, esp
// 00560b1d  89642428             mov dword ptr [esp + 0x28], esp
// 00560b21  687c957a00           push 0x7a957c
// 00560b26  ff1598e67700         call dword ptr [0x77e698]
// 00560b2c  8bce                 mov ecx, esi
// 00560b2e  e8cdfaffff           call 0x560600
// 00560b33  c70668957a00         mov dword ptr [esi], 0x7a9568
// 00560b39  8bc6                 mov eax, esi
// 00560b3b  5e                   pop esi
// 00560b3c  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("Controller2",p){}