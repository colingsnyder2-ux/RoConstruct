// from server: 100% by auto
// roc 2008-06 005922d0  unit: RBX::RootInstance  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005922d0
//
// 005922d0  6aff                 push -1
// 005922d2  68e8727d00           push 0x7d72e8
// 005922d7  64a100000000         mov eax, dword ptr fs:[0]
// 005922dd  50                   push eax
// 005922de  64892500000000       mov dword ptr fs:[0], esp
// 005922e5  51                   push ecx
// 005922e6  56                   push esi
// 005922e7  8bf1                 mov esi, ecx
// 005922e9  6a04                 push 4
// 005922eb  89742408             mov dword ptr [esp + 8], esi
// 005922ef  e82ce61000           call 0x6a0920
// 005922f4  83c404               add esp, 4
// 005922f7  85c0                 test eax, eax
// 005922f9  7404                 je 0x5922ff
// 005922fb  8930                 mov dword ptr [eax], esi
// 005922fd  eb02                 jmp 0x592301
// 005922ff  33c0                 xor eax, eax
// 00592301  8906                 mov dword ptr [esi], eax
// 00592303  8bce                 mov ecx, esi
// 00592305  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0059230d  e8def5ffff           call 0x5918f0
// 00592312  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00592316  894618               mov dword ptr [esi + 0x18], eax
// 00592319  c6403101             mov byte ptr [eax + 0x31], 1
// 0059231d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00592320  894004               mov dword ptr [eax + 4], eax
// 00592323  8b4618               mov eax, dword ptr [esi + 0x18]
// 00592326  8900                 mov dword ptr [eax], eax
// 00592328  8b4618               mov eax, dword ptr [esi + 0x18]
// 0059232b  894008               mov dword ptr [eax + 8], eax
// 0059232e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00592335  8bc6                 mov eax, esi
// 00592337  5e                   pop esi
// 00592338  64890d00000000       mov dword ptr fs:[0], ecx
// 0059233f  83c410               add esp, 0x10
// 00592342  c20800               ret 8
// standard library set<pod36> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
