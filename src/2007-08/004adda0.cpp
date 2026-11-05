// from server: 100% by auto
// roc 2007-08 004adda0  unit: RBX::Network::Replicator::DeleteInstanceItem  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004adda0
//
// 004adda0  83ec08               sub esp, 8
// 004adda3  56                   push esi
// 004adda4  8bf1                 mov esi, ecx
// 004adda6  8b5604               mov edx, dword ptr [esi + 4]
// 004adda9  85d2                 test edx, edx
// 004addab  57                   push edi
// 004addac  7504                 jne 0x4addb2
// 004addae  33c9                 xor ecx, ecx
// 004addb0  eb08                 jmp 0x4addba
// 004addb2  8b4e08               mov ecx, dword ptr [esi + 8]
// 004addb5  2bca                 sub ecx, edx
// 004addb7  c1f904               sar ecx, 4
// 004addba  85d2                 test edx, edx
// 004addbc  743d                 je 0x4addfb
// 004addbe  8b460c               mov eax, dword ptr [esi + 0xc]
// 004addc1  2bc2                 sub eax, edx
// 004addc3  c1f804               sar eax, 4
// 004addc6  3bc8                 cmp ecx, eax
// 004addc8  7331                 jae 0x4addfb
// 004addca  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004addce  8b542414             mov edx, dword ptr [esp + 0x14]
// 004addd2  8b7e08               mov edi, dword ptr [esi + 8]
// 004addd5  c644240800           mov byte ptr [esp + 8], 0
// 004addda  8b442408             mov eax, dword ptr [esp + 8]
// 004addde  50                   push eax
// 004adddf  51                   push ecx
// 004adde0  56                   push esi
// 004adde1  52                   push edx
// 004adde2  6a01                 push 1
// 004adde4  57                   push edi
// 004adde5  e876b1ffff           call 0x4a8f60
// 004addea  83c418               add esp, 0x18
// 004added  83c710               add edi, 0x10
// 004addf0  897e08               mov dword ptr [esi + 8], edi
// 004addf3  5f                   pop edi
// 004addf4  5e                   pop esi
// 004addf5  83c408               add esp, 8
// 004addf8  c20400               ret 4
// 004addfb  8b7e08               mov edi, dword ptr [esi + 8]
// 004addfe  3bd7                 cmp edx, edi
// 004ade00  7606                 jbe 0x4ade08
// 004ade02  ff15d8e67700         call dword ptr [0x77e6d8]
// 004ade08  8b442414             mov eax, dword ptr [esp + 0x14]
// 004ade0c  50                   push eax
// 004ade0d  57                   push edi
// 004ade0e  56                   push esi
// 004ade0f  8d4c2414             lea ecx, [esp + 0x14]
// 004ade13  51                   push ecx
// 004ade14  8bce                 mov ecx, esi
// 004ade16  e805faffff           call 0x4ad820
// 004ade1b  5f                   pop edi
// 004ade1c  5e                   pop esi
// 004ade1d  83c408               add esp, 8
// 004ade20  c20400               ret 4
// standard library vector<pod16> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
