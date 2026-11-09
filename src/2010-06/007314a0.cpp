// from server: 100% by auto
// roc 2010-06 007314a0  unit: lua_exception  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007314a0
//
// 007314a0  55                   push ebp
// 007314a1  8bec                 mov ebp, esp
// 007314a3  6aff                 push -1
// 007314a5  68788f9a00           push 0x9a8f78
// 007314aa  64a100000000         mov eax, dword ptr fs:[0]
// 007314b0  50                   push eax
// 007314b1  64892500000000       mov dword ptr fs:[0], esp
// 007314b8  83ec0c               sub esp, 0xc
// 007314bb  53                   push ebx
// 007314bc  56                   push esi
// 007314bd  57                   push edi
// 007314be  8965f0               mov dword ptr [ebp - 0x10], esp
// 007314c1  8bf1                 mov esi, ecx
// 007314c3  6a04                 push 4
// 007314c5  8975e8               mov dword ptr [ebp - 0x18], esi
// 007314c8  e8d3640700           call 0x7a79a0
// 007314cd  83c404               add esp, 4
// 007314d0  85c0                 test eax, eax
// 007314d2  7404                 je 0x7314d8
// 007314d4  8930                 mov dword ptr [eax], esi
// 007314d6  eb02                 jmp 0x7314da
// 007314d8  33c0                 xor eax, eax
// 007314da  8906                 mov dword ptr [esi], eax
// 007314dc  8b5d08               mov ebx, dword ptr [ebp + 8]
// 007314df  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 007314e2  2b4b0c               sub ecx, dword ptr [ebx + 0xc]
// 007314e5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007314ea  f7e9                 imul ecx
// 007314ec  c1fa02               sar edx, 2
// 007314ef  8bfa                 mov edi, edx
// 007314f1  b800000000           mov eax, 0
// 007314f6  c1ef1f               shr edi, 0x1f
// 007314f9  03fa                 add edi, edx
// 007314fb  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00731502  89460c               mov dword ptr [esi + 0xc], eax
// 00731505  894610               mov dword ptr [esi + 0x10], eax
// 00731508  894614               mov dword ptr [esi + 0x14], eax
// 0073150b  746d                 je 0x73157a
// 0073150d  81ffaaaaaa0a         cmp edi, 0xaaaaaaa
// 00731513  7605                 jbe 0x73151a
// 00731515  e8d628cfff           call 0x423df0
// 0073151a  50                   push eax
// 0073151b  57                   push edi
// 0073151c  e8bff1ffff           call 0x7306e0
// 00731521  8d0c7f               lea ecx, [edi + edi*2]
// 00731524  8d14c8               lea edx, [eax + ecx*8]
// 00731527  89460c               mov dword ptr [esi + 0xc], eax
// 0073152a  894610               mov dword ptr [esi + 0x10], eax
// 0073152d  895614               mov dword ptr [esi + 0x14], edx
// 00731530  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00731533  83c408               add esp, 8
// 00731536  c645fc01             mov byte ptr [ebp - 4], 1
// 0073153a  8945ec               mov dword ptr [ebp - 0x14], eax
// 0073153d  39430c               cmp dword ptr [ebx + 0xc], eax
// 00731540  7606                 jbe 0x731548
// 00731542  ff150ca99e00         call dword ptr [0x9ea90c]
// 00731548  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 0073154b  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 0073154e  7606                 jbe 0x731556
// 00731550  ff150ca99e00         call dword ptr [0x9ea90c]
// 00731556  8b460c               mov eax, dword ptr [esi + 0xc]
// 00731559  c6450800             mov byte ptr [ebp + 8], 0
// 0073155d  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00731560  8b5508               mov edx, dword ptr [ebp + 8]
// 00731563  51                   push ecx
// 00731564  52                   push edx
// 00731565  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00731568  8d4e08               lea ecx, [esi + 8]
// 0073156b  51                   push ecx
// 0073156c  50                   push eax
// 0073156d  52                   push edx
// 0073156e  57                   push edi
// 0073156f  e80cf9ffff           call 0x730e80
// 00731574  83c418               add esp, 0x18
// 00731577  894610               mov dword ptr [esi + 0x10], eax
// 0073157a  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0073157d  5f                   pop edi
// 0073157e  8bc6                 mov eax, esi
// 00731580  5e                   pop esi
// 00731581  64890d00000000       mov dword ptr fs:[0], ecx
// 00731588  5b                   pop ebx
// 00731589  8be5                 mov esp, ebp
// 0073158b  5d                   pop ebp
// 0073158c  c20400               ret 4
// standard library vector<pod24> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
