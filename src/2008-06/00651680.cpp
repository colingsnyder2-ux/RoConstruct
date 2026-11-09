// from server: 100% by auto
// roc 2008-06 00651680  unit: RBX::ScoreHud  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00651680
//
// 00651680  53                   push ebx
// 00651681  55                   push ebp
// 00651682  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00651686  56                   push esi
// 00651687  8b742410             mov esi, dword ptr [esp + 0x10]
// 0065168b  57                   push edi
// 0065168c  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00651690  8bcf                 mov ecx, edi
// 00651692  2bce                 sub ecx, esi
// 00651694  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00651699  f7e9                 imul ecx
// 0065169b  c1fa02               sar edx, 2
// 0065169e  8bc2                 mov eax, edx
// 006516a0  c1e81f               shr eax, 0x1f
// 006516a3  03c2                 add eax, edx
// 006516a5  8d0440               lea eax, [eax + eax*2]
// 006516a8  8d2cc3               lea ebp, [ebx + eax*8]
// 006516ab  3bf7                 cmp esi, edi
// 006516ad  7412                 je 0x6516c1
// 006516af  2bde                 sub ebx, esi
// 006516b1  56                   push esi
// 006516b2  8d0c33               lea ecx, [ebx + esi]
// 006516b5  e896c1e3ff           call 0x48d850
// 006516ba  83c618               add esi, 0x18
// 006516bd  3bf7                 cmp esi, edi
// 006516bf  75f0                 jne 0x6516b1
// 006516c1  5f                   pop edi
// 006516c2  5e                   pop esi
// 006516c3  8bc5                 mov eax, ebp
// 006516c5  5d                   pop ebp
// 006516c6  5b                   pop ebx
// 006516c7  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolyhedron3.cpp (function ??$_Copy_opt@PAV?$Vector3@N@Wml@@PAV12@@std@@YAPAV?$Vector3@N@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolyhedron3.cpp
