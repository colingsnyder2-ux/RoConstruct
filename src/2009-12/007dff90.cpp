// from server: 100% by auto
// roc 2009-12 007dff90  unit: RBX::CircleRadialNormal  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dff90
//
// 007dff90  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007dff94  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007dff98  56                   push esi
// 007dff99  8b742408             mov esi, dword ptr [esp + 8]
// 007dff9d  8bc1                 mov eax, ecx
// 007dff9f  2bc6                 sub eax, esi
// 007dffa1  c1f803               sar eax, 3
// 007dffa4  03c0                 add eax, eax
// 007dffa6  03c0                 add eax, eax
// 007dffa8  03c0                 add eax, eax
// 007dffaa  57                   push edi
// 007dffab  8bf8                 mov edi, eax
// 007dffad  8bc2                 mov eax, edx
// 007dffaf  2bc7                 sub eax, edi
// 007dffb1  3bf1                 cmp esi, ecx
// 007dffb3  7416                 je 0x7dffcb
// 007dffb5  2bd1                 sub edx, ecx
// 007dffb7  d941f8               fld dword ptr [ecx - 8]
// 007dffba  83e908               sub ecx, 8
// 007dffbd  d91c0a               fstp dword ptr [edx + ecx]
// 007dffc0  d94104               fld dword ptr [ecx + 4]
// 007dffc3  d95c0a04             fstp dword ptr [edx + ecx + 4]
// 007dffc7  3bce                 cmp ecx, esi
// 007dffc9  75ec                 jne 0x7dffb7
// 007dffcb  5f                   pop edi
// 007dffcc  5e                   pop esi
// 007dffcd  c3                   ret 
// library ogre-1.7.0/OgreShadowCameraSetupPlaneOptimal.cpp (function ??$_Copy_backward_opt@PAVVector2@Ogre@@PAV12@@std@@YAPAVVector2@Ogre@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreShadowCameraSetupPlaneOptimal.cpp
