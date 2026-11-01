// from server: 100% by auto
// roc 2011-06 00967100  unit: Ogre::RbxCluster::VRbxPartBinding::?$sp_counted_impl_p  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00967100
//
// 00967100  56                   push esi
// 00967101  8bf1                 mov esi, ecx
// 00967103  8b4618               mov eax, dword ptr [esi + 0x18]
// 00967106  57                   push edi
// 00967107  33ff                 xor edi, edi
// 00967109  3bc7                 cmp eax, edi
// 0096710b  7409                 je 0x967116
// 0096710d  50                   push eax
// 0096710e  e8452feaff           call 0x80a058
// 00967113  83c404               add esp, 4
// 00967116  897e18               mov dword ptr [esi + 0x18], edi
// 00967119  897e1c               mov dword ptr [esi + 0x1c], edi
// 0096711c  897e20               mov dword ptr [esi + 0x20], edi
// 0096711f  8b4608               mov eax, dword ptr [esi + 8]
// 00967122  3bc7                 cmp eax, edi
// 00967124  7409                 je 0x96712f
// 00967126  50                   push eax
// 00967127  e82c2feaff           call 0x80a058
// 0096712c  83c404               add esp, 4
// 0096712f  897e08               mov dword ptr [esi + 8], edi
// 00967132  897e0c               mov dword ptr [esi + 0xc], edi
// 00967135  897e10               mov dword ptr [esi + 0x10], edi
// 00967138  5f                   pop edi
// 00967139  5e                   pop esi
// 0096713a  c3                   ret 
// library ogre-1.7.0/OgreRotationSpline.cpp (function ??1RotationalSpline@Ogre@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreRotationSpline.cpp
