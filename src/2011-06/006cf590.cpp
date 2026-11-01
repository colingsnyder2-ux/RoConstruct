// from server: 100% by auto
// roc 2011-06 006cf590  unit: RBX::Mechanism  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006cf590
//
// 006cf590  8b442404             mov eax, dword ptr [esp + 4]
// 006cf594  8b542408             mov edx, dword ptr [esp + 8]
// 006cf598  3bc2                 cmp eax, edx
// 006cf59a  7416                 je 0x6cf5b2
// 006cf59c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006cf5a0  d901                 fld dword ptr [ecx]
// 006cf5a2  83c008               add eax, 8
// 006cf5a5  d958f8               fstp dword ptr [eax - 8]
// 006cf5a8  d94104               fld dword ptr [ecx + 4]
// 006cf5ab  d958fc               fstp dword ptr [eax - 4]
// 006cf5ae  3bc2                 cmp eax, edx
// 006cf5b0  75ee                 jne 0x6cf5a0
// 006cf5b2  c3                   ret 
// library ogre-1.7.0/OgreShadowCameraSetupPlaneOptimal.cpp (function ??$_Fill@PAVVector2@Ogre@@V12@@std@@YAXPAVVector2@Ogre@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreShadowCameraSetupPlaneOptimal.cpp
