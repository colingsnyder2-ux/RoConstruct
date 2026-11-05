// from server: 100% by auto
// roc 2009-12 004bb3b0  unit: Ogre::RbxCullableSceneNode  size: 196 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004bb3b0
//
// 004bb3b0  83ec18               sub esp, 0x18
// 004bb3b3  53                   push ebx
// 004bb3b4  55                   push ebp
// 004bb3b5  56                   push esi
// 004bb3b6  8bf1                 mov esi, ecx
// 004bb3b8  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004bb3bb  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 004bb3be  8bcb                 mov ecx, ebx
// 004bb3c0  2bcd                 sub ecx, ebp
// 004bb3c2  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004bb3c7  f7e9                 imul ecx
// 004bb3c9  d1fa                 sar edx, 1
// 004bb3cb  8bc2                 mov eax, edx
// 004bb3cd  c1e81f               shr eax, 0x1f
// 004bb3d0  57                   push edi
// 004bb3d1  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004bb3d5  03c2                 add eax, edx
// 004bb3d7  3bf8                 cmp edi, eax
// 004bb3d9  763d                 jbe 0x4bb418
// 004bb3db  3beb                 cmp ebp, ebx
// 004bb3dd  7606                 jbe 0x4bb3e5
// 004bb3df  ff1560b79800         call dword ptr [0x98b760]
// 004bb3e5  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004bb3e8  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 004bb3eb  8b2e                 mov ebp, dword ptr [esi]
// 004bb3ed  8d442430             lea eax, [esp + 0x30]
// 004bb3f1  50                   push eax
// 004bb3f2  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004bb3f7  f7e9                 imul ecx
// 004bb3f9  d1fa                 sar edx, 1
// 004bb3fb  8bca                 mov ecx, edx
// 004bb3fd  c1e91f               shr ecx, 0x1f
// 004bb400  03ca                 add ecx, edx
// 004bb402  2bf9                 sub edi, ecx
// 004bb404  57                   push edi
// 004bb405  53                   push ebx
// 004bb406  55                   push ebp
// 004bb407  8bce                 mov ecx, esi
// 004bb409  e8e269fdff           call 0x491df0
// 004bb40e  5f                   pop edi
// 004bb40f  5e                   pop esi
// 004bb410  5d                   pop ebp
// 004bb411  5b                   pop ebx
// 004bb412  83c418               add esp, 0x18
// 004bb415  c21000               ret 0x10
// 004bb418  7350                 jae 0x4bb46a
// 004bb41a  3beb                 cmp ebp, ebx
// 004bb41c  7606                 jbe 0x4bb424
// 004bb41e  ff1560b79800         call dword ptr [0x98b760]
// 004bb424  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 004bb427  8b16                 mov edx, dword ptr [esi]
// 004bb429  89542418             mov dword ptr [esp + 0x18], edx
// 004bb42d  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 004bb430  7606                 jbe 0x4bb438
// 004bb432  ff1560b79800         call dword ptr [0x98b760]
// 004bb438  8b06                 mov eax, dword ptr [esi]
// 004bb43a  57                   push edi
// 004bb43b  8d4c2424             lea ecx, [esp + 0x24]
// 004bb43f  51                   push ecx
// 004bb440  8d4c2418             lea ecx, [esp + 0x18]
// 004bb444  89442418             mov dword ptr [esp + 0x18], eax
// 004bb448  896c241c             mov dword ptr [esp + 0x1c], ebp
// 004bb44c  e8df68fdff           call 0x491d30
// 004bb451  8b542418             mov edx, dword ptr [esp + 0x18]
// 004bb455  8b4804               mov ecx, dword ptr [eax + 4]
// 004bb458  53                   push ebx
// 004bb459  52                   push edx
// 004bb45a  8b10                 mov edx, dword ptr [eax]
// 004bb45c  51                   push ecx
// 004bb45d  52                   push edx
// 004bb45e  8d442428             lea eax, [esp + 0x28]
// 004bb462  50                   push eax
// 004bb463  8bce                 mov ecx, esi
// 004bb465  e8f6fbffff           call 0x4bb060
// 004bb46a  5f                   pop edi
// 004bb46b  5e                   pop esi
// 004bb46c  5d                   pop ebp
// 004bb46d  5b                   pop ebx
// 004bb46e  83c418               add esp, 0x18
// 004bb471  c21000               ret 0x10
// standard library vector<pod12> (function ?resize@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
