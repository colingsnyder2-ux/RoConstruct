// from server: 100% by auto
// roc 2009-12 005ad930  unit: seg_005a0000  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005ad930
//
// 005ad930  53                   push ebx
// 005ad931  56                   push esi
// 005ad932  8b742410             mov esi, dword ptr [esp + 0x10]
// 005ad936  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005ad93a  57                   push edi
// 005ad93b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005ad93f  8bce                 mov ecx, esi
// 005ad941  2bcf                 sub ecx, edi
// 005ad943  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005ad948  f7e9                 imul ecx
// 005ad94a  d1fa                 sar edx, 1
// 005ad94c  8bc2                 mov eax, edx
// 005ad94e  c1e81f               shr eax, 0x1f
// 005ad951  03c2                 add eax, edx
// 005ad953  8d0440               lea eax, [eax + eax*2]
// 005ad956  03c0                 add eax, eax
// 005ad958  03c0                 add eax, eax
// 005ad95a  8bc8                 mov ecx, eax
// 005ad95c  8bc3                 mov eax, ebx
// 005ad95e  2bc1                 sub eax, ecx
// 005ad960  8bd6                 mov edx, esi
// 005ad962  3bfe                 cmp edi, esi
// 005ad964  7425                 je 0x5ad98b
// 005ad966  8d4b08               lea ecx, [ebx + 8]
// 005ad969  2bf3                 sub esi, ebx
// 005ad96b  eb03                 jmp 0x5ad970
// 005ad96d  8d4900               lea ecx, [ecx]
// 005ad970  d942f4               fld dword ptr [edx - 0xc]
// 005ad973  83ea0c               sub edx, 0xc
// 005ad976  83e90c               sub ecx, 0xc
// 005ad979  d959f8               fstp dword ptr [ecx - 8]
// 005ad97c  d94204               fld dword ptr [edx + 4]
// 005ad97f  d959fc               fstp dword ptr [ecx - 4]
// 005ad982  d9040e               fld dword ptr [esi + ecx]
// 005ad985  d919                 fstp dword ptr [ecx]
// 005ad987  3bd7                 cmp edx, edi
// 005ad989  75e5                 jne 0x5ad970
// 005ad98b  5f                   pop edi
// 005ad98c  5e                   pop esi
// 005ad98d  5b                   pop ebx
// 005ad98e  c3                   ret 
// library ogre-1.7.0/OgreMeshSerializerImpl.cpp (function ??$_Copy_backward_opt@PAVVector3@Ogre@@PAV12@@std@@YAPAVVector3@Ogre@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMeshSerializerImpl.cpp
