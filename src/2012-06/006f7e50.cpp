// roc 2012-06 006f7e50  unit: RBX::DuplicateSelectionVerb  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f7e50
//
// 006f7e50  8b442404             mov eax, dword ptr [esp + 4]
// 006f7e54  56                   push esi
// 006f7e55  50                   push eax
// 006f7e56  83ec1c               sub esp, 0x1c
// 006f7e59  8bf1                 mov esi, ecx
// 006f7e5b  8bcc                 mov ecx, esp
// 006f7e5d  89642428             mov dword ptr [esp + 0x28], esp
// 006f7e61  6898eab500           push 0xb5ea98
// 006f7e66  ff154826b200         call dword ptr [0xb22648]
// 006f7e6c  8bce                 mov ecx, esi
// 006f7e6e  e89df9ffff           call 0x6f7810
// 006f7e73  c7064cc7b900         mov dword ptr [esi], 0xb9c74c
// 006f7e79  8bc6                 mov eax, esi
// 006f7e7b  5e                   pop esi
// 006f7e7c  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("TrackCamera",p){}