// from server: 100% by auto
// roc 2010-06 008df5f0  unit: Ogre::RbxMaterialAdapter  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008df5f0
//
// 008df5f0  53                   push ebx
// 008df5f1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008df5f5  56                   push esi
// 008df5f6  8b74240c             mov esi, dword ptr [esp + 0xc]
// 008df5fa  57                   push edi
// 008df5fb  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 008df5ff  8bcf                 mov ecx, edi
// 008df601  2bce                 sub ecx, esi
// 008df603  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008df608  f7e9                 imul ecx
// 008df60a  d1fa                 sar edx, 1
// 008df60c  8bc2                 mov eax, edx
// 008df60e  c1e81f               shr eax, 0x1f
// 008df611  03c2                 add eax, edx
// 008df613  8d0440               lea eax, [eax + eax*2]
// 008df616  8d0483               lea eax, [ebx + eax*4]
// 008df619  8bd6                 mov edx, esi
// 008df61b  3bf7                 cmp esi, edi
// 008df61d  7421                 je 0x8df640
// 008df61f  8d4b08               lea ecx, [ebx + 8]
// 008df622  2bf3                 sub esi, ebx
// 008df624  d902                 fld dword ptr [edx]
// 008df626  83c20c               add edx, 0xc
// 008df629  d959f8               fstp dword ptr [ecx - 8]
// 008df62c  83c10c               add ecx, 0xc
// 008df62f  d942f8               fld dword ptr [edx - 8]
// 008df632  d959f0               fstp dword ptr [ecx - 0x10]
// 008df635  d9440ef4             fld dword ptr [esi + ecx - 0xc]
// 008df639  d959f4               fstp dword ptr [ecx - 0xc]
// 008df63c  3bd7                 cmp edx, edi
// 008df63e  75e4                 jne 0x8df624
// 008df640  5f                   pop edi
// 008df641  5e                   pop esi
// 008df642  5b                   pop ebx
// 008df643  c3                   ret 
// library ogre-1.7.0/OgreMesh.cpp (function ??$_Copy_opt@PAVVector3@Ogre@@PAV12@@std@@YAPAVVector3@Ogre@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMesh.cpp
