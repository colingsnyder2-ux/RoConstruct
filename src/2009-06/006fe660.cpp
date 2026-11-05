// from server: 100% by auto
// roc 2009-06 006fe660  unit: RBX::AdornRbxGfx  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fe660
//
// 006fe660  6aff                 push -1
// 006fe662  6878ef8600           push 0x86ef78
// 006fe667  64a100000000         mov eax, dword ptr fs:[0]
// 006fe66d  50                   push eax
// 006fe66e  64892500000000       mov dword ptr fs:[0], esp
// 006fe675  51                   push ecx
// 006fe676  56                   push esi
// 006fe677  8bf1                 mov esi, ecx
// 006fe679  6a04                 push 4
// 006fe67b  89742408             mov dword ptr [esp + 8], esi
// 006fe67f  e8b4a30100           call 0x718a38
// 006fe684  83c404               add esp, 4
// 006fe687  85c0                 test eax, eax
// 006fe689  7404                 je 0x6fe68f
// 006fe68b  8930                 mov dword ptr [eax], esi
// 006fe68d  eb02                 jmp 0x6fe691
// 006fe68f  33c0                 xor eax, eax
// 006fe691  8906                 mov dword ptr [esi], eax
// 006fe693  8bce                 mov ecx, esi
// 006fe695  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006fe69d  e84e62deff           call 0x4e48f0
// 006fe6a2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006fe6a6  894618               mov dword ptr [esi + 0x18], eax
// 006fe6a9  c6402d01             mov byte ptr [eax + 0x2d], 1
// 006fe6ad  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fe6b0  894004               mov dword ptr [eax + 4], eax
// 006fe6b3  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fe6b6  8900                 mov dword ptr [eax], eax
// 006fe6b8  8b4618               mov eax, dword ptr [esi + 0x18]
// 006fe6bb  894008               mov dword ptr [eax + 8], eax
// 006fe6be  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006fe6c5  8bc6                 mov eax, esi
// 006fe6c7  5e                   pop esi
// 006fe6c8  64890d00000000       mov dword ptr fs:[0], ecx
// 006fe6cf  83c410               add esp, 0x10
// 006fe6d2  c20800               ret 8
// standard library set<pod32> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
