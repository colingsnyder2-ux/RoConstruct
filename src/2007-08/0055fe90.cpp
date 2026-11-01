// from server: 100% by colin
// roc 2007-08 0055fe90  unit: RBX::VModelInstance::?$FilteredSelection  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055fe90
//
// 0055fe90  8b442404             mov eax, dword ptr [esp + 4]
// 0055fe94  56                   push esi
// 0055fe95  50                   push eax
// 0055fe96  83ec1c               sub esp, 0x1c
// 0055fe99  8bf1                 mov esi, ecx
// 0055fe9b  8bcc                 mov ecx, esp
// 0055fe9d  89642428             mov dword ptr [esp + 0x28], esp
// 0055fea1  681c2f7900           push 0x792f1c
// 0055fea6  ff1598e67700         call dword ptr [0x77e698]
// 0055feac  8bce                 mov ecx, esi
// 0055feae  e88dfdffff           call 0x55fc40
// 0055feb3  c70660947a00         mov dword ptr [esi], 0x7a9460
// 0055feb9  8bc6                 mov eax, esi
// 0055febb  5e                   pop esi
// 0055febc  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("TrackCamera",p){}