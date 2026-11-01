// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 004a8010  unit: RBX::VHint::?$FactoryProduct::Creator  size: 238 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a8010
//
// 004a8010  55                   push ebp
// 004a8011  8bec                 mov ebp, esp
// 004a8013  6aff                 push -1
// 004a8015  68787f7c00           push 0x7c7f78
// 004a801a  64a100000000         mov eax, dword ptr fs:[0]
// 004a8020  50                   push eax
// 004a8021  64892500000000       mov dword ptr fs:[0], esp
// 004a8028  83ec0c               sub esp, 0xc
// 004a802b  53                   push ebx
// 004a802c  56                   push esi
// 004a802d  57                   push edi
// 004a802e  8965f0               mov dword ptr [ebp - 0x10], esp
// 004a8031  8bf1                 mov esi, ecx
// 004a8033  6a04                 push 4
// 004a8035  8975e8               mov dword ptr [ebp - 0x18], esi
// 004a8038  e8e3881f00           call 0x6a0920
// 004a803d  83c404               add esp, 4
// 004a8040  85c0                 test eax, eax
// 004a8042  7404                 je 0x4a8048
// 004a8044  8930                 mov dword ptr [eax], esi
// 004a8046  eb02                 jmp 0x4a804a
// 004a8048  33c0                 xor eax, eax
// 004a804a  8906                 mov dword ptr [esi], eax
// 004a804c  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004a804f  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 004a8052  2b4b0c               sub ecx, dword ptr [ebx + 0xc]
// 004a8055  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004a805a  f7e9                 imul ecx
// 004a805c  d1fa                 sar edx, 1
// 004a805e  8bfa                 mov edi, edx
// 004a8060  b800000000           mov eax, 0
// 004a8065  c1ef1f               shr edi, 0x1f
// 004a8068  03fa                 add edi, edx
// 004a806a  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004a8071  89460c               mov dword ptr [esi + 0xc], eax
// 004a8074  894610               mov dword ptr [esi + 0x10], eax
// 004a8077  894614               mov dword ptr [esi + 0x14], eax
// 004a807a  746d                 je 0x4a80e9
// 004a807c  81ff55555515         cmp edi, 0x15555555
// 004a8082  7605                 jbe 0x4a8089
// 004a8084  e8b7ec0100           call 0x4c6d40
// 004a8089  50                   push eax
// 004a808a  57                   push edi
// 004a808b  e820541e00           call 0x68d4b0
// 004a8090  8d0c7f               lea ecx, [edi + edi*2]
// 004a8093  8d1488               lea edx, [eax + ecx*4]
// 004a8096  89460c               mov dword ptr [esi + 0xc], eax
// 004a8099  894610               mov dword ptr [esi + 0x10], eax
// 004a809c  895614               mov dword ptr [esi + 0x14], edx
// 004a809f  8b4310               mov eax, dword ptr [ebx + 0x10]
// 004a80a2  83c408               add esp, 8
// 004a80a5  c645fc01             mov byte ptr [ebp - 4], 1
// 004a80a9  8945ec               mov dword ptr [ebp - 0x14], eax
// 004a80ac  39430c               cmp dword ptr [ebx + 0xc], eax
// 004a80af  7606                 jbe 0x4a80b7
// 004a80b1  ff1590288000         call dword ptr [0x802890]
// 004a80b7  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 004a80ba  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 004a80bd  7606                 jbe 0x4a80c5
// 004a80bf  ff1590288000         call dword ptr [0x802890]
// 004a80c5  8b460c               mov eax, dword ptr [esi + 0xc]
// 004a80c8  c6450800             mov byte ptr [ebp + 8], 0
// 004a80cc  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004a80cf  8b5508               mov edx, dword ptr [ebp + 8]
// 004a80d2  51                   push ecx
// 004a80d3  52                   push edx
// 004a80d4  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004a80d7  8d4e08               lea ecx, [esi + 8]
// 004a80da  51                   push ecx
// 004a80db  50                   push eax
// 004a80dc  52                   push edx
// 004a80dd  57                   push edi
// 004a80de  e83df4ffff           call 0x4a7520
// 004a80e3  83c418               add esp, 0x18
// 004a80e6  894610               mov dword ptr [esi + 0x10], eax
// 004a80e9  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004a80ec  5f                   pop edi
// 004a80ed  8bc6                 mov eax, esi
// 004a80ef  5e                   pop esi
// 004a80f0  64890d00000000       mov dword ptr fs:[0], ecx
// 004a80f7  5b                   pop ebx
// 004a80f8  8be5                 mov esp, ebp
// 004a80fa  5d                   pop ebp
// 004a80fb  c20400               ret 4
// standard library vector<pod12> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
