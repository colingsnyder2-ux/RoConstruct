// from server: 100% by auto
// roc 2011-06 009c0360  unit: RBX::WedgeBuilder  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009c0360
//
// 009c0360  8b442404             mov eax, dword ptr [esp + 4]
// 009c0364  8b542408             mov edx, dword ptr [esp + 8]
// 009c0368  3bc2                 cmp eax, edx
// 009c036a  742a                 je 0x9c0396
// 009c036c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009c0370  83c008               add eax, 8
// 009c0373  56                   push esi
// 009c0374  d901                 fld dword ptr [ecx]
// 009c0376  83c010               add eax, 0x10
// 009c0379  d958e8               fstp dword ptr [eax - 0x18]
// 009c037c  8d70f8               lea esi, [eax - 8]
// 009c037f  d94104               fld dword ptr [ecx + 4]
// 009c0382  d958ec               fstp dword ptr [eax - 0x14]
// 009c0385  d94108               fld dword ptr [ecx + 8]
// 009c0388  d958f0               fstp dword ptr [eax - 0x10]
// 009c038b  d9410c               fld dword ptr [ecx + 0xc]
// 009c038e  d958f4               fstp dword ptr [eax - 0xc]
// 009c0391  3bf2                 cmp esi, edx
// 009c0393  75df                 jne 0x9c0374
// 009c0395  5e                   pop esi
// 009c0396  c3                   ret 
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??$fill@PAVVector4@Ogre@@V12@@std@@YAXPAVVector4@Ogre@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
