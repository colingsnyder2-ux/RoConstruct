// from server: 100% by auto
// roc 2009-12 004b9d30  unit: Ogre::RbxCullableSceneNode  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b9d30
//
// 004b9d30  53                   push ebx
// 004b9d31  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004b9d35  56                   push esi
// 004b9d36  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004b9d3a  57                   push edi
// 004b9d3b  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004b9d3f  8bcf                 mov ecx, edi
// 004b9d41  2bce                 sub ecx, esi
// 004b9d43  b8abaaaa2a           mov eax, 0x2aaaaaab
// 004b9d48  f7e9                 imul ecx
// 004b9d4a  d1fa                 sar edx, 1
// 004b9d4c  8bc2                 mov eax, edx
// 004b9d4e  c1e81f               shr eax, 0x1f
// 004b9d51  03c2                 add eax, edx
// 004b9d53  8d0440               lea eax, [eax + eax*2]
// 004b9d56  8d0483               lea eax, [ebx + eax*4]
// 004b9d59  8bd6                 mov edx, esi
// 004b9d5b  3bf7                 cmp esi, edi
// 004b9d5d  7421                 je 0x4b9d80
// 004b9d5f  8d4b08               lea ecx, [ebx + 8]
// 004b9d62  2bf3                 sub esi, ebx
// 004b9d64  d902                 fld dword ptr [edx]
// 004b9d66  83c20c               add edx, 0xc
// 004b9d69  d959f8               fstp dword ptr [ecx - 8]
// 004b9d6c  83c10c               add ecx, 0xc
// 004b9d6f  d942f8               fld dword ptr [edx - 8]
// 004b9d72  d959f0               fstp dword ptr [ecx - 0x10]
// 004b9d75  d9440ef4             fld dword ptr [esi + ecx - 0xc]
// 004b9d79  d959f4               fstp dword ptr [ecx - 0xc]
// 004b9d7c  3bd7                 cmp edx, edi
// 004b9d7e  75e4                 jne 0x4b9d64
// 004b9d80  5f                   pop edi
// 004b9d81  5e                   pop esi
// 004b9d82  5b                   pop ebx
// 004b9d83  c3                   ret 
// library ogre-1.7.0/OgreMesh.cpp (function ??$_Copy_opt@PAVVector3@Ogre@@PAV12@@std@@YAPAVVector3@Ogre@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMesh.cpp
