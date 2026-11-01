// from server: 100% by auto
// roc 2010-06 009529b0  unit: seg_00950000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009529b0
//
// 009529b0  53                   push ebx
// 009529b1  56                   push esi
// 009529b2  8b742410             mov esi, dword ptr [esp + 0x10]
// 009529b6  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 009529ba  57                   push edi
// 009529bb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 009529bf  8bce                 mov ecx, esi
// 009529c1  2bcf                 sub ecx, edi
// 009529c3  b8abaaaa2a           mov eax, 0x2aaaaaab
// 009529c8  f7e9                 imul ecx
// 009529ca  d1fa                 sar edx, 1
// 009529cc  8bc2                 mov eax, edx
// 009529ce  c1e81f               shr eax, 0x1f
// 009529d1  03c2                 add eax, edx
// 009529d3  8d0440               lea eax, [eax + eax*2]
// 009529d6  03c0                 add eax, eax
// 009529d8  03c0                 add eax, eax
// 009529da  8bc8                 mov ecx, eax
// 009529dc  8bc3                 mov eax, ebx
// 009529de  2bc1                 sub eax, ecx
// 009529e0  8bd6                 mov edx, esi
// 009529e2  3bfe                 cmp edi, esi
// 009529e4  7425                 je 0x952a0b
// 009529e6  8d4b08               lea ecx, [ebx + 8]
// 009529e9  2bf3                 sub esi, ebx
// 009529eb  eb03                 jmp 0x9529f0
// 009529ed  8d4900               lea ecx, [ecx]
// 009529f0  d942f4               fld dword ptr [edx - 0xc]
// 009529f3  83ea0c               sub edx, 0xc
// 009529f6  83e90c               sub ecx, 0xc
// 009529f9  d959f8               fstp dword ptr [ecx - 8]
// 009529fc  d94204               fld dword ptr [edx + 4]
// 009529ff  d959fc               fstp dword ptr [ecx - 4]
// 00952a02  d9040e               fld dword ptr [esi + ecx]
// 00952a05  d919                 fstp dword ptr [ecx]
// 00952a07  3bd7                 cmp edx, edi
// 00952a09  75e5                 jne 0x9529f0
// 00952a0b  5f                   pop edi
// 00952a0c  5e                   pop esi
// 00952a0d  5b                   pop ebx
// 00952a0e  c3                   ret 
// library ogre-1.7.0/OgreMeshSerializerImpl.cpp (function ??$_Copy_backward_opt@PAVVector3@Ogre@@PAV12@@std@@YAPAVVector3@Ogre@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMeshSerializerImpl.cpp
