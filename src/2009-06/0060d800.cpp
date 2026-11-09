// from server: 100% by EspClaude
// roc 2009-06 0060d800  unit: RBX::DeleteSelectionVerb  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0060d800
//
// 0060d800  8b442404             mov eax, dword ptr [esp + 4]
// 0060d804  56                   push esi
// 0060d805  50                   push eax
// 0060d806  83ec1c               sub esp, 0x1c
// 0060d809  8bf1                 mov esi, ecx
// 0060d80b  8bcc                 mov ecx, esp
// 0060d80d  89642428             mov dword ptr [esp + 0x28], esp
// 0060d811  6870898b00           push 0x8b8970
// 0060d816  ff15b4e48900         call dword ptr [0x89e4b4]
// 0060d81c  8bce                 mov ecx, esi
// 0060d81e  e8adfeffff           call 0x60d6d0
// 0060d823  c70620878d00         mov dword ptr [esi], 0x8d8720
// 0060d829  8bc6                 mov eax, esi
// 0060d82b  5e                   pop esi
// 0060d82c  c20400               ret 4
// copied from an identical function in another client (function ??0CutVerb@@QAE@H@Z)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B{virtual ~B(){}; B(std::string,int);};
struct CutVerb:B{CutVerb(int);};
CutVerb::CutVerb(int p):B("SelectionTilt",p){}