// from server: 100% by EspClaude
// roc 2009-06 00413ae0  unit: CutVerb  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00413ae0
//
// 00413ae0  8b442404             mov eax, dword ptr [esp + 4]
// 00413ae4  56                   push esi
// 00413ae5  50                   push eax
// 00413ae6  83ec1c               sub esp, 0x1c
// 00413ae9  8bf1                 mov esi, ecx
// 00413aeb  8bcc                 mov ecx, esp
// 00413aed  89642428             mov dword ptr [esp + 0x28], esp
// 00413af1  68c8f68a00           push 0x8af6c8
// 00413af6  ff15b4e48900         call dword ptr [0x89e4b4]
// 00413afc  8bce                 mov ecx, esi
// 00413afe  e81d961f00           call 0x60d120
// 00413b03  c70600f78a00         mov dword ptr [esi], 0x8af700
// 00413b09  8bc6                 mov eax, esi
// 00413b0b  5e                   pop esi
// 00413b0c  c20400               ret 4
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