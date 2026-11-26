// from server: 100% by Xemicl
// roc 2012-06 006f7cf0  unit: RBX::SelectChildrenOfSelectionSelectionVerb  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f7cf0
//
// 006f7cf0  8b442404             mov eax, dword ptr [esp + 4]
// 006f7cf4  56                   push esi
// 006f7cf5  50                   push eax
// 006f7cf6  83ec1c               sub esp, 0x1c
// 006f7cf9  8bf1                 mov esi, ecx
// 006f7cfb  8bcc                 mov ecx, esp
// 006f7cfd  89642428             mov dword ptr [esp + 0x28], esp
// 006f7d01  681cc7b900           push 0xb9c71c
// 006f7d06  ff154826b200         call dword ptr [0xb22648]
// 006f7d0c  8bce                 mov ecx, esi
// 006f7d0e  e8fdfaffff           call 0x6f7810
// 006f7d13  c70600c7b900         mov dword ptr [esi], 0xb9c700
// 006f7d19  8bc6                 mov eax, esi
// 006f7d1b  5e                   pop esi
// 006f7d1c  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("Duplicate",p){}