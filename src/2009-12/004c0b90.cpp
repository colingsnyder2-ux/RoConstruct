// from server: 100% by auto
// roc 2009-12 004c0b90  unit: RBX::RbxParticleEmitter  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c0b90
//
// 004c0b90  53                   push ebx
// 004c0b91  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004c0b95  55                   push ebp
// 004c0b96  56                   push esi
// 004c0b97  8b742414             mov esi, dword ptr [esp + 0x14]
// 004c0b9b  57                   push edi
// 004c0b9c  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004c0ba0  8bc6                 mov eax, esi
// 004c0ba2  2bc7                 sub eax, edi
// 004c0ba4  c1f803               sar eax, 3
// 004c0ba7  03c0                 add eax, eax
// 004c0ba9  03c0                 add eax, eax
// 004c0bab  03c0                 add eax, eax
// 004c0bad  8beb                 mov ebp, ebx
// 004c0baf  2be8                 sub ebp, eax
// 004c0bb1  3bfe                 cmp edi, esi
// 004c0bb3  7412                 je 0x4c0bc7
// 004c0bb5  2bde                 sub ebx, esi
// 004c0bb7  83ee08               sub esi, 8
// 004c0bba  56                   push esi
// 004c0bbb  8d0c33               lea ecx, [ebx + esi]
// 004c0bbe  e8bdae0b00           call 0x57ba80
// 004c0bc3  3bf7                 cmp esi, edi
// 004c0bc5  75f0                 jne 0x4c0bb7
// 004c0bc7  5f                   pop edi
// 004c0bc8  5e                   pop esi
// 004c0bc9  8bc5                 mov eax, ebp
// 004c0bcb  5d                   pop ebp
// 004c0bcc  5b                   pop ebx
// 004c0bcd  c3                   ret 
// library wildmagic-2-core/Containment\WmlContMinEllipseCR2.cpp (function ??$_Copy_backward_opt@PAV?$Vector2@M@Wml@@PAV12@@std@@YAPAV?$Vector2@M@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContMinEllipseCR2.cpp
