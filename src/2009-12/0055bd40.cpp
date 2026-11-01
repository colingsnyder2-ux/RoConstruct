// from server: 100% by auto
// roc 2009-12 0055bd40  unit: RBX::Network::ServerReplicator  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0055bd40
//
// 0055bd40  6aff                 push -1
// 0055bd42  68d8c59300           push 0x93c5d8
// 0055bd47  64a100000000         mov eax, dword ptr fs:[0]
// 0055bd4d  50                   push eax
// 0055bd4e  64892500000000       mov dword ptr fs:[0], esp
// 0055bd55  51                   push ecx
// 0055bd56  56                   push esi
// 0055bd57  8bf1                 mov esi, ecx
// 0055bd59  6a04                 push 4
// 0055bd5b  89742408             mov dword ptr [esp + 8], esi
// 0055bd5f  e8fc7a2900           call 0x7f3860
// 0055bd64  83c404               add esp, 4
// 0055bd67  85c0                 test eax, eax
// 0055bd69  7404                 je 0x55bd6f
// 0055bd6b  8930                 mov dword ptr [eax], esi
// 0055bd6d  eb02                 jmp 0x55bd71
// 0055bd6f  33c0                 xor eax, eax
// 0055bd71  8906                 mov dword ptr [esi], eax
// 0055bd73  8bce                 mov ecx, esi
// 0055bd75  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0055bd7d  e8eef2ffff           call 0x55b070
// 0055bd82  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0055bd86  894618               mov dword ptr [esi + 0x18], eax
// 0055bd89  c6402501             mov byte ptr [eax + 0x25], 1
// 0055bd8d  8b4618               mov eax, dword ptr [esi + 0x18]
// 0055bd90  894004               mov dword ptr [eax + 4], eax
// 0055bd93  8b4618               mov eax, dword ptr [esi + 0x18]
// 0055bd96  8900                 mov dword ptr [eax], eax
// 0055bd98  8b4618               mov eax, dword ptr [esi + 0x18]
// 0055bd9b  894008               mov dword ptr [eax + 8], eax
// 0055bd9e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0055bda5  8bc6                 mov eax, esi
// 0055bda7  5e                   pop esi
// 0055bda8  64890d00000000       mov dword ptr fs:[0], ecx
// 0055bdaf  83c410               add esp, 0x10
// 0055bdb2  c20800               ret 8
// standard library set<pod24> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
