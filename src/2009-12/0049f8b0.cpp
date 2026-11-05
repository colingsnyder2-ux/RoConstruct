// from server: 100% by auto
// roc 2009-12 0049f8b0  unit: Ogre::UTVertexSurfaceTexTangent::?$SpecializedMeshGen  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0049f8b0
//
// 0049f8b0  83ec08               sub esp, 8
// 0049f8b3  8b542414             mov edx, dword ptr [esp + 0x14]
// 0049f8b7  53                   push ebx
// 0049f8b8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0049f8bc  56                   push esi
// 0049f8bd  8b742418             mov esi, dword ptr [esp + 0x18]
// 0049f8c1  57                   push edi
// 0049f8c2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0049f8c6  32c0                 xor al, al
// 0049f8c8  88442410             mov byte ptr [esp + 0x10], al
// 0049f8cc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0049f8d0  8844240c             mov byte ptr [esp + 0xc], al
// 0049f8d4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0049f8d8  50                   push eax
// 0049f8d9  51                   push ecx
// 0049f8da  52                   push edx
// 0049f8db  57                   push edi
// 0049f8dc  56                   push esi
// 0049f8dd  53                   push ebx
// 0049f8de  e8bdfeffff           call 0x49f7a0
// 0049f8e3  2bf3                 sub esi, ebx
// 0049f8e5  b893244992           mov eax, 0x92492493
// 0049f8ea  f7ee                 imul esi
// 0049f8ec  03d6                 add edx, esi
// 0049f8ee  c1fa05               sar edx, 5
// 0049f8f1  8bc2                 mov eax, edx
// 0049f8f3  c1e81f               shr eax, 0x1f
// 0049f8f6  03c2                 add eax, edx
// 0049f8f8  8d0cc500000000       lea ecx, [eax*8]
// 0049f8ff  2bc8                 sub ecx, eax
// 0049f901  83c418               add esp, 0x18
// 0049f904  03c9                 add ecx, ecx
// 0049f906  8bc7                 mov eax, edi
// 0049f908  03c9                 add ecx, ecx
// 0049f90a  5f                   pop edi
// 0049f90b  03c9                 add ecx, ecx
// 0049f90d  5e                   pop esi
// 0049f90e  2bc1                 sub eax, ecx
// 0049f910  5b                   pop ebx
// 0049f911  83c408               add esp, 8
// 0049f914  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolygon2.cpp (function ??$_Copy_backward_opt@PAV?$Line2@N@Wml@@PAV12@@std@@YAPAV?$Line2@N@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolygon2.cpp
