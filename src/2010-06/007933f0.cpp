// from server: 100% by auto
// roc 2010-06 007933f0  unit: RBX::CircleRadialNormal  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007933f0
//
// 007933f0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007933f4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007933f8  56                   push esi
// 007933f9  8b742408             mov esi, dword ptr [esp + 8]
// 007933fd  8bc1                 mov eax, ecx
// 007933ff  2bc6                 sub eax, esi
// 00793401  c1f803               sar eax, 3
// 00793404  03c0                 add eax, eax
// 00793406  03c0                 add eax, eax
// 00793408  03c0                 add eax, eax
// 0079340a  57                   push edi
// 0079340b  8bf8                 mov edi, eax
// 0079340d  8bc2                 mov eax, edx
// 0079340f  2bc7                 sub eax, edi
// 00793411  3bf1                 cmp esi, ecx
// 00793413  7416                 je 0x79342b
// 00793415  2bd1                 sub edx, ecx
// 00793417  d941f8               fld dword ptr [ecx - 8]
// 0079341a  83e908               sub ecx, 8
// 0079341d  d91c0a               fstp dword ptr [edx + ecx]
// 00793420  d94104               fld dword ptr [ecx + 4]
// 00793423  d95c0a04             fstp dword ptr [edx + ecx + 4]
// 00793427  3bce                 cmp ecx, esi
// 00793429  75ec                 jne 0x793417
// 0079342b  5f                   pop edi
// 0079342c  5e                   pop esi
// 0079342d  c3                   ret 
// library ogre-1.7.0/OgreShadowCameraSetupPlaneOptimal.cpp (function ??$_Copy_backward_opt@PAVVector2@Ogre@@PAV12@@std@@YAPAVVector2@Ogre@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreShadowCameraSetupPlaneOptimal.cpp
