// from server: 100% by auto
// roc 2008-06 0067fa80  unit: Ogre::RbxEntity  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0067fa80
//
// 0067fa80  53                   push ebx
// 0067fa81  55                   push ebp
// 0067fa82  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0067fa88  56                   push esi
// 0067fa89  57                   push edi
// 0067fa8a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0067fa8e  8bf1                 mov esi, ecx
// 0067fa90  c70700000000         mov dword ptr [edi], 0
// 0067fa96  85f6                 test esi, esi
// 0067fa98  740e                 je 0x67faa8
// 0067fa9a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0067fa9e  39460c               cmp dword ptr [esi + 0xc], eax
// 0067faa1  7705                 ja 0x67faa8
// 0067faa3  3b4610               cmp eax, dword ptr [esi + 0x10]
// 0067faa6  7606                 jbe 0x67faae
// 0067faa8  ffd5                 call ebp
// 0067faaa  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0067faae  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0067fab2  8b0e                 mov ecx, dword ptr [esi]
// 0067fab4  890f                 mov dword ptr [edi], ecx
// 0067fab6  894704               mov dword ptr [edi + 4], eax
// 0067fab9  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0067fabc  7705                 ja 0x67fac3
// 0067fabe  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0067fac1  7606                 jbe 0x67fac9
// 0067fac3  ffd5                 call ebp
// 0067fac5  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0067fac9  8b07                 mov eax, dword ptr [edi]
// 0067facb  8b0e                 mov ecx, dword ptr [esi]
// 0067facd  85c0                 test eax, eax
// 0067facf  7404                 je 0x67fad5
// 0067fad1  3bc1                 cmp eax, ecx
// 0067fad3  7402                 je 0x67fad7
// 0067fad5  ffd5                 call ebp
// 0067fad7  8b4f04               mov ecx, dword ptr [edi + 4]
// 0067fada  3bcb                 cmp ecx, ebx
// 0067fadc  7425                 je 0x67fb03
// 0067fade  8b4610               mov eax, dword ptr [esi + 0x10]
// 0067fae1  c644241400           mov byte ptr [esp + 0x14], 0
// 0067fae6  8b542414             mov edx, dword ptr [esp + 0x14]
// 0067faea  52                   push edx
// 0067faeb  8b542418             mov edx, dword ptr [esp + 0x18]
// 0067faef  52                   push edx
// 0067faf0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0067faf4  52                   push edx
// 0067faf5  51                   push ecx
// 0067faf6  50                   push eax
// 0067faf7  53                   push ebx
// 0067faf8  e873f6ffff           call 0x67f170
// 0067fafd  83c418               add esp, 0x18
// 0067fb00  894610               mov dword ptr [esi + 0x10], eax
// 0067fb03  8bc7                 mov eax, edi
// 0067fb05  5f                   pop edi
// 0067fb06  5e                   pop esi
// 0067fb07  5d                   pop ebp
// 0067fb08  5b                   pop ebx
// 0067fb09  c21400               ret 0x14
// standard library vector<pod12> (function ?erase@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@0@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
