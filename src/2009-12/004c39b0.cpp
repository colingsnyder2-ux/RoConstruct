// from server: 100% by auto
// roc 2009-12 004c39b0  unit: Ogre::RbxCluster::VRbxPartBinding::?$sp_counted_impl_p  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c39b0
//
// 004c39b0  56                   push esi
// 004c39b1  8bf1                 mov esi, ecx
// 004c39b3  8b4628               mov eax, dword ptr [esi + 0x28]
// 004c39b6  57                   push edi
// 004c39b7  33ff                 xor edi, edi
// 004c39b9  3bc7                 cmp eax, edi
// 004c39bb  7409                 je 0x4c39c6
// 004c39bd  50                   push eax
// 004c39be  e897fe3200           call 0x7f385a
// 004c39c3  83c404               add esp, 4
// 004c39c6  8b461c               mov eax, dword ptr [esi + 0x1c]
// 004c39c9  50                   push eax
// 004c39ca  897e28               mov dword ptr [esi + 0x28], edi
// 004c39cd  897e2c               mov dword ptr [esi + 0x2c], edi
// 004c39d0  897e30               mov dword ptr [esi + 0x30], edi
// 004c39d3  e882fe3200           call 0x7f385a
// 004c39d8  8b4610               mov eax, dword ptr [esi + 0x10]
// 004c39db  83c404               add esp, 4
// 004c39de  3bc7                 cmp eax, edi
// 004c39e0  7409                 je 0x4c39eb
// 004c39e2  50                   push eax
// 004c39e3  e872fe3200           call 0x7f385a
// 004c39e8  83c404               add esp, 4
// 004c39eb  8b4e04               mov ecx, dword ptr [esi + 4]
// 004c39ee  51                   push ecx
// 004c39ef  897e10               mov dword ptr [esi + 0x10], edi
// 004c39f2  897e14               mov dword ptr [esi + 0x14], edi
// 004c39f5  897e18               mov dword ptr [esi + 0x18], edi
// 004c39f8  e85dfe3200           call 0x7f385a
// 004c39fd  83c404               add esp, 4
// 004c3a00  5f                   pop edi
// 004c3a01  5e                   pop esi
// 004c3a02  c3                   ret 
// library ogre-1.7.0/OgreRotationSpline.cpp (function ??1RotationalSpline@Ogre@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreRotationSpline.cpp
