// from server: 100% by Xemicl
// roc 2012-06 006f79a0  unit: RBX::ClearStarterpack  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f79a0
//
// 006f79a0  8b442404             mov eax, dword ptr [esp + 4]
// 006f79a4  56                   push esi
// 006f79a5  50                   push eax
// 006f79a6  83ec1c               sub esp, 0x1c
// 006f79a9  8bf1                 mov esi, ecx
// 006f79ab  8bcc                 mov ecx, esp
// 006f79ad  89642428             mov dword ptr [esp + 0x28], esp
// 006f79b1  68a0ceb500           push 0xb5cea0
// 006f79b6  ff154826b200         call dword ptr [0xb22648]
// 006f79bc  8bce                 mov ecx, esi
// 006f79be  e84dfeffff           call 0x6f7810
// 006f79c3  c70680c6b900         mov dword ptr [esi], 0xb9c680
// 006f79c9  8bc6                 mov eax, esi
// 006f79cb  5e                   pop esi
// 006f79cc  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("Group",p){}