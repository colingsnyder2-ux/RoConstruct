// from server: 100% by auto
// roc 2009-12 007b31e0  unit: RBX::Assembly  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b31e0
//
// 007b31e0  83ec08               sub esp, 8
// 007b31e3  8b542414             mov edx, dword ptr [esp + 0x14]
// 007b31e7  53                   push ebx
// 007b31e8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007b31ec  56                   push esi
// 007b31ed  8b742418             mov esi, dword ptr [esp + 0x18]
// 007b31f1  57                   push edi
// 007b31f2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007b31f6  32c0                 xor al, al
// 007b31f8  88442410             mov byte ptr [esp + 0x10], al
// 007b31fc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007b3200  8844240c             mov byte ptr [esp + 0xc], al
// 007b3204  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007b3208  50                   push eax
// 007b3209  51                   push ecx
// 007b320a  52                   push edx
// 007b320b  57                   push edi
// 007b320c  56                   push esi
// 007b320d  53                   push ebx
// 007b320e  e83dfeffff           call 0x7b3050
// 007b3213  2bf3                 sub esi, ebx
// 007b3215  b893244992           mov eax, 0x92492493
// 007b321a  f7ee                 imul esi
// 007b321c  03d6                 add edx, esi
// 007b321e  c1fa04               sar edx, 4
// 007b3221  8bc2                 mov eax, edx
// 007b3223  c1e81f               shr eax, 0x1f
// 007b3226  03c2                 add eax, edx
// 007b3228  8d0cc500000000       lea ecx, [eax*8]
// 007b322f  83c418               add esp, 0x18
// 007b3232  2bc8                 sub ecx, eax
// 007b3234  8bc7                 mov eax, edi
// 007b3236  03c9                 add ecx, ecx
// 007b3238  5f                   pop edi
// 007b3239  03c9                 add ecx, ecx
// 007b323b  5e                   pop esi
// 007b323c  2bc1                 sub eax, ecx
// 007b323e  5b                   pop ebx
// 007b323f  83c408               add esp, 8
// 007b3242  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolygon2.cpp (function ??$_Copy_backward_opt@PAV?$Line2@M@Wml@@PAV12@@std@@YAPAV?$Line2@M@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolygon2.cpp
