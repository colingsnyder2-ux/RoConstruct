// from server: 100% by auto
// roc 2009-12 00535880  unit: RBX::Network::IdSerializer  size: 238 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00535880
//
// 00535880  55                   push ebp
// 00535881  8bec                 mov ebp, esp
// 00535883  6aff                 push -1
// 00535885  6858969300           push 0x939658
// 0053588a  64a100000000         mov eax, dword ptr fs:[0]
// 00535890  50                   push eax
// 00535891  64892500000000       mov dword ptr fs:[0], esp
// 00535898  83ec0c               sub esp, 0xc
// 0053589b  53                   push ebx
// 0053589c  56                   push esi
// 0053589d  57                   push edi
// 0053589e  8965f0               mov dword ptr [ebp - 0x10], esp
// 005358a1  8bf1                 mov esi, ecx
// 005358a3  6a04                 push 4
// 005358a5  8975e8               mov dword ptr [ebp - 0x18], esi
// 005358a8  e8b3df2b00           call 0x7f3860
// 005358ad  83c404               add esp, 4
// 005358b0  85c0                 test eax, eax
// 005358b2  7404                 je 0x5358b8
// 005358b4  8930                 mov dword ptr [eax], esi
// 005358b6  eb02                 jmp 0x5358ba
// 005358b8  33c0                 xor eax, eax
// 005358ba  8906                 mov dword ptr [esi], eax
// 005358bc  8b5d08               mov ebx, dword ptr [ebp + 8]
// 005358bf  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 005358c2  2b4b0c               sub ecx, dword ptr [ebx + 0xc]
// 005358c5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005358ca  f7e9                 imul ecx
// 005358cc  d1fa                 sar edx, 1
// 005358ce  8bfa                 mov edi, edx
// 005358d0  b800000000           mov eax, 0
// 005358d5  c1ef1f               shr edi, 0x1f
// 005358d8  03fa                 add edi, edx
// 005358da  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005358e1  89460c               mov dword ptr [esi + 0xc], eax
// 005358e4  894610               mov dword ptr [esi + 0x10], eax
// 005358e7  894614               mov dword ptr [esi + 0x14], eax
// 005358ea  746d                 je 0x535959
// 005358ec  81ff55555515         cmp edi, 0x15555555
// 005358f2  7605                 jbe 0x5358f9
// 005358f4  e867c8f0ff           call 0x442160
// 005358f9  50                   push eax
// 005358fa  57                   push edi
// 005358fb  e850e1f1ff           call 0x453a50
// 00535900  8d0c7f               lea ecx, [edi + edi*2]
// 00535903  8d1488               lea edx, [eax + ecx*4]
// 00535906  89460c               mov dword ptr [esi + 0xc], eax
// 00535909  894610               mov dword ptr [esi + 0x10], eax
// 0053590c  895614               mov dword ptr [esi + 0x14], edx
// 0053590f  8b4310               mov eax, dword ptr [ebx + 0x10]
// 00535912  83c408               add esp, 8
// 00535915  c645fc01             mov byte ptr [ebp - 4], 1
// 00535919  8945ec               mov dword ptr [ebp - 0x14], eax
// 0053591c  39430c               cmp dword ptr [ebx + 0xc], eax
// 0053591f  7606                 jbe 0x535927
// 00535921  ff1560b79800         call dword ptr [0x98b760]
// 00535927  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 0053592a  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 0053592d  7606                 jbe 0x535935
// 0053592f  ff1560b79800         call dword ptr [0x98b760]
// 00535935  8b460c               mov eax, dword ptr [esi + 0xc]
// 00535938  c6450800             mov byte ptr [ebp + 8], 0
// 0053593c  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0053593f  8b5508               mov edx, dword ptr [ebp + 8]
// 00535942  51                   push ecx
// 00535943  52                   push edx
// 00535944  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00535947  8d4e08               lea ecx, [esi + 8]
// 0053594a  51                   push ecx
// 0053594b  50                   push eax
// 0053594c  52                   push edx
// 0053594d  57                   push edi
// 0053594e  e8adefffff           call 0x534900
// 00535953  83c418               add esp, 0x18
// 00535956  894610               mov dword ptr [esi + 0x10], eax
// 00535959  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0053595c  5f                   pop edi
// 0053595d  8bc6                 mov eax, esi
// 0053595f  5e                   pop esi
// 00535960  64890d00000000       mov dword ptr fs:[0], ecx
// 00535967  5b                   pop ebx
// 00535968  8be5                 mov esp, ebp
// 0053596a  5d                   pop ebp
// 0053596b  c20400               ret 4
// standard library vector<pod12> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
