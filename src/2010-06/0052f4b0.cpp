// from server: 100% by auto
// roc 2010-06 0052f4b0  unit: RBX::VAggregateChunk::?$WeakReferenceCountedPointer  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0052f4b0
//
// 0052f4b0  56                   push esi
// 0052f4b1  8bf1                 mov esi, ecx
// 0052f4b3  8b4628               mov eax, dword ptr [esi + 0x28]
// 0052f4b6  57                   push edi
// 0052f4b7  33ff                 xor edi, edi
// 0052f4b9  3bc7                 cmp eax, edi
// 0052f4bb  7409                 je 0x52f4c6
// 0052f4bd  50                   push eax
// 0052f4be  e8d7842700           call 0x7a799a
// 0052f4c3  83c404               add esp, 4
// 0052f4c6  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0052f4c9  50                   push eax
// 0052f4ca  897e28               mov dword ptr [esi + 0x28], edi
// 0052f4cd  897e2c               mov dword ptr [esi + 0x2c], edi
// 0052f4d0  897e30               mov dword ptr [esi + 0x30], edi
// 0052f4d3  e8c2842700           call 0x7a799a
// 0052f4d8  8b4610               mov eax, dword ptr [esi + 0x10]
// 0052f4db  83c404               add esp, 4
// 0052f4de  3bc7                 cmp eax, edi
// 0052f4e0  7409                 je 0x52f4eb
// 0052f4e2  50                   push eax
// 0052f4e3  e8b2842700           call 0x7a799a
// 0052f4e8  83c404               add esp, 4
// 0052f4eb  8b4e04               mov ecx, dword ptr [esi + 4]
// 0052f4ee  51                   push ecx
// 0052f4ef  897e10               mov dword ptr [esi + 0x10], edi
// 0052f4f2  897e14               mov dword ptr [esi + 0x14], edi
// 0052f4f5  897e18               mov dword ptr [esi + 0x18], edi
// 0052f4f8  e89d842700           call 0x7a799a
// 0052f4fd  83c404               add esp, 4
// 0052f500  5f                   pop edi
// 0052f501  5e                   pop esi
// 0052f502  c3                   ret 
// library ogre-1.7.0/OgreRotationSpline.cpp (function ??1RotationalSpline@Ogre@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreRotationSpline.cpp
