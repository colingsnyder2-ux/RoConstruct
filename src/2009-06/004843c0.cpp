// from server: 100% by auto
// roc 2009-06 004843c0  unit: Ogre::RbxSpatialHashedSceneNode  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004843c0
//
// 004843c0  83ec08               sub esp, 8
// 004843c3  56                   push esi
// 004843c4  8bf1                 mov esi, ecx
// 004843c6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004843c9  57                   push edi
// 004843ca  85c9                 test ecx, ecx
// 004843cc  7504                 jne 0x4843d2
// 004843ce  33c0                 xor eax, eax
// 004843d0  eb08                 jmp 0x4843da
// 004843d2  8b4614               mov eax, dword ptr [esi + 0x14]
// 004843d5  2bc1                 sub eax, ecx
// 004843d7  c1f804               sar eax, 4
// 004843da  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004843dd  8bd7                 mov edx, edi
// 004843df  2bd1                 sub edx, ecx
// 004843e1  c1fa04               sar edx, 4
// 004843e4  3bd0                 cmp edx, eax
// 004843e6  7331                 jae 0x484419
// 004843e8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004843ec  c644240800           mov byte ptr [esp + 8], 0
// 004843f1  8b442408             mov eax, dword ptr [esp + 8]
// 004843f5  50                   push eax
// 004843f6  8b442418             mov eax, dword ptr [esp + 0x18]
// 004843fa  51                   push ecx
// 004843fb  8d5608               lea edx, [esi + 8]
// 004843fe  52                   push edx
// 004843ff  50                   push eax
// 00484400  6a01                 push 1
// 00484402  57                   push edi
// 00484403  e838110000           call 0x485540
// 00484408  83c418               add esp, 0x18
// 0048440b  83c710               add edi, 0x10
// 0048440e  897e10               mov dword ptr [esi + 0x10], edi
// 00484411  5f                   pop edi
// 00484412  5e                   pop esi
// 00484413  83c408               add esp, 8
// 00484416  c20400               ret 4
// 00484419  3bcf                 cmp ecx, edi
// 0048441b  7606                 jbe 0x484423
// 0048441d  ff15ace98900         call dword ptr [0x89e9ac]
// 00484423  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00484427  8b06                 mov eax, dword ptr [esi]
// 00484429  51                   push ecx
// 0048442a  57                   push edi
// 0048442b  50                   push eax
// 0048442c  8d542414             lea edx, [esp + 0x14]
// 00484430  52                   push edx
// 00484431  8bce                 mov ecx, esi
// 00484433  e878fbffff           call 0x483fb0
// 00484438  5f                   pop edi
// 00484439  5e                   pop esi
// 0048443a  83c408               add esp, 8
// 0048443d  c20400               ret 4
// standard library vector<pod16> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
