// from server: 100% by auto
// roc 2010-06 00793390  unit: RBX::CircleRadialNormal  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00793390
//
// 00793390  8b442404             mov eax, dword ptr [esp + 4]
// 00793394  8b542408             mov edx, dword ptr [esp + 8]
// 00793398  3bc2                 cmp eax, edx
// 0079339a  7416                 je 0x7933b2
// 0079339c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007933a0  d901                 fld dword ptr [ecx]
// 007933a2  83c008               add eax, 8
// 007933a5  d958f8               fstp dword ptr [eax - 8]
// 007933a8  d94104               fld dword ptr [ecx + 4]
// 007933ab  d958fc               fstp dword ptr [eax - 4]
// 007933ae  3bc2                 cmp eax, edx
// 007933b0  75ee                 jne 0x7933a0
// 007933b2  c3                   ret 
// library ogre-1.7.0/OgreShadowCameraSetupPlaneOptimal.cpp (function ??$_Fill@PAVVector2@Ogre@@V12@@std@@YAXPAVVector2@Ogre@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreShadowCameraSetupPlaneOptimal.cpp
