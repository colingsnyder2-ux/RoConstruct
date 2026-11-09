// from server: 100% by auto
// roc 2009-06 0043f310  unit: 1RBX::Metadata::VReflection::?$FactoryProduct  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043f310
//
// 0043f310  83ec08               sub esp, 8
// 0043f313  56                   push esi
// 0043f314  8bf1                 mov esi, ecx
// 0043f316  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0043f319  57                   push edi
// 0043f31a  85c9                 test ecx, ecx
// 0043f31c  7504                 jne 0x43f322
// 0043f31e  33c0                 xor eax, eax
// 0043f320  eb08                 jmp 0x43f32a
// 0043f322  8b4614               mov eax, dword ptr [esi + 0x14]
// 0043f325  2bc1                 sub eax, ecx
// 0043f327  c1f804               sar eax, 4
// 0043f32a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0043f32d  8bd7                 mov edx, edi
// 0043f32f  2bd1                 sub edx, ecx
// 0043f331  c1fa04               sar edx, 4
// 0043f334  3bd0                 cmp edx, eax
// 0043f336  7331                 jae 0x43f369
// 0043f338  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043f33c  c644240800           mov byte ptr [esp + 8], 0
// 0043f341  8b442408             mov eax, dword ptr [esp + 8]
// 0043f345  50                   push eax
// 0043f346  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043f34a  51                   push ecx
// 0043f34b  8d5608               lea edx, [esi + 8]
// 0043f34e  52                   push edx
// 0043f34f  50                   push eax
// 0043f350  6a01                 push 1
// 0043f352  57                   push edi
// 0043f353  e808f9ffff           call 0x43ec60
// 0043f358  83c418               add esp, 0x18
// 0043f35b  83c710               add edi, 0x10
// 0043f35e  897e10               mov dword ptr [esi + 0x10], edi
// 0043f361  5f                   pop edi
// 0043f362  5e                   pop esi
// 0043f363  83c408               add esp, 8
// 0043f366  c20400               ret 4
// 0043f369  3bcf                 cmp ecx, edi
// 0043f36b  7606                 jbe 0x43f373
// 0043f36d  ff15ace98900         call dword ptr [0x89e9ac]
// 0043f373  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043f377  8b06                 mov eax, dword ptr [esi]
// 0043f379  51                   push ecx
// 0043f37a  57                   push edi
// 0043f37b  50                   push eax
// 0043f37c  8d542414             lea edx, [esp + 0x14]
// 0043f380  52                   push edx
// 0043f381  8bce                 mov ecx, esi
// 0043f383  e8c8fcffff           call 0x43f050
// 0043f388  5f                   pop edi
// 0043f389  5e                   pop esi
// 0043f38a  83c408               add esp, 8
// 0043f38d  c20400               ret 4
// standard library vector<pod16> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
