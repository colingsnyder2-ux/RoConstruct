// from server: 100% by auto
// roc 2007-08 004fcac0  unit: RBX::Render::AggregateChunk  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004fcac0
//
// 004fcac0  55                   push ebp
// 004fcac1  8bec                 mov ebp, esp
// 004fcac3  6aff                 push -1
// 004fcac5  6830e87400           push 0x74e830
// 004fcaca  64a100000000         mov eax, dword ptr fs:[0]
// 004fcad0  50                   push eax
// 004fcad1  83ec0c               sub esp, 0xc
// 004fcad4  53                   push ebx
// 004fcad5  56                   push esi
// 004fcad6  57                   push edi
// 004fcad7  a188518b00           mov eax, dword ptr [0x8b5188]
// 004fcadc  33c5                 xor eax, ebp
// 004fcade  50                   push eax
// 004fcadf  8d45f4               lea eax, [ebp - 0xc]
// 004fcae2  64a300000000         mov dword ptr fs:[0], eax
// 004fcae8  8965f0               mov dword ptr [ebp - 0x10], esp
// 004fcaeb  8bf1                 mov esi, ecx
// 004fcaed  8975e8               mov dword ptr [ebp - 0x18], esi
// 004fcaf0  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004fcaf3  33c0                 xor eax, eax
// 004fcaf5  3bd8                 cmp ebx, eax
// 004fcaf7  894604               mov dword ptr [esi + 4], eax
// 004fcafa  894608               mov dword ptr [esi + 8], eax
// 004fcafd  89460c               mov dword ptr [esi + 0xc], eax
// 004fcb00  744f                 je 0x4fcb51
// 004fcb02  81fbffffff07         cmp ebx, 0x7ffffff
// 004fcb08  7605                 jbe 0x4fcb0f
// 004fcb0a  e8f1acf1ff           call 0x417800
// 004fcb0f  50                   push eax
// 004fcb10  53                   push ebx
// 004fcb11  e88af7ffff           call 0x4fc2a0
// 004fcb16  8b5508               mov edx, dword ptr [ebp + 8]
// 004fcb19  8bf8                 mov edi, eax
// 004fcb1b  c645ec00             mov byte ptr [ebp - 0x14], 0
// 004fcb1f  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 004fcb22  51                   push ecx
// 004fcb23  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004fcb26  52                   push edx
// 004fcb27  c1e305               shl ebx, 5
// 004fcb2a  8d043b               lea eax, [ebx + edi]
// 004fcb2d  89460c               mov dword ptr [esi + 0xc], eax
// 004fcb30  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004fcb33  56                   push esi
// 004fcb34  50                   push eax
// 004fcb35  51                   push ecx
// 004fcb36  57                   push edi
// 004fcb37  897e04               mov dword ptr [esi + 4], edi
// 004fcb3a  897e08               mov dword ptr [esi + 8], edi
// 004fcb3d  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004fcb44  e8e7feffff           call 0x4fca30
// 004fcb49  83c420               add esp, 0x20
// 004fcb4c  03df                 add ebx, edi
// 004fcb4e  895e08               mov dword ptr [esi + 8], ebx
// 004fcb51  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004fcb54  64890d00000000       mov dword ptr fs:[0], ecx
// 004fcb5b  59                   pop ecx
// 004fcb5c  5f                   pop edi
// 004fcb5d  5e                   pop esi
// 004fcb5e  5b                   pop ebx
// 004fcb5f  8be5                 mov esp, ebp
// 004fcb61  5d                   pop ebp
// 004fcb62  c20800               ret 8
// standard library vector<pod32> (function ?_Construct_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIABUE@@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
