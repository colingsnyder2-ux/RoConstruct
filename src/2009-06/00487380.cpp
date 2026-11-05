// from server: 100% by auto
// roc 2009-06 00487380  unit: Ogre::RbxMeshPartAdapter  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00487380
//
// 00487380  6aff                 push -1
// 00487382  6878ef8600           push 0x86ef78
// 00487387  64a100000000         mov eax, dword ptr fs:[0]
// 0048738d  50                   push eax
// 0048738e  64892500000000       mov dword ptr fs:[0], esp
// 00487395  51                   push ecx
// 00487396  56                   push esi
// 00487397  8bf1                 mov esi, ecx
// 00487399  6a04                 push 4
// 0048739b  89742408             mov dword ptr [esp + 8], esi
// 0048739f  e894162900           call 0x718a38
// 004873a4  83c404               add esp, 4
// 004873a7  85c0                 test eax, eax
// 004873a9  7404                 je 0x4873af
// 004873ab  8930                 mov dword ptr [eax], esi
// 004873ad  eb02                 jmp 0x4873b1
// 004873af  33c0                 xor eax, eax
// 004873b1  8906                 mov dword ptr [esi], eax
// 004873b3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004873b7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004873bb  50                   push eax
// 004873bc  51                   push ecx
// 004873bd  8bce                 mov ecx, esi
// 004873bf  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004873c7  e8c4f6ffff           call 0x486a90
// 004873cc  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004873d0  8bc6                 mov eax, esi
// 004873d2  5e                   pop esi
// 004873d3  64890d00000000       mov dword ptr fs:[0], ecx
// 004873da  83c410               add esp, 0x10
// 004873dd  c20800               ret 8
// standard library vector<ptr> (function ??0?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@IABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
