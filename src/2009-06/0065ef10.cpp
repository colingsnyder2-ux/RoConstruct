// from server: 100% by auto
// roc 2009-06 0065ef10  unit: RBX::VBasicPartInstance::?$SeatImpl  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0065ef10
//
// 0065ef10  83ec08               sub esp, 8
// 0065ef13  56                   push esi
// 0065ef14  8bf1                 mov esi, ecx
// 0065ef16  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0065ef19  57                   push edi
// 0065ef1a  85c9                 test ecx, ecx
// 0065ef1c  7504                 jne 0x65ef22
// 0065ef1e  33c0                 xor eax, eax
// 0065ef20  eb08                 jmp 0x65ef2a
// 0065ef22  8b4614               mov eax, dword ptr [esi + 0x14]
// 0065ef25  2bc1                 sub eax, ecx
// 0065ef27  c1f803               sar eax, 3
// 0065ef2a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0065ef2d  8bd7                 mov edx, edi
// 0065ef2f  2bd1                 sub edx, ecx
// 0065ef31  c1fa03               sar edx, 3
// 0065ef34  3bd0                 cmp edx, eax
// 0065ef36  7331                 jae 0x65ef69
// 0065ef38  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0065ef3c  c644240800           mov byte ptr [esp + 8], 0
// 0065ef41  8b442408             mov eax, dword ptr [esp + 8]
// 0065ef45  50                   push eax
// 0065ef46  8b442418             mov eax, dword ptr [esp + 0x18]
// 0065ef4a  51                   push ecx
// 0065ef4b  8d5608               lea edx, [esi + 8]
// 0065ef4e  52                   push edx
// 0065ef4f  50                   push eax
// 0065ef50  6a01                 push 1
// 0065ef52  57                   push edi
// 0065ef53  e838eaffff           call 0x65d990
// 0065ef58  83c418               add esp, 0x18
// 0065ef5b  83c708               add edi, 8
// 0065ef5e  897e10               mov dword ptr [esi + 0x10], edi
// 0065ef61  5f                   pop edi
// 0065ef62  5e                   pop esi
// 0065ef63  83c408               add esp, 8
// 0065ef66  c20400               ret 4
// 0065ef69  3bcf                 cmp ecx, edi
// 0065ef6b  7606                 jbe 0x65ef73
// 0065ef6d  ff15ace98900         call dword ptr [0x89e9ac]
// 0065ef73  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0065ef77  8b06                 mov eax, dword ptr [esi]
// 0065ef79  51                   push ecx
// 0065ef7a  57                   push edi
// 0065ef7b  50                   push eax
// 0065ef7c  8d542414             lea edx, [esp + 0x14]
// 0065ef80  52                   push edx
// 0065ef81  8bce                 mov ecx, esi
// 0065ef83  e878fdffff           call 0x65ed00
// 0065ef88  5f                   pop edi
// 0065ef89  5e                   pop esi
// 0065ef8a  83c408               add esp, 8
// 0065ef8d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
