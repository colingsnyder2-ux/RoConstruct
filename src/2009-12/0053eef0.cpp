// from server: 100% by auto
// roc 2009-12 0053eef0  unit: RBX::Network::Replicator::NewInstanceItem  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053eef0
//
// 0053eef0  6aff                 push -1
// 0053eef2  68d8c59300           push 0x93c5d8
// 0053eef7  64a100000000         mov eax, dword ptr fs:[0]
// 0053eefd  50                   push eax
// 0053eefe  64892500000000       mov dword ptr fs:[0], esp
// 0053ef05  51                   push ecx
// 0053ef06  56                   push esi
// 0053ef07  8bf1                 mov esi, ecx
// 0053ef09  6a04                 push 4
// 0053ef0b  89742408             mov dword ptr [esp + 8], esi
// 0053ef0f  e84c492b00           call 0x7f3860
// 0053ef14  83c404               add esp, 4
// 0053ef17  85c0                 test eax, eax
// 0053ef19  7404                 je 0x53ef1f
// 0053ef1b  8930                 mov dword ptr [eax], esi
// 0053ef1d  eb02                 jmp 0x53ef21
// 0053ef1f  33c0                 xor eax, eax
// 0053ef21  8906                 mov dword ptr [esi], eax
// 0053ef23  8bce                 mov ecx, esi
// 0053ef25  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0053ef2d  e82ee31600           call 0x6ad260
// 0053ef32  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0053ef36  894618               mov dword ptr [esi + 0x18], eax
// 0053ef39  c6402d01             mov byte ptr [eax + 0x2d], 1
// 0053ef3d  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053ef40  894004               mov dword ptr [eax + 4], eax
// 0053ef43  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053ef46  8900                 mov dword ptr [eax], eax
// 0053ef48  8b4618               mov eax, dword ptr [esi + 0x18]
// 0053ef4b  894008               mov dword ptr [eax + 8], eax
// 0053ef4e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0053ef55  8bc6                 mov eax, esi
// 0053ef57  5e                   pop esi
// 0053ef58  64890d00000000       mov dword ptr fs:[0], ecx
// 0053ef5f  83c410               add esp, 0x10
// 0053ef62  c20800               ret 8
// standard library set<pod32> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
