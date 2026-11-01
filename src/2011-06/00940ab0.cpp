// from server: 100% by auto
// roc 2011-06 00940ab0  unit: Ogre::RbxMaterialAdapter  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00940ab0
//
// 00940ab0  8b442404             mov eax, dword ptr [esp + 4]
// 00940ab4  8b542408             mov edx, dword ptr [esp + 8]
// 00940ab8  3bc2                 cmp eax, edx
// 00940aba  741c                 je 0x940ad8
// 00940abc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00940ac0  d901                 fld dword ptr [ecx]
// 00940ac2  83c00c               add eax, 0xc
// 00940ac5  d958f4               fstp dword ptr [eax - 0xc]
// 00940ac8  d94104               fld dword ptr [ecx + 4]
// 00940acb  d958f8               fstp dword ptr [eax - 8]
// 00940ace  d94108               fld dword ptr [ecx + 8]
// 00940ad1  d958fc               fstp dword ptr [eax - 4]
// 00940ad4  3bc2                 cmp eax, edx
// 00940ad6  75e8                 jne 0x940ac0
// 00940ad8  c3                   ret 
// library ogre-1.7.0/OgreMeshSerializerImpl.cpp (function ??$_Fill@PAVVector3@Ogre@@V12@@std@@YAXPAVVector3@Ogre@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMeshSerializerImpl.cpp
