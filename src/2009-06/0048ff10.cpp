// from server: 100% by auto
// roc 2009-06 0048ff10  unit: Ogre::TextureCompositor  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048ff10
//
// 0048ff10  83ec08               sub esp, 8
// 0048ff13  56                   push esi
// 0048ff14  8bf1                 mov esi, ecx
// 0048ff16  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0048ff19  57                   push edi
// 0048ff1a  85c9                 test ecx, ecx
// 0048ff1c  7504                 jne 0x48ff22
// 0048ff1e  33c0                 xor eax, eax
// 0048ff20  eb08                 jmp 0x48ff2a
// 0048ff22  8b4614               mov eax, dword ptr [esi + 0x14]
// 0048ff25  2bc1                 sub eax, ecx
// 0048ff27  c1f806               sar eax, 6
// 0048ff2a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0048ff2d  8bd7                 mov edx, edi
// 0048ff2f  2bd1                 sub edx, ecx
// 0048ff31  c1fa06               sar edx, 6
// 0048ff34  3bd0                 cmp edx, eax
// 0048ff36  7331                 jae 0x48ff69
// 0048ff38  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048ff3c  c644240800           mov byte ptr [esp + 8], 0
// 0048ff41  8b442408             mov eax, dword ptr [esp + 8]
// 0048ff45  50                   push eax
// 0048ff46  8b442418             mov eax, dword ptr [esp + 0x18]
// 0048ff4a  51                   push ecx
// 0048ff4b  8d5608               lea edx, [esi + 8]
// 0048ff4e  52                   push edx
// 0048ff4f  50                   push eax
// 0048ff50  6a01                 push 1
// 0048ff52  57                   push edi
// 0048ff53  e858e4ffff           call 0x48e3b0
// 0048ff58  83c418               add esp, 0x18
// 0048ff5b  83c740               add edi, 0x40
// 0048ff5e  897e10               mov dword ptr [esi + 0x10], edi
// 0048ff61  5f                   pop edi
// 0048ff62  5e                   pop esi
// 0048ff63  83c408               add esp, 8
// 0048ff66  c20400               ret 4
// 0048ff69  3bcf                 cmp ecx, edi
// 0048ff6b  7606                 jbe 0x48ff73
// 0048ff6d  ff15ace98900         call dword ptr [0x89e9ac]
// 0048ff73  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048ff77  8b06                 mov eax, dword ptr [esi]
// 0048ff79  51                   push ecx
// 0048ff7a  57                   push edi
// 0048ff7b  50                   push eax
// 0048ff7c  8d542414             lea edx, [esp + 0x14]
// 0048ff80  52                   push edx
// 0048ff81  8bce                 mov ecx, esi
// 0048ff83  e8c8fdffff           call 0x48fd50
// 0048ff88  5f                   pop edi
// 0048ff89  5e                   pop esi
// 0048ff8a  83c408               add esp, 8
// 0048ff8d  c20400               ret 4
// standard library vector<pod64> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
