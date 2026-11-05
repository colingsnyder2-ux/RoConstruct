// from server: 100% by auto
// roc 2010-06 00658930  unit: RBX::VKeyframeSequence::?$FactoryProduct  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00658930
//
// 00658930  83ec08               sub esp, 8
// 00658933  56                   push esi
// 00658934  8bf1                 mov esi, ecx
// 00658936  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00658939  57                   push edi
// 0065893a  85c9                 test ecx, ecx
// 0065893c  7504                 jne 0x658942
// 0065893e  33c0                 xor eax, eax
// 00658940  eb08                 jmp 0x65894a
// 00658942  8b4614               mov eax, dword ptr [esi + 0x14]
// 00658945  2bc1                 sub eax, ecx
// 00658947  c1f803               sar eax, 3
// 0065894a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0065894d  8bd7                 mov edx, edi
// 0065894f  2bd1                 sub edx, ecx
// 00658951  c1fa03               sar edx, 3
// 00658954  3bd0                 cmp edx, eax
// 00658956  7331                 jae 0x658989
// 00658958  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0065895c  c644240800           mov byte ptr [esp + 8], 0
// 00658961  8b442408             mov eax, dword ptr [esp + 8]
// 00658965  50                   push eax
// 00658966  8b442418             mov eax, dword ptr [esp + 0x18]
// 0065896a  51                   push ecx
// 0065896b  8d5608               lea edx, [esi + 8]
// 0065896e  52                   push edx
// 0065896f  50                   push eax
// 00658970  6a01                 push 1
// 00658972  57                   push edi
// 00658973  e878edffff           call 0x6576f0
// 00658978  83c418               add esp, 0x18
// 0065897b  83c708               add edi, 8
// 0065897e  897e10               mov dword ptr [esi + 0x10], edi
// 00658981  5f                   pop edi
// 00658982  5e                   pop esi
// 00658983  83c408               add esp, 8
// 00658986  c20400               ret 4
// 00658989  3bcf                 cmp ecx, edi
// 0065898b  7606                 jbe 0x658993
// 0065898d  ff150ca99e00         call dword ptr [0x9ea90c]
// 00658993  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00658997  8b06                 mov eax, dword ptr [esi]
// 00658999  51                   push ecx
// 0065899a  57                   push edi
// 0065899b  50                   push eax
// 0065899c  8d542414             lea edx, [esp + 0x14]
// 006589a0  52                   push edx
// 006589a1  8bce                 mov ecx, esi
// 006589a3  e888faffff           call 0x658430
// 006589a8  5f                   pop edi
// 006589a9  5e                   pop esi
// 006589aa  83c408               add esp, 8
// 006589ad  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
