// from server: 100% by Xemicl
// roc 2012-06 006f7a00  unit: RBX::ClearStarterpack  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f7a00
//
// 006f7a00  8b442404             mov eax, dword ptr [esp + 4]
// 006f7a04  56                   push esi
// 006f7a05  50                   push eax
// 006f7a06  83ec1c               sub esp, 0x1c
// 006f7a09  8bf1                 mov esi, ecx
// 006f7a0b  8bcc                 mov ecx, esp
// 006f7a0d  89642428             mov dword ptr [esp + 0x28], esp
// 006f7a11  685cceb500           push 0xb5ce5c
// 006f7a16  ff154826b200         call dword ptr [0xb22648]
// 006f7a1c  8bce                 mov ecx, esi
// 006f7a1e  e8edfdffff           call 0x6f7810
// 006f7a23  c706c0c6b900         mov dword ptr [esi], 0xb9c6c0
// 006f7a29  8bc6                 mov eax, esi
// 006f7a2b  5e                   pop esi
// 006f7a2c  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("SnapSelection",p){}