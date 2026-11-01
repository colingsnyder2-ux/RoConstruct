// from server: 100% by auto
// roc 2009-12 004be180  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004be180
//
// 004be180  8b442408             mov eax, dword ptr [esp + 8]
// 004be184  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004be188  8b11                 mov edx, dword ptr [ecx]
// 004be18a  53                   push ebx
// 004be18b  8b58f8               mov ebx, dword ptr [eax - 8]
// 004be18e  55                   push ebp
// 004be18f  8b68fc               mov ebp, dword ptr [eax - 4]
// 004be192  56                   push esi
// 004be193  8b70f0               mov esi, dword ptr [eax - 0x10]
// 004be196  57                   push edi
// 004be197  8b78f4               mov edi, dword ptr [eax - 0xc]
// 004be19a  8950f0               mov dword ptr [eax - 0x10], edx
// 004be19d  8b5104               mov edx, dword ptr [ecx + 4]
// 004be1a0  8950f4               mov dword ptr [eax - 0xc], edx
// 004be1a3  8b5108               mov edx, dword ptr [ecx + 8]
// 004be1a6  8950f8               mov dword ptr [eax - 8], edx
// 004be1a9  8b510c               mov edx, dword ptr [ecx + 0xc]
// 004be1ac  8950fc               mov dword ptr [eax - 4], edx
// 004be1af  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004be1b3  52                   push edx
// 004be1b4  2bc1                 sub eax, ecx
// 004be1b6  83ec10               sub esp, 0x10
// 004be1b9  8bd4                 mov edx, esp
// 004be1bb  83e810               sub eax, 0x10
// 004be1be  c1f804               sar eax, 4
// 004be1c1  50                   push eax
// 004be1c2  8932                 mov dword ptr [edx], esi
// 004be1c4  897a04               mov dword ptr [edx + 4], edi
// 004be1c7  6a00                 push 0
// 004be1c9  895a08               mov dword ptr [edx + 8], ebx
// 004be1cc  51                   push ecx
// 004be1cd  896a0c               mov dword ptr [edx + 0xc], ebp
// 004be1d0  e8ebfaffff           call 0x4bdcc0
// 004be1d5  83c420               add esp, 0x20
// 004be1d8  5f                   pop edi
// 004be1d9  5e                   pop esi
// 004be1da  5d                   pop ebp
// 004be1db  5b                   pop ebx
// 004be1dc  c3                   ret 
// library ogre-1.6.4/OgreEdgeListBuilder.cpp (function ??$_Pop_heap_0@PAUGeometry@EdgeListBuilder@Ogre@@U123@UgeometryLess@23@@std@@YAXPAUGeometry@EdgeListBuilder@Ogre@@0UgeometryLess@23@0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreEdgeListBuilder.cpp
