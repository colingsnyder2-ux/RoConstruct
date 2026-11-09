// from server: 100% by auto
// roc 2007-08 00576b70  unit: RBX::PartInstance  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00576b70
//
// 00576b70  83ec08               sub esp, 8
// 00576b73  56                   push esi
// 00576b74  8bf1                 mov esi, ecx
// 00576b76  8b5604               mov edx, dword ptr [esi + 4]
// 00576b79  85d2                 test edx, edx
// 00576b7b  57                   push edi
// 00576b7c  7504                 jne 0x576b82
// 00576b7e  33c9                 xor ecx, ecx
// 00576b80  eb08                 jmp 0x576b8a
// 00576b82  8b4e08               mov ecx, dword ptr [esi + 8]
// 00576b85  2bca                 sub ecx, edx
// 00576b87  c1f903               sar ecx, 3
// 00576b8a  85d2                 test edx, edx
// 00576b8c  743d                 je 0x576bcb
// 00576b8e  8b460c               mov eax, dword ptr [esi + 0xc]
// 00576b91  2bc2                 sub eax, edx
// 00576b93  c1f803               sar eax, 3
// 00576b96  3bc8                 cmp ecx, eax
// 00576b98  7331                 jae 0x576bcb
// 00576b9a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00576b9e  8b542414             mov edx, dword ptr [esp + 0x14]
// 00576ba2  8b7e08               mov edi, dword ptr [esi + 8]
// 00576ba5  c644240800           mov byte ptr [esp + 8], 0
// 00576baa  8b442408             mov eax, dword ptr [esp + 8]
// 00576bae  50                   push eax
// 00576baf  51                   push ecx
// 00576bb0  56                   push esi
// 00576bb1  52                   push edx
// 00576bb2  6a01                 push 1
// 00576bb4  57                   push edi
// 00576bb5  e806f6ffff           call 0x5761c0
// 00576bba  83c418               add esp, 0x18
// 00576bbd  83c708               add edi, 8
// 00576bc0  897e08               mov dword ptr [esi + 8], edi
// 00576bc3  5f                   pop edi
// 00576bc4  5e                   pop esi
// 00576bc5  83c408               add esp, 8
// 00576bc8  c20400               ret 4
// 00576bcb  8b7e08               mov edi, dword ptr [esi + 8]
// 00576bce  3bd7                 cmp edx, edi
// 00576bd0  7606                 jbe 0x576bd8
// 00576bd2  ff15d8e67700         call dword ptr [0x77e6d8]
// 00576bd8  8b442414             mov eax, dword ptr [esp + 0x14]
// 00576bdc  50                   push eax
// 00576bdd  57                   push edi
// 00576bde  56                   push esi
// 00576bdf  8d4c2414             lea ecx, [esp + 0x14]
// 00576be3  51                   push ecx
// 00576be4  8bce                 mov ecx, esi
// 00576be6  e8e5feffff           call 0x576ad0
// 00576beb  5f                   pop edi
// 00576bec  5e                   pop esi
// 00576bed  83c408               add esp, 8
// 00576bf0  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
