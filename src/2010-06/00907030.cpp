// from server: 100% by auto
// roc 2010-06 00907030  unit: RBX::RbxParticleEmitter  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00907030
//
// 00907030  53                   push ebx
// 00907031  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00907035  55                   push ebp
// 00907036  56                   push esi
// 00907037  8b742414             mov esi, dword ptr [esp + 0x14]
// 0090703b  57                   push edi
// 0090703c  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00907040  8bc6                 mov eax, esi
// 00907042  2bc7                 sub eax, edi
// 00907044  c1f803               sar eax, 3
// 00907047  03c0                 add eax, eax
// 00907049  03c0                 add eax, eax
// 0090704b  03c0                 add eax, eax
// 0090704d  8beb                 mov ebp, ebx
// 0090704f  2be8                 sub ebp, eax
// 00907051  3bfe                 cmp edi, esi
// 00907053  7412                 je 0x907067
// 00907055  2bde                 sub ebx, esi
// 00907057  83ee08               sub esi, 8
// 0090705a  56                   push esi
// 0090705b  8d0c33               lea ecx, [ebx + esi]
// 0090705e  e8ed9ce1ff           call 0x720d50
// 00907063  3bf7                 cmp esi, edi
// 00907065  75f0                 jne 0x907057
// 00907067  5f                   pop edi
// 00907068  5e                   pop esi
// 00907069  8bc5                 mov eax, ebp
// 0090706b  5d                   pop ebp
// 0090706c  5b                   pop ebx
// 0090706d  c3                   ret 
// library wildmagic-2-core/Containment\WmlContMinEllipseCR2.cpp (function ??$_Copy_backward_opt@PAV?$Vector2@M@Wml@@PAV12@@std@@YAPAV?$Vector2@M@Wml@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlContMinEllipseCR2.cpp
