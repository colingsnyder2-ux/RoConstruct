// from server: 100% by auto
// roc 2009-12 006bf410  unit: RBX::VInstance::?$NonFactoryProduct  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bf410
//
// 006bf410  6aff                 push -1
// 006bf412  68d8c59300           push 0x93c5d8
// 006bf417  64a100000000         mov eax, dword ptr fs:[0]
// 006bf41d  50                   push eax
// 006bf41e  64892500000000       mov dword ptr fs:[0], esp
// 006bf425  51                   push ecx
// 006bf426  56                   push esi
// 006bf427  8bf1                 mov esi, ecx
// 006bf429  6a04                 push 4
// 006bf42b  89742408             mov dword ptr [esp + 8], esi
// 006bf42f  e82c441300           call 0x7f3860
// 006bf434  83c404               add esp, 4
// 006bf437  85c0                 test eax, eax
// 006bf439  7404                 je 0x6bf43f
// 006bf43b  8930                 mov dword ptr [eax], esi
// 006bf43d  eb02                 jmp 0x6bf441
// 006bf43f  33c0                 xor eax, eax
// 006bf441  8906                 mov dword ptr [esi], eax
// 006bf443  8bce                 mov ecx, esi
// 006bf445  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006bf44d  e8fee5ffff           call 0x6bda50
// 006bf452  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006bf456  894614               mov dword ptr [esi + 0x14], eax
// 006bf459  c7461800000000       mov dword ptr [esi + 0x18], 0
// 006bf460  8bc6                 mov eax, esi
// 006bf462  5e                   pop esi
// 006bf463  64890d00000000       mov dword ptr fs:[0], ecx
// 006bf46a  83c410               add esp, 0x10
// 006bf46d  c3                   ret 
// standard library list<ptr> (function ??0?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE@XZ)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
