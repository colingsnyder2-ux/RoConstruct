// from server: 100% by colin
// roc 2007-08 0055fd80  unit: RBX::VModelInstance::?$FilteredSelection  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055fd80
//
// 0055fd80  8b442404             mov eax, dword ptr [esp + 4]
// 0055fd84  56                   push esi
// 0055fd85  50                   push eax
// 0055fd86  83ec1c               sub esp, 0x1c
// 0055fd89  8bf1                 mov esi, ecx
// 0055fd8b  8bcc                 mov ecx, esp
// 0055fd8d  89642428             mov dword ptr [esp + 0x28], esp
// 0055fd91  6850197900           push 0x791950
// 0055fd96  ff1598e67700         call dword ptr [0x77e698]
// 0055fd9c  8bce                 mov ecx, esi
// 0055fd9e  e89dfeffff           call 0x55fc40
// 0055fda3  c706f4937a00         mov dword ptr [esi], 0x7a93f4
// 0055fda9  8bc6                 mov eax, esi
// 0055fdab  5e                   pop esi
// 0055fdac  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("UnGroup",p){}