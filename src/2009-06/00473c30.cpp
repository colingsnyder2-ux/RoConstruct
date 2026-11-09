// from server: 100% by auto
// roc 2009-06 00473c30  unit: Ogre::VRbxSky::?$SharedPtr  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00473c30
//
// 00473c30  56                   push esi
// 00473c31  8b742408             mov esi, dword ptr [esp + 8]
// 00473c35  8d4604               lea eax, [esi + 4]
// 00473c38  8d5104               lea edx, [ecx + 4]
// 00473c3b  3bd0                 cmp edx, eax
// 00473c3d  740c                 je 0x473c4b
// 00473c3f  53                   push ebx
// 00473c40  8b18                 mov ebx, dword ptr [eax]
// 00473c42  57                   push edi
// 00473c43  8b3a                 mov edi, dword ptr [edx]
// 00473c45  891a                 mov dword ptr [edx], ebx
// 00473c47  8938                 mov dword ptr [eax], edi
// 00473c49  5f                   pop edi
// 00473c4a  5b                   pop ebx
// 00473c4b  8d4608               lea eax, [esi + 8]
// 00473c4e  83c108               add ecx, 8
// 00473c51  3bc8                 cmp ecx, eax
// 00473c53  7408                 je 0x473c5d
// 00473c55  8b30                 mov esi, dword ptr [eax]
// 00473c57  8b11                 mov edx, dword ptr [ecx]
// 00473c59  8931                 mov dword ptr [ecx], esi
// 00473c5b  8910                 mov dword ptr [eax], edx
// 00473c5d  5e                   pop esi
// 00473c5e  c20400               ret 4
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ?swap@?$SharedPtr@VHardwareVertexBuffer@Ogre@@@Ogre@@MAEXAAV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
