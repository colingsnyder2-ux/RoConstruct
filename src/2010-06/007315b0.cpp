// from server: 100% by auto
// roc 2010-06 007315b0  unit: lua_exception  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007315b0
//
// 007315b0  55                   push ebp
// 007315b1  8bec                 mov ebp, esp
// 007315b3  6aff                 push -1
// 007315b5  68988f9a00           push 0x9a8f98
// 007315ba  64a100000000         mov eax, dword ptr fs:[0]
// 007315c0  50                   push eax
// 007315c1  64892500000000       mov dword ptr fs:[0], esp
// 007315c8  83ec0c               sub esp, 0xc
// 007315cb  53                   push ebx
// 007315cc  56                   push esi
// 007315cd  57                   push edi
// 007315ce  8965f0               mov dword ptr [ebp - 0x10], esp
// 007315d1  8bf1                 mov esi, ecx
// 007315d3  6a04                 push 4
// 007315d5  8975e8               mov dword ptr [ebp - 0x18], esi
// 007315d8  e8c3630700           call 0x7a79a0
// 007315dd  83c404               add esp, 4
// 007315e0  85c0                 test eax, eax
// 007315e2  7404                 je 0x7315e8
// 007315e4  8930                 mov dword ptr [eax], esi
// 007315e6  eb02                 jmp 0x7315ea
// 007315e8  33c0                 xor eax, eax
// 007315ea  8906                 mov dword ptr [esi], eax
// 007315ec  8b5d08               mov ebx, dword ptr [ebp + 8]
// 007315ef  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 007315f2  2b4b0c               sub ecx, dword ptr [ebx + 0xc]
// 007315f5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007315fa  f7e9                 imul ecx
// 007315fc  c1fa02               sar edx, 2
// 007315ff  8bfa                 mov edi, edx
// 00731601  b800000000           mov eax, 0
// 00731606  c1ef1f               shr edi, 0x1f
// 00731609  03fa                 add edi, edx
// 0073160b  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00731612  89460c               mov dword ptr [esi + 0xc], eax
// 00731615  894610               mov dword ptr [esi + 0x10], eax
// 00731618  894614               mov dword ptr [esi + 0x14], eax
// 0073161b  746d                 je 0x73168a
// 0073161d  81ffaaaaaa0a         cmp edi, 0xaaaaaaa
// 00731623  7605                 jbe 0x73162a
// 00731625  e8c627cfff           call 0x423df0
// 0073162a  50                   push eax
// 0073162b  57                   push edi
// 0073162c  e8aff0ffff           call 0x7306e0
// 00731631  8d0c7f               lea ecx, [edi + edi*2]
// 00731634  8d14c8               lea edx, [eax + ecx*8]
// 00731637  89460c               mov dword ptr [esi + 0xc], eax
// 0073163a  894610               mov dword ptr [esi + 0x10], eax
// 0073163d  895614               mov dword ptr [esi + 0x14], edx
// 00731640  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00731643  83c408               add esp, 8
// 00731646  c645fc01             mov byte ptr [ebp - 4], 1
// 0073164a  8945ec               mov dword ptr [ebp - 0x14], eax
// 0073164d  39430c               cmp dword ptr [ebx + 0xc], eax
// 00731650  7606                 jbe 0x731658
// 00731652  ff150ca99e00         call dword ptr [0x9ea90c]
// 00731658  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 0073165b  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 0073165e  7606                 jbe 0x731666
// 00731660  ff150ca99e00         call dword ptr [0x9ea90c]
// 00731666  8b460c               mov eax, dword ptr [esi + 0xc]
// 00731669  c6450800             mov byte ptr [ebp + 8], 0
// 0073166d  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00731670  8b5508               mov edx, dword ptr [ebp + 8]
// 00731673  51                   push ecx
// 00731674  52                   push edx
// 00731675  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00731678  8d4e08               lea ecx, [esi + 8]
// 0073167b  51                   push ecx
// 0073167c  50                   push eax
// 0073167d  52                   push edx
// 0073167e  57                   push edi
// 0073167f  e8acf6ffff           call 0x730d30
// 00731684  83c418               add esp, 0x18
// 00731687  894610               mov dword ptr [esi + 0x10], eax
// 0073168a  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0073168d  5f                   pop edi
// 0073168e  8bc6                 mov eax, esi
// 00731690  5e                   pop esi
// 00731691  64890d00000000       mov dword ptr fs:[0], ecx
// 00731698  5b                   pop ebx
// 00731699  8be5                 mov esp, ebp
// 0073169b  5d                   pop ebp
// 0073169c  c20400               ret 4
// standard library vector<pod24> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
