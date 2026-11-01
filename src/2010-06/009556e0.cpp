// from server: 100% by auto
// roc 2010-06 009556e0  unit: seg_00950000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009556e0
//
// 009556e0  8b442404             mov eax, dword ptr [esp + 4]
// 009556e4  8b542408             mov edx, dword ptr [esp + 8]
// 009556e8  3bc2                 cmp eax, edx
// 009556ea  741c                 je 0x955708
// 009556ec  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009556f0  d901                 fld dword ptr [ecx]
// 009556f2  83c00c               add eax, 0xc
// 009556f5  d958f4               fstp dword ptr [eax - 0xc]
// 009556f8  d94104               fld dword ptr [ecx + 4]
// 009556fb  d958f8               fstp dword ptr [eax - 8]
// 009556fe  d94108               fld dword ptr [ecx + 8]
// 00955701  d958fc               fstp dword ptr [eax - 4]
// 00955704  3bc2                 cmp eax, edx
// 00955706  75e8                 jne 0x9556f0
// 00955708  c3                   ret 
// library ogre-1.7.0/OgreMeshSerializerImpl.cpp (function ??$_Fill@PAVVector3@Ogre@@V12@@std@@YAXPAVVector3@Ogre@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMeshSerializerImpl.cpp
