// from server: 100% by auto
// roc 2010-06 00976be0  unit: RBX::RightAngleRampBuilder  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00976be0
//
// 00976be0  83ec08               sub esp, 8
// 00976be3  56                   push esi
// 00976be4  8bf1                 mov esi, ecx
// 00976be6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00976be9  57                   push edi
// 00976bea  85c9                 test ecx, ecx
// 00976bec  7504                 jne 0x976bf2
// 00976bee  33c0                 xor eax, eax
// 00976bf0  eb08                 jmp 0x976bfa
// 00976bf2  8b4614               mov eax, dword ptr [esi + 0x14]
// 00976bf5  2bc1                 sub eax, ecx
// 00976bf7  c1f804               sar eax, 4
// 00976bfa  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00976bfd  8bd7                 mov edx, edi
// 00976bff  2bd1                 sub edx, ecx
// 00976c01  c1fa04               sar edx, 4
// 00976c04  3bd0                 cmp edx, eax
// 00976c06  7331                 jae 0x976c39
// 00976c08  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00976c0c  c644240800           mov byte ptr [esp + 8], 0
// 00976c11  8b442408             mov eax, dword ptr [esp + 8]
// 00976c15  50                   push eax
// 00976c16  8b442418             mov eax, dword ptr [esp + 0x18]
// 00976c1a  51                   push ecx
// 00976c1b  8d5608               lea edx, [esi + 8]
// 00976c1e  52                   push edx
// 00976c1f  50                   push eax
// 00976c20  6a01                 push 1
// 00976c22  57                   push edi
// 00976c23  e838edffff           call 0x975960
// 00976c28  83c418               add esp, 0x18
// 00976c2b  83c710               add edi, 0x10
// 00976c2e  897e10               mov dword ptr [esi + 0x10], edi
// 00976c31  5f                   pop edi
// 00976c32  5e                   pop esi
// 00976c33  83c408               add esp, 8
// 00976c36  c20400               ret 4
// 00976c39  3bcf                 cmp ecx, edi
// 00976c3b  7606                 jbe 0x976c43
// 00976c3d  ff150ca99e00         call dword ptr [0x9ea90c]
// 00976c43  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00976c47  8b06                 mov eax, dword ptr [esi]
// 00976c49  51                   push ecx
// 00976c4a  57                   push edi
// 00976c4b  50                   push eax
// 00976c4c  8d542414             lea edx, [esp + 0x14]
// 00976c50  52                   push edx
// 00976c51  8bce                 mov ecx, esi
// 00976c53  e818f2ffff           call 0x975e70
// 00976c58  5f                   pop edi
// 00976c59  5e                   pop esi
// 00976c5a  83c408               add esp, 8
// 00976c5d  c20400               ret 4
// standard library vector<pod16> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
