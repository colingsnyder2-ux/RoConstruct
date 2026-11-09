// from server: 100% by colin
// roc 2007-08 0055fef0  unit: RBX::VModelInstance::?$FilteredSelection  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055fef0
//
// 0055fef0  8b442404             mov eax, dword ptr [esp + 4]
// 0055fef4  56                   push esi
// 0055fef5  50                   push eax
// 0055fef6  83ec1c               sub esp, 0x1c
// 0055fef9  8bf1                 mov esi, ecx
// 0055fefb  8bcc                 mov ecx, esp
// 0055fefd  89642428             mov dword ptr [esp + 0x28], esp
// 0055ff01  68002f7900           push 0x792f00
// 0055ff06  ff1598e67700         call dword ptr [0x77e698]
// 0055ff0c  8bce                 mov ecx, esi
// 0055ff0e  e82dfdffff           call 0x55fc40
// 0055ff13  c70690947a00         mov dword ptr [esi], 0x7a9490
// 0055ff19  8bc6                 mov eax, esi
// 0055ff1b  5e                   pop esi
// 0055ff1c  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("WatchCamera",p){}