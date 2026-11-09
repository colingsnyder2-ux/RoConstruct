// from server: 100% by auto
// roc 2009-12 007c6b60  unit: RBX::ScoreHud  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c6b60
//
// 007c6b60  53                   push ebx
// 007c6b61  55                   push ebp
// 007c6b62  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 007c6b66  56                   push esi
// 007c6b67  8b742410             mov esi, dword ptr [esp + 0x10]
// 007c6b6b  57                   push edi
// 007c6b6c  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 007c6b70  8bcf                 mov ecx, edi
// 007c6b72  2bce                 sub ecx, esi
// 007c6b74  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007c6b79  f7e9                 imul ecx
// 007c6b7b  c1fa02               sar edx, 2
// 007c6b7e  8bc2                 mov eax, edx
// 007c6b80  c1e81f               shr eax, 0x1f
// 007c6b83  03c2                 add eax, edx
// 007c6b85  8d0440               lea eax, [eax + eax*2]
// 007c6b88  8d2cc3               lea ebp, [ebx + eax*8]
// 007c6b8b  3bf7                 cmp esi, edi
// 007c6b8d  7412                 je 0x7c6ba1
// 007c6b8f  2bde                 sub ebx, esi
// 007c6b91  56                   push esi
// 007c6b92  8d0c33               lea ecx, [ebx + esi]
// 007c6b95  e82667d3ff           call 0x4fd2c0
// 007c6b9a  83c618               add esi, 0x18
// 007c6b9d  3bf7                 cmp esi, edi
// 007c6b9f  75f0                 jne 0x7c6b91
// 007c6ba1  5f                   pop edi
// 007c6ba2  5e                   pop esi
// 007c6ba3  8bc5                 mov eax, ebp
// 007c6ba5  5d                   pop ebp
// 007c6ba6  5b                   pop ebx
// 007c6ba7  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolyhedron3.cpp (function ??$_Copy_opt@PAV?$Vector3@N@Wml@@PAV12@@std@@YAPAV?$Vector3@N@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolyhedron3.cpp
