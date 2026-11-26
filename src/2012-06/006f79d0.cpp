// from server: 100% by Xemicl
// roc 2012-06 006f79d0  unit: RBX::ClearStarterpack  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f79d0
//
// 006f79d0  8b442404             mov eax, dword ptr [esp + 4]
// 006f79d4  56                   push esi
// 006f79d5  50                   push eax
// 006f79d6  83ec1c               sub esp, 0x1c
// 006f79d9  8bf1                 mov esi, ecx
// 006f79db  8bcc                 mov ecx, esp
// 006f79dd  89642428             mov dword ptr [esp + 0x28], esp
// 006f79e1  686cceb500           push 0xb5ce6c
// 006f79e6  ff154826b200         call dword ptr [0xb22648]
// 006f79ec  8bce                 mov ecx, esi
// 006f79ee  e81dfeffff           call 0x6f7810
// 006f79f3  c706a0c6b900         mov dword ptr [esi], 0xb9c6a0
// 006f79f9  8bc6                 mov eax, esi
// 006f79fb  5e                   pop esi
// 006f79fc  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("WeldSelection",p){}