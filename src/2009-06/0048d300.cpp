// from server: 100% by auto
// roc 2009-06 0048d300  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048d300
//
// 0048d300  83ec08               sub esp, 8
// 0048d303  56                   push esi
// 0048d304  8bf1                 mov esi, ecx
// 0048d306  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0048d309  57                   push edi
// 0048d30a  85c9                 test ecx, ecx
// 0048d30c  7504                 jne 0x48d312
// 0048d30e  33c0                 xor eax, eax
// 0048d310  eb08                 jmp 0x48d31a
// 0048d312  8b4614               mov eax, dword ptr [esi + 0x14]
// 0048d315  2bc1                 sub eax, ecx
// 0048d317  c1f805               sar eax, 5
// 0048d31a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0048d31d  8bd7                 mov edx, edi
// 0048d31f  2bd1                 sub edx, ecx
// 0048d321  c1fa05               sar edx, 5
// 0048d324  3bd0                 cmp edx, eax
// 0048d326  7331                 jae 0x48d359
// 0048d328  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048d32c  c644240800           mov byte ptr [esp + 8], 0
// 0048d331  8b442408             mov eax, dword ptr [esp + 8]
// 0048d335  50                   push eax
// 0048d336  8b442418             mov eax, dword ptr [esp + 0x18]
// 0048d33a  51                   push ecx
// 0048d33b  8d5608               lea edx, [esi + 8]
// 0048d33e  52                   push edx
// 0048d33f  50                   push eax
// 0048d340  6a01                 push 1
// 0048d342  57                   push edi
// 0048d343  e8c8f2ffff           call 0x48c610
// 0048d348  83c418               add esp, 0x18
// 0048d34b  83c720               add edi, 0x20
// 0048d34e  897e10               mov dword ptr [esi + 0x10], edi
// 0048d351  5f                   pop edi
// 0048d352  5e                   pop esi
// 0048d353  83c408               add esp, 8
// 0048d356  c20400               ret 4
// 0048d359  3bcf                 cmp ecx, edi
// 0048d35b  7606                 jbe 0x48d363
// 0048d35d  ff15ace98900         call dword ptr [0x89e9ac]
// 0048d363  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048d367  8b06                 mov eax, dword ptr [esi]
// 0048d369  51                   push ecx
// 0048d36a  57                   push edi
// 0048d36b  50                   push eax
// 0048d36c  8d542414             lea edx, [esp + 0x14]
// 0048d370  52                   push edx
// 0048d371  8bce                 mov ecx, esi
// 0048d373  e8f8fbffff           call 0x48cf70
// 0048d378  5f                   pop edi
// 0048d379  5e                   pop esi
// 0048d37a  83c408               add esp, 8
// 0048d37d  c20400               ret 4
// standard library vector<pod32> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
