// from server: 100% by auto
// roc 2008-06 00649030  unit: RBX::Block  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00649030
//
// 00649030  6aff                 push -1
// 00649032  68e8727d00           push 0x7d72e8
// 00649037  64a100000000         mov eax, dword ptr fs:[0]
// 0064903d  50                   push eax
// 0064903e  64892500000000       mov dword ptr fs:[0], esp
// 00649045  51                   push ecx
// 00649046  56                   push esi
// 00649047  8bf1                 mov esi, ecx
// 00649049  6a04                 push 4
// 0064904b  89742408             mov dword ptr [esp + 8], esi
// 0064904f  e8cc780500           call 0x6a0920
// 00649054  83c404               add esp, 4
// 00649057  85c0                 test eax, eax
// 00649059  7404                 je 0x64905f
// 0064905b  8930                 mov dword ptr [eax], esi
// 0064905d  eb02                 jmp 0x649061
// 0064905f  33c0                 xor eax, eax
// 00649061  8906                 mov dword ptr [esi], eax
// 00649063  8bce                 mov ecx, esi
// 00649065  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064906d  e84ef3ffff           call 0x6483c0
// 00649072  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00649076  894618               mov dword ptr [esi + 0x18], eax
// 00649079  c6401d01             mov byte ptr [eax + 0x1d], 1
// 0064907d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00649080  894004               mov dword ptr [eax + 4], eax
// 00649083  8b4618               mov eax, dword ptr [esi + 0x18]
// 00649086  8900                 mov dword ptr [eax], eax
// 00649088  8b4618               mov eax, dword ptr [esi + 0x18]
// 0064908b  894008               mov dword ptr [eax + 8], eax
// 0064908e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00649095  8bc6                 mov eax, esi
// 00649097  5e                   pop esi
// 00649098  64890d00000000       mov dword ptr fs:[0], ecx
// 0064909f  83c410               add esp, 0x10
// 006490a2  c20800               ret 8
// standard library set<pod16> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
