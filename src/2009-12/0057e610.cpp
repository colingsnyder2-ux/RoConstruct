// from server: 100% by auto
// roc 2009-12 0057e610  unit: Ogre::RbxSceneUpdater  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057e610
//
// 0057e610  83ec10               sub esp, 0x10
// 0057e613  8b442418             mov eax, dword ptr [esp + 0x18]
// 0057e617  8b5004               mov edx, dword ptr [eax + 4]
// 0057e61a  53                   push ebx
// 0057e61b  55                   push ebp
// 0057e61c  56                   push esi
// 0057e61d  8bf1                 mov esi, ecx
// 0057e61f  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0057e622  8b08                 mov ecx, dword ptr [eax]
// 0057e624  57                   push edi
// 0057e625  894c2410             mov dword ptr [esp + 0x10], ecx
// 0057e629  89542414             mov dword ptr [esp + 0x14], edx
// 0057e62d  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0057e630  7606                 jbe 0x57e638
// 0057e632  ff1560b79800         call dword ptr [0x98b760]
// 0057e638  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0057e63b  8b2e                 mov ebp, dword ptr [esi]
// 0057e63d  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0057e640  7606                 jbe 0x57e648
// 0057e642  ff1560b79800         call dword ptr [0x98b760]
// 0057e648  8b06                 mov eax, dword ptr [esi]
// 0057e64a  53                   push ebx
// 0057e64b  55                   push ebp
// 0057e64c  57                   push edi
// 0057e64d  50                   push eax
// 0057e64e  8d442428             lea eax, [esp + 0x28]
// 0057e652  50                   push eax
// 0057e653  8bce                 mov ecx, esi
// 0057e655  e806f0ffff           call 0x57d660
// 0057e65a  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0057e65d  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0057e660  7606                 jbe 0x57e668
// 0057e662  ff1560b79800         call dword ptr [0x98b760]
// 0057e668  8b542424             mov edx, dword ptr [esp + 0x24]
// 0057e66c  8b06                 mov eax, dword ptr [esi]
// 0057e66e  8d4c2410             lea ecx, [esp + 0x10]
// 0057e672  51                   push ecx
// 0057e673  52                   push edx
// 0057e674  57                   push edi
// 0057e675  50                   push eax
// 0057e676  8bce                 mov ecx, esi
// 0057e678  e8e327f0ff           call 0x480e60
// 0057e67d  5f                   pop edi
// 0057e67e  5e                   pop esi
// 0057e67f  5d                   pop ebp
// 0057e680  5b                   pop ebx
// 0057e681  83c410               add esp, 0x10
// 0057e684  c20800               ret 8
// standard library vector<i64> (function ?_Assign_n@?$vector@_JV?$allocator@_J@std@@@std@@IAEXIAB_J@Z)

// stl: vector<i64>
typedef __int64 E;
#include <vector>
template class std::vector<E>;
