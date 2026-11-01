// from server: 100% by auto
// roc 2009-12 005d1d00  unit: G3D::VVector3::?$Table  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005d1d00
//
// 005d1d00  6aff                 push -1
// 005d1d02  68d8c59300           push 0x93c5d8
// 005d1d07  64a100000000         mov eax, dword ptr fs:[0]
// 005d1d0d  50                   push eax
// 005d1d0e  64892500000000       mov dword ptr fs:[0], esp
// 005d1d15  51                   push ecx
// 005d1d16  56                   push esi
// 005d1d17  8bf1                 mov esi, ecx
// 005d1d19  6a04                 push 4
// 005d1d1b  89742408             mov dword ptr [esp + 8], esi
// 005d1d1f  e83c1b2200           call 0x7f3860
// 005d1d24  83c404               add esp, 4
// 005d1d27  85c0                 test eax, eax
// 005d1d29  7404                 je 0x5d1d2f
// 005d1d2b  8930                 mov dword ptr [eax], esi
// 005d1d2d  eb02                 jmp 0x5d1d31
// 005d1d2f  33c0                 xor eax, eax
// 005d1d31  8906                 mov dword ptr [esi], eax
// 005d1d33  8bce                 mov ecx, esi
// 005d1d35  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005d1d3d  e82ec8ffff           call 0x5ce570
// 005d1d42  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005d1d46  894618               mov dword ptr [esi + 0x18], eax
// 005d1d49  c6402101             mov byte ptr [eax + 0x21], 1
// 005d1d4d  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d1d50  894004               mov dword ptr [eax + 4], eax
// 005d1d53  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d1d56  8900                 mov dword ptr [eax], eax
// 005d1d58  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d1d5b  894008               mov dword ptr [eax + 8], eax
// 005d1d5e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005d1d65  8bc6                 mov eax, esi
// 005d1d67  5e                   pop esi
// 005d1d68  64890d00000000       mov dword ptr fs:[0], ecx
// 005d1d6f  83c410               add esp, 0x10
// 005d1d72  c20800               ret 8
// standard library set<pod20> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
