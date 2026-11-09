// from server: 100% by colin
// roc 2007-08 0055fd50  unit: RBX::VModelInstance::?$FilteredSelection  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055fd50
//
// 0055fd50  8b442404             mov eax, dword ptr [esp + 4]
// 0055fd54  56                   push esi
// 0055fd55  50                   push eax
// 0055fd56  83ec1c               sub esp, 0x1c
// 0055fd59  8bf1                 mov esi, ecx
// 0055fd5b  8bcc                 mov ecx, esp
// 0055fd5d  89642428             mov dword ptr [esp + 0x28], esp
// 0055fd61  6830197900           push 0x791930
// 0055fd66  ff1598e67700         call dword ptr [0x77e698]
// 0055fd6c  8bce                 mov ecx, esi
// 0055fd6e  e8cdfeffff           call 0x55fc40
// 0055fd73  c706dc937a00         mov dword ptr [esi], 0x7a93dc
// 0055fd79  8bc6                 mov eax, esi
// 0055fd7b  5e                   pop esi
// 0055fd7c  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("SnapSelection",p){}