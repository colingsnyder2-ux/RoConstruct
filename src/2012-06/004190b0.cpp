// from server: 100% by Xemicl
// roc 2012-06 004190b0  unit: CutVerb  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004190b0
//
// 004190b0  8b442404             mov eax, dword ptr [esp + 4]
// 004190b4  56                   push esi
// 004190b5  50                   push eax
// 004190b6  83ec1c               sub esp, 0x1c
// 004190b9  8bf1                 mov esi, ecx
// 004190bb  8bcc                 mov ecx, esp
// 004190bd  89642428             mov dword ptr [esp + 0x28], esp
// 004190c1  68dc6cb400           push 0xb46cdc
// 004190c6  ff154826b200         call dword ptr [0xb22648]
// 004190cc  8bce                 mov ecx, esi
// 004190ce  e83de72d00           call 0x6f7810
// 004190d3  c7061c6db400         mov dword ptr [esi], 0xb46d1c
// 004190d9  8bc6                 mov eax, esi
// 004190db  5e                   pop esi
// 004190dc  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("Copy",p){}
__declspec(noinline) void use(){CutVerb x(0);}