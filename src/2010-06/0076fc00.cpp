// from server: 100% by auto
// roc 2010-06 0076fc00  unit: RBX::ScoreHud  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076fc00
//
// 0076fc00  53                   push ebx
// 0076fc01  55                   push ebp
// 0076fc02  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0076fc06  56                   push esi
// 0076fc07  8b742410             mov esi, dword ptr [esp + 0x10]
// 0076fc0b  57                   push edi
// 0076fc0c  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0076fc10  8bcf                 mov ecx, edi
// 0076fc12  2bce                 sub ecx, esi
// 0076fc14  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0076fc19  f7e9                 imul ecx
// 0076fc1b  c1fa02               sar edx, 2
// 0076fc1e  8bc2                 mov eax, edx
// 0076fc20  c1e81f               shr eax, 0x1f
// 0076fc23  03c2                 add eax, edx
// 0076fc25  8d0440               lea eax, [eax + eax*2]
// 0076fc28  8d2cc3               lea ebp, [ebx + eax*8]
// 0076fc2b  3bf7                 cmp esi, edi
// 0076fc2d  7412                 je 0x76fc41
// 0076fc2f  2bde                 sub ebx, esi
// 0076fc31  56                   push esi
// 0076fc32  8d0c33               lea ecx, [ebx + esi]
// 0076fc35  e8c6acd3ff           call 0x4aa900
// 0076fc3a  83c618               add esi, 0x18
// 0076fc3d  3bf7                 cmp esi, edi
// 0076fc3f  75f0                 jne 0x76fc31
// 0076fc41  5f                   pop edi
// 0076fc42  5e                   pop esi
// 0076fc43  8bc5                 mov eax, ebp
// 0076fc45  5d                   pop ebp
// 0076fc46  5b                   pop ebx
// 0076fc47  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolyhedron3.cpp (function ??$_Copy_opt@PAV?$Vector3@N@Wml@@PAV12@@std@@YAPAV?$Vector3@N@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolyhedron3.cpp
