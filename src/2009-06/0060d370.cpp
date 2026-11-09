// from server: 100% by EspClaude
// roc 2009-06 0060d370  unit: RBX::VModelInstance::?$FilteredSelection  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0060d370
//
// 0060d370  8b442404             mov eax, dword ptr [esp + 4]
// 0060d374  56                   push esi
// 0060d375  50                   push eax
// 0060d376  83ec1c               sub esp, 0x1c
// 0060d379  8bf1                 mov esi, ecx
// 0060d37b  8bcc                 mov ecx, esp
// 0060d37d  89642428             mov dword ptr [esp + 0x28], esp
// 0060d381  6860a08b00           push 0x8ba060
// 0060d386  ff15b4e48900         call dword ptr [0x89e4b4]
// 0060d38c  8bce                 mov ecx, esi
// 0060d38e  e88dfdffff           call 0x60d120
// 0060d393  c706a0868d00         mov dword ptr [esi], 0x8d86a0
// 0060d399  8bc6                 mov eax, esi
// 0060d39b  5e                   pop esi
// 0060d39c  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("WatchCamera",p){}