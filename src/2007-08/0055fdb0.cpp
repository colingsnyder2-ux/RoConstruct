// from server: 100% by colin
// roc 2007-08 0055fdb0  unit: RBX::VModelInstance::?$FilteredSelection  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055fdb0
//
// 0055fdb0  8b442404             mov eax, dword ptr [esp + 4]
// 0055fdb4  56                   push esi
// 0055fdb5  50                   push eax
// 0055fdb6  83ec1c               sub esp, 0x1c
// 0055fdb9  8bf1                 mov esi, ecx
// 0055fdbb  8bcc                 mov ecx, esp
// 0055fdbd  89642428             mov dword ptr [esp + 0x28], esp
// 0055fdc1  6820947a00           push 0x7a9420
// 0055fdc6  ff1598e67700         call dword ptr [0x77e698]
// 0055fdcc  8bce                 mov ecx, esi
// 0055fdce  e86dfeffff           call 0x55fc40
// 0055fdd3  c7060c947a00         mov dword ptr [esi], 0x7a940c
// 0055fdd9  8bc6                 mov eax, esi
// 0055fddb  5e                   pop esi
// 0055fddc  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("Duplicate",p){}