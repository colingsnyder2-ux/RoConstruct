// from server: 100% by Xemicl
// roc 2012-06 006f8cc0  unit: RBX::UngroupSelectionVerb  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f8cc0
//
// 006f8cc0  8b442404             mov eax, dword ptr [esp + 4]
// 006f8cc4  56                   push esi
// 006f8cc5  50                   push eax
// 006f8cc6  83ec1c               sub esp, 0x1c
// 006f8cc9  8bf1                 mov esi, ecx
// 006f8ccb  8bcc                 mov ecx, esp
// 006f8ccd  89642428             mov dword ptr [esp + 0x28], esp
// 006f8cd1  684cceb500           push 0xb5ce4c
// 006f8cd6  ff154826b200         call dword ptr [0xb22648]
// 006f8cdc  8bce                 mov ecx, esi
// 006f8cde  e88dfaffff           call 0x6f8770
// 006f8ce3  c70620c9b900         mov dword ptr [esi], 0xb9c920
// 006f8ce9  8bc6                 mov eax, esi
// 006f8ceb  5e                   pop esi
// 006f8cec  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("SelectionRotate",p){}