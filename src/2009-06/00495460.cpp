// from server: 100% by auto
// roc 2009-06 00495460  unit: Ogre::RbxMaterialAdapter  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00495460
//
// 00495460  6aff                 push -1
// 00495462  6878ef8600           push 0x86ef78
// 00495467  64a100000000         mov eax, dword ptr fs:[0]
// 0049546d  50                   push eax
// 0049546e  64892500000000       mov dword ptr fs:[0], esp
// 00495475  51                   push ecx
// 00495476  56                   push esi
// 00495477  8bf1                 mov esi, ecx
// 00495479  6a04                 push 4
// 0049547b  89742408             mov dword ptr [esp + 8], esi
// 0049547f  e8b4352800           call 0x718a38
// 00495484  83c404               add esp, 4
// 00495487  85c0                 test eax, eax
// 00495489  7404                 je 0x49548f
// 0049548b  8930                 mov dword ptr [eax], esi
// 0049548d  eb02                 jmp 0x495491
// 0049548f  33c0                 xor eax, eax
// 00495491  8906                 mov dword ptr [esi], eax
// 00495493  8bce                 mov ecx, esi
// 00495495  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0049549d  e85efaffff           call 0x494f00
// 004954a2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004954a6  894614               mov dword ptr [esi + 0x14], eax
// 004954a9  c7461800000000       mov dword ptr [esi + 0x18], 0
// 004954b0  8bc6                 mov eax, esi
// 004954b2  5e                   pop esi
// 004954b3  64890d00000000       mov dword ptr fs:[0], ecx
// 004954ba  83c410               add esp, 0x10
// 004954bd  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
