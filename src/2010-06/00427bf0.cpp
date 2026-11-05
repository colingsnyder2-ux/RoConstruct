// from server: 100% by auto
// roc 2010-06 00427bf0  unit: std::D::DU?$char_traits::V?$basic_string::?$holder  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00427bf0
//
// 00427bf0  83ec08               sub esp, 8
// 00427bf3  56                   push esi
// 00427bf4  8bf1                 mov esi, ecx
// 00427bf6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00427bf9  57                   push edi
// 00427bfa  85c9                 test ecx, ecx
// 00427bfc  7504                 jne 0x427c02
// 00427bfe  33c0                 xor eax, eax
// 00427c00  eb08                 jmp 0x427c0a
// 00427c02  8b4614               mov eax, dword ptr [esi + 0x14]
// 00427c05  2bc1                 sub eax, ecx
// 00427c07  c1f803               sar eax, 3
// 00427c0a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00427c0d  8bd7                 mov edx, edi
// 00427c0f  2bd1                 sub edx, ecx
// 00427c11  c1fa03               sar edx, 3
// 00427c14  3bd0                 cmp edx, eax
// 00427c16  7331                 jae 0x427c49
// 00427c18  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00427c1c  c644240800           mov byte ptr [esp + 8], 0
// 00427c21  8b442408             mov eax, dword ptr [esp + 8]
// 00427c25  50                   push eax
// 00427c26  8b442418             mov eax, dword ptr [esp + 0x18]
// 00427c2a  51                   push ecx
// 00427c2b  8d5608               lea edx, [esi + 8]
// 00427c2e  52                   push edx
// 00427c2f  50                   push eax
// 00427c30  6a01                 push 1
// 00427c32  57                   push edi
// 00427c33  e818f8ffff           call 0x427450
// 00427c38  83c418               add esp, 0x18
// 00427c3b  83c708               add edi, 8
// 00427c3e  897e10               mov dword ptr [esi + 0x10], edi
// 00427c41  5f                   pop edi
// 00427c42  5e                   pop esi
// 00427c43  83c408               add esp, 8
// 00427c46  c20400               ret 4
// 00427c49  3bcf                 cmp ecx, edi
// 00427c4b  7606                 jbe 0x427c53
// 00427c4d  ff150ca99e00         call dword ptr [0x9ea90c]
// 00427c53  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00427c57  8b06                 mov eax, dword ptr [esi]
// 00427c59  51                   push ecx
// 00427c5a  57                   push edi
// 00427c5b  50                   push eax
// 00427c5c  8d542414             lea edx, [esp + 0x14]
// 00427c60  52                   push edx
// 00427c61  8bce                 mov ecx, esi
// 00427c63  e8c8feffff           call 0x427b30
// 00427c68  5f                   pop edi
// 00427c69  5e                   pop esi
// 00427c6a  83c408               add esp, 8
// 00427c6d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
