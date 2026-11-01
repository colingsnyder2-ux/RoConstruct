// from server: 100% by auto
// roc 2009-06 006e2960  unit: RBX::ScoreHud  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e2960
//
// 006e2960  53                   push ebx
// 006e2961  55                   push ebp
// 006e2962  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 006e2966  56                   push esi
// 006e2967  8b742410             mov esi, dword ptr [esp + 0x10]
// 006e296b  57                   push edi
// 006e296c  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 006e2970  8bcf                 mov ecx, edi
// 006e2972  2bce                 sub ecx, esi
// 006e2974  b8abaaaa2a           mov eax, 0x2aaaaaab
// 006e2979  f7e9                 imul ecx
// 006e297b  c1fa02               sar edx, 2
// 006e297e  8bc2                 mov eax, edx
// 006e2980  c1e81f               shr eax, 0x1f
// 006e2983  03c2                 add eax, edx
// 006e2985  8d0440               lea eax, [eax + eax*2]
// 006e2988  8d2cc3               lea ebp, [ebx + eax*8]
// 006e298b  3bf7                 cmp esi, edi
// 006e298d  7412                 je 0x6e29a1
// 006e298f  2bde                 sub ebx, esi
// 006e2991  56                   push esi
// 006e2992  8d0c33               lea ecx, [ebx + esi]
// 006e2995  e81670ddff           call 0x4b99b0
// 006e299a  83c618               add esi, 0x18
// 006e299d  3bf7                 cmp esi, edi
// 006e299f  75f0                 jne 0x6e2991
// 006e29a1  5f                   pop edi
// 006e29a2  5e                   pop esi
// 006e29a3  8bc5                 mov eax, ebp
// 006e29a5  5d                   pop ebp
// 006e29a6  5b                   pop ebx
// 006e29a7  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolyhedron3.cpp (function ??$_Copy_opt@PAV?$Vector3@N@Wml@@PAV12@@std@@YAPAV?$Vector3@N@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolyhedron3.cpp
