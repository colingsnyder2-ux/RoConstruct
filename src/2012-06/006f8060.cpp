// from server: 100% by Xemicl
// roc 2012-06 006f8060  unit: RBX::TrackCameraCommand  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f8060
//
// 006f8060  8b442404             mov eax, dword ptr [esp + 4]
// 006f8064  56                   push esi
// 006f8065  50                   push eax
// 006f8066  83ec1c               sub esp, 0x1c
// 006f8069  8bf1                 mov esi, ecx
// 006f806b  8bcc                 mov ecx, esp
// 006f806d  89642428             mov dword ptr [esp + 0x28], esp
// 006f8071  6804ceb500           push 0xb5ce04
// 006f8076  ff154826b200         call dword ptr [0xb22648]
// 006f807c  8bce                 mov ecx, esi
// 006f807e  e88df7ffff           call 0x6f7810
// 006f8083  c70644c8b900         mov dword ptr [esi], 0xb9c844
// 006f8089  8bc6                 mov eax, esi
// 006f808b  5e                   pop esi
// 006f808c  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("SelectionDown",p){}