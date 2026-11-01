// from server: 100% by auto
// roc 2010-06 009046a0  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009046a0
//
// 009046a0  8b442408             mov eax, dword ptr [esp + 8]
// 009046a4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 009046a8  8b11                 mov edx, dword ptr [ecx]
// 009046aa  53                   push ebx
// 009046ab  8b58f8               mov ebx, dword ptr [eax - 8]
// 009046ae  55                   push ebp
// 009046af  8b68fc               mov ebp, dword ptr [eax - 4]
// 009046b2  56                   push esi
// 009046b3  8b70f0               mov esi, dword ptr [eax - 0x10]
// 009046b6  57                   push edi
// 009046b7  8b78f4               mov edi, dword ptr [eax - 0xc]
// 009046ba  8950f0               mov dword ptr [eax - 0x10], edx
// 009046bd  8b5104               mov edx, dword ptr [ecx + 4]
// 009046c0  8950f4               mov dword ptr [eax - 0xc], edx
// 009046c3  8b5108               mov edx, dword ptr [ecx + 8]
// 009046c6  8950f8               mov dword ptr [eax - 8], edx
// 009046c9  8b510c               mov edx, dword ptr [ecx + 0xc]
// 009046cc  8950fc               mov dword ptr [eax - 4], edx
// 009046cf  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 009046d3  52                   push edx
// 009046d4  2bc1                 sub eax, ecx
// 009046d6  83ec10               sub esp, 0x10
// 009046d9  8bd4                 mov edx, esp
// 009046db  83e810               sub eax, 0x10
// 009046de  c1f804               sar eax, 4
// 009046e1  50                   push eax
// 009046e2  8932                 mov dword ptr [edx], esi
// 009046e4  897a04               mov dword ptr [edx + 4], edi
// 009046e7  6a00                 push 0
// 009046e9  895a08               mov dword ptr [edx + 8], ebx
// 009046ec  51                   push ecx
// 009046ed  896a0c               mov dword ptr [edx + 0xc], ebp
// 009046f0  e84bfdffff           call 0x904440
// 009046f5  83c420               add esp, 0x20
// 009046f8  5f                   pop edi
// 009046f9  5e                   pop esi
// 009046fa  5d                   pop ebp
// 009046fb  5b                   pop ebx
// 009046fc  c3                   ret 
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??$_Pop_heap_0@PAUGeometry@EdgeListBuilder@Ogre@@U123@UgeometryLess@23@@std@@YAXPAUGeometry@EdgeListBuilder@Ogre@@0UgeometryLess@23@0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
