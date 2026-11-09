// from server: 100% by auto
// roc 2009-06 005ded70  unit: RBX::VInstance::?$NonFactoryProduct  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ded70
//
// 005ded70  83ec08               sub esp, 8
// 005ded73  56                   push esi
// 005ded74  8bf1                 mov esi, ecx
// 005ded76  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005ded79  57                   push edi
// 005ded7a  85c9                 test ecx, ecx
// 005ded7c  7504                 jne 0x5ded82
// 005ded7e  33c0                 xor eax, eax
// 005ded80  eb08                 jmp 0x5ded8a
// 005ded82  8b4614               mov eax, dword ptr [esi + 0x14]
// 005ded85  2bc1                 sub eax, ecx
// 005ded87  c1f805               sar eax, 5
// 005ded8a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005ded8d  8bd7                 mov edx, edi
// 005ded8f  2bd1                 sub edx, ecx
// 005ded91  c1fa05               sar edx, 5
// 005ded94  3bd0                 cmp edx, eax
// 005ded96  7331                 jae 0x5dedc9
// 005ded98  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005ded9c  c644240800           mov byte ptr [esp + 8], 0
// 005deda1  8b442408             mov eax, dword ptr [esp + 8]
// 005deda5  50                   push eax
// 005deda6  8b442418             mov eax, dword ptr [esp + 0x18]
// 005dedaa  51                   push ecx
// 005dedab  8d5608               lea edx, [esi + 8]
// 005dedae  52                   push edx
// 005dedaf  50                   push eax
// 005dedb0  6a01                 push 1
// 005dedb2  57                   push edi
// 005dedb3  e8a8d9ffff           call 0x5dc760
// 005dedb8  83c418               add esp, 0x18
// 005dedbb  83c720               add edi, 0x20
// 005dedbe  897e10               mov dword ptr [esi + 0x10], edi
// 005dedc1  5f                   pop edi
// 005dedc2  5e                   pop esi
// 005dedc3  83c408               add esp, 8
// 005dedc6  c20400               ret 4
// 005dedc9  3bcf                 cmp ecx, edi
// 005dedcb  7606                 jbe 0x5dedd3
// 005dedcd  ff15ace98900         call dword ptr [0x89e9ac]
// 005dedd3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005dedd7  8b06                 mov eax, dword ptr [esi]
// 005dedd9  51                   push ecx
// 005dedda  57                   push edi
// 005deddb  50                   push eax
// 005deddc  8d542414             lea edx, [esp + 0x14]
// 005dede0  52                   push edx
// 005dede1  8bce                 mov ecx, esi
// 005dede3  e898f9ffff           call 0x5de780
// 005dede8  5f                   pop edi
// 005dede9  5e                   pop esi
// 005dedea  83c408               add esp, 8
// 005deded  c20400               ret 4
// standard library vector<pod32> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
