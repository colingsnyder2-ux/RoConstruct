// from server: 100% by colin
// roc 2007-08 0055fcf0  unit: RBX::VModelInstance::?$FilteredSelection  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055fcf0
//
// 0055fcf0  8b442404             mov eax, dword ptr [esp + 4]
// 0055fcf4  56                   push esi
// 0055fcf5  50                   push eax
// 0055fcf6  83ec1c               sub esp, 0x1c
// 0055fcf9  8bf1                 mov esi, ecx
// 0055fcfb  8bcc                 mov ecx, esp
// 0055fcfd  89642428             mov dword ptr [esp + 0x28], esp
// 0055fd01  6858197900           push 0x791958
// 0055fd06  ff1598e67700         call dword ptr [0x77e698]
// 0055fd0c  8bce                 mov ecx, esi
// 0055fd0e  e82dffffff           call 0x55fc40
// 0055fd13  c706ac937a00         mov dword ptr [esi], 0x7a93ac
// 0055fd19  8bc6                 mov eax, esi
// 0055fd1b  5e                   pop esi
// 0055fd1c  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("Group",p){}