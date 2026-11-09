// from server: 100% by auto
// roc 2010-06 0076b770  unit: RBX::VChatLine::?$sp_counted_impl_p  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076b770
//
// 0076b770  6aff                 push -1
// 0076b772  6858a29900           push 0x99a258
// 0076b777  64a100000000         mov eax, dword ptr fs:[0]
// 0076b77d  50                   push eax
// 0076b77e  64892500000000       mov dword ptr fs:[0], esp
// 0076b785  51                   push ecx
// 0076b786  56                   push esi
// 0076b787  8bf1                 mov esi, ecx
// 0076b789  6a04                 push 4
// 0076b78b  89742408             mov dword ptr [esp + 8], esi
// 0076b78f  e80cc20300           call 0x7a79a0
// 0076b794  83c404               add esp, 4
// 0076b797  85c0                 test eax, eax
// 0076b799  7404                 je 0x76b79f
// 0076b79b  8930                 mov dword ptr [eax], esi
// 0076b79d  eb02                 jmp 0x76b7a1
// 0076b79f  33c0                 xor eax, eax
// 0076b7a1  8906                 mov dword ptr [esi], eax
// 0076b7a3  8bce                 mov ecx, esi
// 0076b7a5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0076b7ad  e8aefbffff           call 0x76b360
// 0076b7b2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0076b7b6  894618               mov dword ptr [esi + 0x18], eax
// 0076b7b9  c6404d01             mov byte ptr [eax + 0x4d], 1
// 0076b7bd  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076b7c0  894004               mov dword ptr [eax + 4], eax
// 0076b7c3  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076b7c6  8900                 mov dword ptr [eax], eax
// 0076b7c8  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076b7cb  894008               mov dword ptr [eax + 8], eax
// 0076b7ce  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0076b7d5  8bc6                 mov eax, esi
// 0076b7d7  5e                   pop esi
// 0076b7d8  64890d00000000       mov dword ptr fs:[0], ecx
// 0076b7df  83c410               add esp, 0x10
// 0076b7e2  c20800               ret 8
// standard library set<pod64> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod64>
struct E { int v[16]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
