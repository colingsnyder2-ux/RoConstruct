// from server: 100% by auto
// roc 2009-06 006d3d50  unit: RBX::Block  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d3d50
//
// 006d3d50  6aff                 push -1
// 006d3d52  6878ef8600           push 0x86ef78
// 006d3d57  64a100000000         mov eax, dword ptr fs:[0]
// 006d3d5d  50                   push eax
// 006d3d5e  64892500000000       mov dword ptr fs:[0], esp
// 006d3d65  51                   push ecx
// 006d3d66  56                   push esi
// 006d3d67  8bf1                 mov esi, ecx
// 006d3d69  6a04                 push 4
// 006d3d6b  89742408             mov dword ptr [esp + 8], esi
// 006d3d6f  e8c44c0400           call 0x718a38
// 006d3d74  83c404               add esp, 4
// 006d3d77  85c0                 test eax, eax
// 006d3d79  7404                 je 0x6d3d7f
// 006d3d7b  8930                 mov dword ptr [eax], esi
// 006d3d7d  eb02                 jmp 0x6d3d81
// 006d3d7f  33c0                 xor eax, eax
// 006d3d81  8906                 mov dword ptr [esi], eax
// 006d3d83  8bce                 mov ecx, esi
// 006d3d85  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006d3d8d  e84ef4ffff           call 0x6d31e0
// 006d3d92  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006d3d96  894618               mov dword ptr [esi + 0x18], eax
// 006d3d99  c6401d01             mov byte ptr [eax + 0x1d], 1
// 006d3d9d  8b4618               mov eax, dword ptr [esi + 0x18]
// 006d3da0  894004               mov dword ptr [eax + 4], eax
// 006d3da3  8b4618               mov eax, dword ptr [esi + 0x18]
// 006d3da6  8900                 mov dword ptr [eax], eax
// 006d3da8  8b4618               mov eax, dword ptr [esi + 0x18]
// 006d3dab  894008               mov dword ptr [eax + 8], eax
// 006d3dae  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006d3db5  8bc6                 mov eax, esi
// 006d3db7  5e                   pop esi
// 006d3db8  64890d00000000       mov dword ptr fs:[0], ecx
// 006d3dbf  83c410               add esp, 0x10
// 006d3dc2  c20800               ret 8
// standard library set<pod16> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
