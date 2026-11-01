// from server: 100% by auto
// roc 2010-06 00975850  unit: RBX::RightAngleRampBuilder  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00975850
//
// 00975850  8b542408             mov edx, dword ptr [esp + 8]
// 00975854  53                   push ebx
// 00975855  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00975859  57                   push edi
// 0097585a  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0097585e  8bc2                 mov eax, edx
// 00975860  2bc7                 sub eax, edi
// 00975862  c1f804               sar eax, 4
// 00975865  c1e004               shl eax, 4
// 00975868  8bc8                 mov ecx, eax
// 0097586a  8bc3                 mov eax, ebx
// 0097586c  2bc1                 sub eax, ecx
// 0097586e  3bfa                 cmp edi, edx
// 00975870  7430                 je 0x9758a2
// 00975872  56                   push esi
// 00975873  8bf2                 mov esi, edx
// 00975875  8d4b08               lea ecx, [ebx + 8]
// 00975878  2bf3                 sub esi, ebx
// 0097587a  8d9b00000000         lea ebx, [ebx]
// 00975880  d942f0               fld dword ptr [edx - 0x10]
// 00975883  83ea10               sub edx, 0x10
// 00975886  83e910               sub ecx, 0x10
// 00975889  d959f8               fstp dword ptr [ecx - 8]
// 0097588c  d94204               fld dword ptr [edx + 4]
// 0097588f  d959fc               fstp dword ptr [ecx - 4]
// 00975892  d9040e               fld dword ptr [esi + ecx]
// 00975895  d919                 fstp dword ptr [ecx]
// 00975897  d9420c               fld dword ptr [edx + 0xc]
// 0097589a  d95904               fstp dword ptr [ecx + 4]
// 0097589d  3bd7                 cmp edx, edi
// 0097589f  75df                 jne 0x975880
// 009758a1  5e                   pop esi
// 009758a2  5f                   pop edi
// 009758a3  5b                   pop ebx
// 009758a4  c3                   ret 
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??$_Copy_backward_opt@PAVVector4@Ogre@@PAV12@@std@@YAPAVVector4@Ogre@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
