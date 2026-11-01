// from server: 100% by auto
// roc 2009-12 007dff30  unit: RBX::CircleRadialNormal  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dff30
//
// 007dff30  8b442404             mov eax, dword ptr [esp + 4]
// 007dff34  8b542408             mov edx, dword ptr [esp + 8]
// 007dff38  3bc2                 cmp eax, edx
// 007dff3a  7416                 je 0x7dff52
// 007dff3c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007dff40  d901                 fld dword ptr [ecx]
// 007dff42  83c008               add eax, 8
// 007dff45  d958f8               fstp dword ptr [eax - 8]
// 007dff48  d94104               fld dword ptr [ecx + 4]
// 007dff4b  d958fc               fstp dword ptr [eax - 4]
// 007dff4e  3bc2                 cmp eax, edx
// 007dff50  75ee                 jne 0x7dff40
// 007dff52  c3                   ret 
// library ogre-1.7.0/OgreShadowCameraSetupPlaneOptimal.cpp (function ??$_Fill@PAVVector2@Ogre@@V12@@std@@YAXPAVVector2@Ogre@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreShadowCameraSetupPlaneOptimal.cpp
