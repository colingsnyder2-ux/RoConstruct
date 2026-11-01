// from server: 100% by auto
// roc 2010-06 00975920  unit: RBX::RightAngleRampBuilder  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00975920
//
// 00975920  8b442404             mov eax, dword ptr [esp + 4]
// 00975924  8b542408             mov edx, dword ptr [esp + 8]
// 00975928  3bc2                 cmp eax, edx
// 0097592a  742a                 je 0x975956
// 0097592c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00975930  83c008               add eax, 8
// 00975933  56                   push esi
// 00975934  d901                 fld dword ptr [ecx]
// 00975936  83c010               add eax, 0x10
// 00975939  d958e8               fstp dword ptr [eax - 0x18]
// 0097593c  8d70f8               lea esi, [eax - 8]
// 0097593f  d94104               fld dword ptr [ecx + 4]
// 00975942  d958ec               fstp dword ptr [eax - 0x14]
// 00975945  d94108               fld dword ptr [ecx + 8]
// 00975948  d958f0               fstp dword ptr [eax - 0x10]
// 0097594b  d9410c               fld dword ptr [ecx + 0xc]
// 0097594e  d958f4               fstp dword ptr [eax - 0xc]
// 00975951  3bf2                 cmp esi, edx
// 00975953  75df                 jne 0x975934
// 00975955  5e                   pop esi
// 00975956  c3                   ret 
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??$fill@PAVVector4@Ogre@@V12@@std@@YAXPAVVector4@Ogre@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
