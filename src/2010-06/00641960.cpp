// from server: 100% by auto
// roc 2010-06 00641960  unit: RBX::VInstance::?$NonFactoryProduct  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00641960
//
// 00641960  6aff                 push -1
// 00641962  6858a29900           push 0x99a258
// 00641967  64a100000000         mov eax, dword ptr fs:[0]
// 0064196d  50                   push eax
// 0064196e  64892500000000       mov dword ptr fs:[0], esp
// 00641975  51                   push ecx
// 00641976  56                   push esi
// 00641977  8bf1                 mov esi, ecx
// 00641979  6a04                 push 4
// 0064197b  89742408             mov dword ptr [esp + 8], esi
// 0064197f  e81c601600           call 0x7a79a0
// 00641984  83c404               add esp, 4
// 00641987  85c0                 test eax, eax
// 00641989  7404                 je 0x64198f
// 0064198b  8930                 mov dword ptr [eax], esi
// 0064198d  eb02                 jmp 0x641991
// 0064198f  33c0                 xor eax, eax
// 00641991  8906                 mov dword ptr [esi], eax
// 00641993  8bce                 mov ecx, esi
// 00641995  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064199d  e87e07feff           call 0x622120
// 006419a2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006419a6  894618               mov dword ptr [esi + 0x18], eax
// 006419a9  c6403501             mov byte ptr [eax + 0x35], 1
// 006419ad  8b4618               mov eax, dword ptr [esi + 0x18]
// 006419b0  894004               mov dword ptr [eax + 4], eax
// 006419b3  8b4618               mov eax, dword ptr [esi + 0x18]
// 006419b6  8900                 mov dword ptr [eax], eax
// 006419b8  8b4618               mov eax, dword ptr [esi + 0x18]
// 006419bb  894008               mov dword ptr [eax + 8], eax
// 006419be  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006419c5  8bc6                 mov eax, esi
// 006419c7  5e                   pop esi
// 006419c8  64890d00000000       mov dword ptr fs:[0], ecx
// 006419cf  83c410               add esp, 0x10
// 006419d2  c20800               ret 8
// standard library set<pod40> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
