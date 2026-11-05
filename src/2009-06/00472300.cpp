// from server: 100% by auto
// roc 2009-06 00472300  unit: RBX::LDraw2Lua::LDraw2RobloxPartMap  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00472300
//
// 00472300  83ec08               sub esp, 8
// 00472303  56                   push esi
// 00472304  8bf1                 mov esi, ecx
// 00472306  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00472309  57                   push edi
// 0047230a  85c9                 test ecx, ecx
// 0047230c  7504                 jne 0x472312
// 0047230e  33c0                 xor eax, eax
// 00472310  eb08                 jmp 0x47231a
// 00472312  8b4614               mov eax, dword ptr [esi + 0x14]
// 00472315  2bc1                 sub eax, ecx
// 00472317  c1f806               sar eax, 6
// 0047231a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0047231d  8bd7                 mov edx, edi
// 0047231f  2bd1                 sub edx, ecx
// 00472321  c1fa06               sar edx, 6
// 00472324  3bd0                 cmp edx, eax
// 00472326  7331                 jae 0x472359
// 00472328  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0047232c  c644240800           mov byte ptr [esp + 8], 0
// 00472331  8b442408             mov eax, dword ptr [esp + 8]
// 00472335  50                   push eax
// 00472336  8b442418             mov eax, dword ptr [esp + 0x18]
// 0047233a  51                   push ecx
// 0047233b  8d5608               lea edx, [esi + 8]
// 0047233e  52                   push edx
// 0047233f  50                   push eax
// 00472340  6a01                 push 1
// 00472342  57                   push edi
// 00472343  e808f8ffff           call 0x471b50
// 00472348  83c418               add esp, 0x18
// 0047234b  83c740               add edi, 0x40
// 0047234e  897e10               mov dword ptr [esi + 0x10], edi
// 00472351  5f                   pop edi
// 00472352  5e                   pop esi
// 00472353  83c408               add esp, 8
// 00472356  c20400               ret 4
// 00472359  3bcf                 cmp ecx, edi
// 0047235b  7606                 jbe 0x472363
// 0047235d  ff15ace98900         call dword ptr [0x89e9ac]
// 00472363  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00472367  8b06                 mov eax, dword ptr [esi]
// 00472369  51                   push ecx
// 0047236a  57                   push edi
// 0047236b  50                   push eax
// 0047236c  8d542414             lea edx, [esp + 0x14]
// 00472370  52                   push edx
// 00472371  8bce                 mov ecx, esi
// 00472373  e8a8feffff           call 0x472220
// 00472378  5f                   pop edi
// 00472379  5e                   pop esi
// 0047237a  83c408               add esp, 8
// 0047237d  c20400               ret 4
// standard library vector<pod64> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
