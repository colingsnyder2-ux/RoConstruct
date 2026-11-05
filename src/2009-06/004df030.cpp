// from server: 100% by auto
// roc 2009-06 004df030  unit: RBX::Network::IdSerializer  size: 238 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004df030
//
// 004df030  55                   push ebp
// 004df031  8bec                 mov ebp, esp
// 004df033  6aff                 push -1
// 004df035  6838b98500           push 0x85b938
// 004df03a  64a100000000         mov eax, dword ptr fs:[0]
// 004df040  50                   push eax
// 004df041  64892500000000       mov dword ptr fs:[0], esp
// 004df048  83ec0c               sub esp, 0xc
// 004df04b  53                   push ebx
// 004df04c  56                   push esi
// 004df04d  57                   push edi
// 004df04e  8965f0               mov dword ptr [ebp - 0x10], esp
// 004df051  8bf1                 mov esi, ecx
// 004df053  6a04                 push 4
// 004df055  8975e8               mov dword ptr [ebp - 0x18], esi
// 004df058  e8db992300           call 0x718a38
// 004df05d  83c404               add esp, 4
// 004df060  85c0                 test eax, eax
// 004df062  7404                 je 0x4df068
// 004df064  8930                 mov dword ptr [eax], esi
// 004df066  eb02                 jmp 0x4df06a
// 004df068  33c0                 xor eax, eax
// 004df06a  8906                 mov dword ptr [esi], eax
// 004df06c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004df06f  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004df072  2b4b0c               sub ecx, dword ptr [ebx + 0xc]
// 004df075  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004df07a  f7e9                 imul ecx
// 004df07c  d1fa                 sar edx, 1
// 004df07e  8bfa                 mov edi, edx
// 004df080  b800000000           mov eax, 0
// 004df085  c1ef1f               shr edi, 0x1f
// 004df088  03fa                 add edi, edx
// 004df08a  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004df091  89460c               mov dword ptr [esi + 0xc], eax
// 004df094  894610               mov dword ptr [esi + 0x10], eax
// 004df097  894614               mov dword ptr [esi + 0x14], eax
// 004df09a  746d                 je 0x4df109
// 004df09c  81ff55555515         cmp edi, 0x15555555
// 004df0a2  7605                 jbe 0x4df0a9
// 004df0a4  e8b712fbff           call 0x490360
// 004df0a9  50                   push eax
// 004df0aa  57                   push edi
// 004df0ab  e8a0bef9ff           call 0x47af50
// 004df0b0  8d0c7f               lea ecx, [edi + edi*2]
// 004df0b3  8d1488               lea edx, [eax + ecx*4]
// 004df0b6  89460c               mov dword ptr [esi + 0xc], eax
// 004df0b9  894610               mov dword ptr [esi + 0x10], eax
// 004df0bc  895614               mov dword ptr [esi + 0x14], edx
// 004df0bf  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004df0c2  83c408               add esp, 8
// 004df0c5  c645fc01             mov byte ptr [ebp - 4], 1
// 004df0c9  8945ec               mov dword ptr [ebp - 0x14], eax
// 004df0cc  39430c               cmp dword ptr [ebx + 0xc], eax
// 004df0cf  7606                 jbe 0x4df0d7
// 004df0d1  ff15ace98900         call dword ptr [0x89e9ac]
// 004df0d7  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 004df0da  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 004df0dd  7606                 jbe 0x4df0e5
// 004df0df  ff15ace98900         call dword ptr [0x89e9ac]
// 004df0e5  8b460c               mov eax, dword ptr [esi + 0xc]
// 004df0e8  c6450800             mov byte ptr [ebp + 8], 0
// 004df0ec  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004df0ef  8b5508               mov edx, dword ptr [ebp + 8]
// 004df0f2  51                   push ecx
// 004df0f3  52                   push edx
// 004df0f4  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004df0f7  8d4e08               lea ecx, [esi + 8]
// 004df0fa  51                   push ecx
// 004df0fb  50                   push eax
// 004df0fc  52                   push edx
// 004df0fd  57                   push edi
// 004df0fe  e8fdf3ffff           call 0x4de500
// 004df103  83c418               add esp, 0x18
// 004df106  894610               mov dword ptr [esi + 0x10], eax
// 004df109  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004df10c  5f                   pop edi
// 004df10d  8bc6                 mov eax, esi
// 004df10f  5e                   pop esi
// 004df110  64890d00000000       mov dword ptr fs:[0], ecx
// 004df117  5b                   pop ebx
// 004df118  8be5                 mov esp, ebp
// 004df11a  5d                   pop ebp
// 004df11b  c20400               ret 4
// standard library vector<pod12> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
