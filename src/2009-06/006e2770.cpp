// from server: 100% by auto
// roc 2009-06 006e2770  unit: RBX::ScoreHud  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e2770
//
// 006e2770  6aff                 push -1
// 006e2772  6878ef8600           push 0x86ef78
// 006e2777  64a100000000         mov eax, dword ptr fs:[0]
// 006e277d  50                   push eax
// 006e277e  64892500000000       mov dword ptr fs:[0], esp
// 006e2785  51                   push ecx
// 006e2786  56                   push esi
// 006e2787  8bf1                 mov esi, ecx
// 006e2789  6a04                 push 4
// 006e278b  89742408             mov dword ptr [esp + 8], esi
// 006e278f  e8a4620300           call 0x718a38
// 006e2794  83c404               add esp, 4
// 006e2797  85c0                 test eax, eax
// 006e2799  7404                 je 0x6e279f
// 006e279b  8930                 mov dword ptr [eax], esi
// 006e279d  eb02                 jmp 0x6e27a1
// 006e279f  33c0                 xor eax, eax
// 006e27a1  8906                 mov dword ptr [esi], eax
// 006e27a3  8bce                 mov ecx, esi
// 006e27a5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006e27ad  e8fefbffff           call 0x6e23b0
// 006e27b2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006e27b6  894618               mov dword ptr [esi + 0x18], eax
// 006e27b9  c6403101             mov byte ptr [eax + 0x31], 1
// 006e27bd  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e27c0  894004               mov dword ptr [eax + 4], eax
// 006e27c3  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e27c6  8900                 mov dword ptr [eax], eax
// 006e27c8  8b4618               mov eax, dword ptr [esi + 0x18]
// 006e27cb  894008               mov dword ptr [eax + 8], eax
// 006e27ce  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006e27d5  8bc6                 mov eax, esi
// 006e27d7  5e                   pop esi
// 006e27d8  64890d00000000       mov dword ptr fs:[0], ecx
// 006e27df  83c410               add esp, 0x10
// 006e27e2  c20800               ret 8
// standard library set<pod36> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
