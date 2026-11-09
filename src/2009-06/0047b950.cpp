// from server: 100% by auto
// roc 2009-06 0047b950  unit: Ogre::VRootManager::?$sp_counted_impl_p  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047b950
//
// 0047b950  53                   push ebx
// 0047b951  55                   push ebp
// 0047b952  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 0047b958  56                   push esi
// 0047b959  57                   push edi
// 0047b95a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0047b95e  8bf1                 mov esi, ecx
// 0047b960  c70700000000         mov dword ptr [edi], 0
// 0047b966  85f6                 test esi, esi
// 0047b968  740e                 je 0x47b978
// 0047b96a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0047b96e  39460c               cmp dword ptr [esi + 0xc], eax
// 0047b971  7705                 ja 0x47b978
// 0047b973  3b4610               cmp eax, dword ptr [esi + 0x10]
// 0047b976  7606                 jbe 0x47b97e
// 0047b978  ffd5                 call ebp
// 0047b97a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0047b97e  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0047b982  8b0e                 mov ecx, dword ptr [esi]
// 0047b984  890f                 mov dword ptr [edi], ecx
// 0047b986  894704               mov dword ptr [edi + 4], eax
// 0047b989  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0047b98c  7705                 ja 0x47b993
// 0047b98e  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0047b991  7606                 jbe 0x47b999
// 0047b993  ffd5                 call ebp
// 0047b995  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0047b999  8b07                 mov eax, dword ptr [edi]
// 0047b99b  8b0e                 mov ecx, dword ptr [esi]
// 0047b99d  85c0                 test eax, eax
// 0047b99f  7404                 je 0x47b9a5
// 0047b9a1  3bc1                 cmp eax, ecx
// 0047b9a3  7402                 je 0x47b9a7
// 0047b9a5  ffd5                 call ebp
// 0047b9a7  8b4f04               mov ecx, dword ptr [edi + 4]
// 0047b9aa  3bcb                 cmp ecx, ebx
// 0047b9ac  7425                 je 0x47b9d3
// 0047b9ae  8b4610               mov eax, dword ptr [esi + 0x10]
// 0047b9b1  c644241400           mov byte ptr [esp + 0x14], 0
// 0047b9b6  8b542414             mov edx, dword ptr [esp + 0x14]
// 0047b9ba  52                   push edx
// 0047b9bb  8b542418             mov edx, dword ptr [esp + 0x18]
// 0047b9bf  52                   push edx
// 0047b9c0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0047b9c4  52                   push edx
// 0047b9c5  51                   push ecx
// 0047b9c6  50                   push eax
// 0047b9c7  53                   push ebx
// 0047b9c8  e8e3f5ffff           call 0x47afb0
// 0047b9cd  83c418               add esp, 0x18
// 0047b9d0  894610               mov dword ptr [esi + 0x10], eax
// 0047b9d3  8bc7                 mov eax, edi
// 0047b9d5  5f                   pop edi
// 0047b9d6  5e                   pop esi
// 0047b9d7  5d                   pop ebp
// 0047b9d8  5b                   pop ebx
// 0047b9d9  c21400               ret 0x14
// standard library vector<pod12> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
