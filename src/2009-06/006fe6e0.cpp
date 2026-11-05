// from server: 100% by auto
// roc 2009-06 006fe6e0  unit: RBX::AdornRbxGfx  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fe6e0
//
// 006fe6e0  6aff                 push -1
// 006fe6e2  6878ef8600           push 0x86ef78
// 006fe6e7  64a100000000         mov eax, dword ptr fs:[0]
// 006fe6ed  50                   push eax
// 006fe6ee  64892500000000       mov dword ptr fs:[0], esp
// 006fe6f5  51                   push ecx
// 006fe6f6  56                   push esi
// 006fe6f7  8bf1                 mov esi, ecx
// 006fe6f9  6a04                 push 4
// 006fe6fb  89742408             mov dword ptr [esp + 8], esi
// 006fe6ff  e834a30100           call 0x718a38
// 006fe704  83c404               add esp, 4
// 006fe707  85c0                 test eax, eax
// 006fe709  7404                 je 0x6fe70f
// 006fe70b  8930                 mov dword ptr [eax], esi
// 006fe70d  eb02                 jmp 0x6fe711
// 006fe70f  33c0                 xor eax, eax
// 006fe711  8906                 mov dword ptr [esi], eax
// 006fe713  8bce                 mov ecx, esi
// 006fe715  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006fe71d  e80e58f4ff           call 0x643f30
// 006fe722  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006fe726  894618               mov dword ptr [esi + 0x18], eax
// 006fe729  c6403501             mov byte ptr [eax + 0x35], 1
// 006fe72d  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fe730  894004               mov dword ptr [eax + 4], eax
// 006fe733  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fe736  8900                 mov dword ptr [eax], eax
// 006fe738  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fe73b  894008               mov dword ptr [eax + 8], eax
// 006fe73e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006fe745  8bc6                 mov eax, esi
// 006fe747  5e                   pop esi
// 006fe748  64890d00000000       mov dword ptr fs:[0], ecx
// 006fe74f  83c410               add esp, 0x10
// 006fe752  c20800               ret 8
// standard library set<pod40> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
