// from server: 100% by auto
// roc 2008-06 0068ddc0  unit: Ogre::VDataStream::?$SharedPtr  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0068ddc0
//
// 0068ddc0  56                   push esi
// 0068ddc1  8b742408             mov esi, dword ptr [esp + 8]
// 0068ddc5  8d4604               lea eax, [esi + 4]
// 0068ddc8  8d5104               lea edx, [ecx + 4]
// 0068ddcb  3bd0                 cmp edx, eax
// 0068ddcd  740c                 je 0x68dddb
// 0068ddcf  53                   push ebx
// 0068ddd0  8b18                 mov ebx, dword ptr [eax]
// 0068ddd2  57                   push edi
// 0068ddd3  8b3a                 mov edi, dword ptr [edx]
// 0068ddd5  891a                 mov dword ptr [edx], ebx
// 0068ddd7  8938                 mov dword ptr [eax], edi
// 0068ddd9  5f                   pop edi
// 0068ddda  5b                   pop ebx
// 0068dddb  8d4608               lea eax, [esi + 8]
// 0068ddde  83c108               add ecx, 8
// 0068dde1  3bc8                 cmp ecx, eax
// 0068dde3  7408                 je 0x68dded
// 0068dde5  8b30                 mov esi, dword ptr [eax]
// 0068dde7  8b11                 mov edx, dword ptr [ecx]
// 0068dde9  8931                 mov dword ptr [ecx], esi
// 0068ddeb  8910                 mov dword ptr [eax], edx
// 0068dded  5e                   pop esi
// 0068ddee  c20400               ret 4
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ?swap@?$SharedPtr@VHardwareVertexBuffer@Ogre@@@Ogre@@MAEXAAV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
