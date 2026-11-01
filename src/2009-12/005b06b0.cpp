// from server: 100% by auto
// roc 2009-12 005b06b0  unit: seg_005b0000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b06b0
//
// 005b06b0  8b442404             mov eax, dword ptr [esp + 4]
// 005b06b4  8b542408             mov edx, dword ptr [esp + 8]
// 005b06b8  3bc2                 cmp eax, edx
// 005b06ba  741c                 je 0x5b06d8
// 005b06bc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005b06c0  d901                 fld dword ptr [ecx]
// 005b06c2  83c00c               add eax, 0xc
// 005b06c5  d958f4               fstp dword ptr [eax - 0xc]
// 005b06c8  d94104               fld dword ptr [ecx + 4]
// 005b06cb  d958f8               fstp dword ptr [eax - 8]
// 005b06ce  d94108               fld dword ptr [ecx + 8]
// 005b06d1  d958fc               fstp dword ptr [eax - 4]
// 005b06d4  3bc2                 cmp eax, edx
// 005b06d6  75e8                 jne 0x5b06c0
// 005b06d8  c3                   ret 
// library ogre-1.7.0/OgreMeshSerializerImpl.cpp (function ??$_Fill@PAVVector3@Ogre@@V12@@std@@YAXPAVVector3@Ogre@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMeshSerializerImpl.cpp
