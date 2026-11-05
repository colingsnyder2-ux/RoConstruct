// from server: 100% by auto
// roc 2010-06 00444e40  unit: 1RBX::Metadata::VReflection::?$FactoryProduct  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00444e40
//
// 00444e40  83ec08               sub esp, 8
// 00444e43  56                   push esi
// 00444e44  8bf1                 mov esi, ecx
// 00444e46  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00444e49  57                   push edi
// 00444e4a  85c9                 test ecx, ecx
// 00444e4c  7504                 jne 0x444e52
// 00444e4e  33c0                 xor eax, eax
// 00444e50  eb08                 jmp 0x444e5a
// 00444e52  8b4614               mov eax, dword ptr [esi + 0x14]
// 00444e55  2bc1                 sub eax, ecx
// 00444e57  c1f804               sar eax, 4
// 00444e5a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00444e5d  8bd7                 mov edx, edi
// 00444e5f  2bd1                 sub edx, ecx
// 00444e61  c1fa04               sar edx, 4
// 00444e64  3bd0                 cmp edx, eax
// 00444e66  7331                 jae 0x444e99
// 00444e68  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00444e6c  c644240800           mov byte ptr [esp + 8], 0
// 00444e71  8b442408             mov eax, dword ptr [esp + 8]
// 00444e75  50                   push eax
// 00444e76  8b442418             mov eax, dword ptr [esp + 0x18]
// 00444e7a  51                   push ecx
// 00444e7b  8d5608               lea edx, [esi + 8]
// 00444e7e  52                   push edx
// 00444e7f  50                   push eax
// 00444e80  6a01                 push 1
// 00444e82  57                   push edi
// 00444e83  e808f9ffff           call 0x444790
// 00444e88  83c418               add esp, 0x18
// 00444e8b  83c710               add edi, 0x10
// 00444e8e  897e10               mov dword ptr [esi + 0x10], edi
// 00444e91  5f                   pop edi
// 00444e92  5e                   pop esi
// 00444e93  83c408               add esp, 8
// 00444e96  c20400               ret 4
// 00444e99  3bcf                 cmp ecx, edi
// 00444e9b  7606                 jbe 0x444ea3
// 00444e9d  ff150ca99e00         call dword ptr [0x9ea90c]
// 00444ea3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00444ea7  8b06                 mov eax, dword ptr [esi]
// 00444ea9  51                   push ecx
// 00444eaa  57                   push edi
// 00444eab  50                   push eax
// 00444eac  8d542414             lea edx, [esp + 0x14]
// 00444eb0  52                   push edx
// 00444eb1  8bce                 mov ecx, esi
// 00444eb3  e8c8fcffff           call 0x444b80
// 00444eb8  5f                   pop edi
// 00444eb9  5e                   pop esi
// 00444eba  83c408               add esp, 8
// 00444ebd  c20400               ret 4
// standard library vector<pod16> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
