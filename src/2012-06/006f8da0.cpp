// from server: 100% by Xemicl
// roc 2012-06 006f8da0  unit: RBX::RotateAxisCommand  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f8da0
//
// 006f8da0  8b442404             mov eax, dword ptr [esp + 4]
// 006f8da4  56                   push esi
// 006f8da5  50                   push eax
// 006f8da6  83ec1c               sub esp, 0x1c
// 006f8da9  8bf1                 mov esi, ecx
// 006f8dab  8bcc                 mov ecx, esp
// 006f8dad  89642428             mov dword ptr [esp + 0x28], esp
// 006f8db1  683cceb500           push 0xb5ce3c
// 006f8db6  ff154826b200         call dword ptr [0xb22648]
// 006f8dbc  8bce                 mov ecx, esi
// 006f8dbe  e8adf9ffff           call 0x6f8770
// 006f8dc3  c70654c9b900         mov dword ptr [esi], 0xb9c954
// 006f8dc9  8bc6                 mov eax, esi
// 006f8dcb  5e                   pop esi
// 006f8dcc  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("SelectionTilt",p){}