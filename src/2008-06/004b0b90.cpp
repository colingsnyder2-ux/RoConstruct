// from server: 100% by auto
// roc 2008-06 004b0b90  unit: RBX::Network::Replicator::NewInstanceItem  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b0b90
//
// 004b0b90  6aff                 push -1
// 004b0b92  68e8727d00           push 0x7d72e8
// 004b0b97  64a100000000         mov eax, dword ptr fs:[0]
// 004b0b9d  50                   push eax
// 004b0b9e  64892500000000       mov dword ptr fs:[0], esp
// 004b0ba5  51                   push ecx
// 004b0ba6  56                   push esi
// 004b0ba7  8bf1                 mov esi, ecx
// 004b0ba9  6a04                 push 4
// 004b0bab  89742408             mov dword ptr [esp + 8], esi
// 004b0baf  e86cfd1e00           call 0x6a0920
// 004b0bb4  83c404               add esp, 4
// 004b0bb7  85c0                 test eax, eax
// 004b0bb9  7404                 je 0x4b0bbf
// 004b0bbb  8930                 mov dword ptr [eax], esi
// 004b0bbd  eb02                 jmp 0x4b0bc1
// 004b0bbf  33c0                 xor eax, eax
// 004b0bc1  8906                 mov dword ptr [esi], eax
// 004b0bc3  8bce                 mov ecx, esi
// 004b0bc5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004b0bcd  e81ec0ffff           call 0x4acbf0
// 004b0bd2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004b0bd6  894618               mov dword ptr [esi + 0x18], eax
// 004b0bd9  c6403d01             mov byte ptr [eax + 0x3d], 1
// 004b0bdd  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b0be0  894004               mov dword ptr [eax + 4], eax
// 004b0be3  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b0be6  8900                 mov dword ptr [eax], eax
// 004b0be8  8b4618               mov eax, dword ptr [esi + 0x18]
// 004b0beb  894008               mov dword ptr [eax + 8], eax
// 004b0bee  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004b0bf5  8bc6                 mov eax, esi
// 004b0bf7  5e                   pop esi
// 004b0bf8  64890d00000000       mov dword ptr fs:[0], ecx
// 004b0bff  83c410               add esp, 0x10
// 004b0c02  c20800               ret 8
// standard library set<pod48> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
