// from server: 100% by auto
// roc 2010-06 006aae40  unit: boost::Vthread::?$sp_counted_impl_p  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006aae40
//
// 006aae40  83ec08               sub esp, 8
// 006aae43  8b542414             mov edx, dword ptr [esp + 0x14]
// 006aae47  53                   push ebx
// 006aae48  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006aae4c  56                   push esi
// 006aae4d  8b742418             mov esi, dword ptr [esp + 0x18]
// 006aae51  57                   push edi
// 006aae52  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006aae56  32c0                 xor al, al
// 006aae58  88442410             mov byte ptr [esp + 0x10], al
// 006aae5c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006aae60  8844240c             mov byte ptr [esp + 0xc], al
// 006aae64  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006aae68  50                   push eax
// 006aae69  51                   push ecx
// 006aae6a  52                   push edx
// 006aae6b  57                   push edi
// 006aae6c  56                   push esi
// 006aae6d  53                   push ebx
// 006aae6e  e8adfcffff           call 0x6aab20
// 006aae73  2bf3                 sub esi, ebx
// 006aae75  b867666666           mov eax, 0x66666667
// 006aae7a  f7ee                 imul esi
// 006aae7c  c1fa04               sar edx, 4
// 006aae7f  8bc2                 mov eax, edx
// 006aae81  c1e81f               shr eax, 0x1f
// 006aae84  03c2                 add eax, edx
// 006aae86  8d0480               lea eax, [eax + eax*4]
// 006aae89  03c0                 add eax, eax
// 006aae8b  03c0                 add eax, eax
// 006aae8d  03c0                 add eax, eax
// 006aae8f  83c418               add esp, 0x18
// 006aae92  8bc8                 mov ecx, eax
// 006aae94  8bc7                 mov eax, edi
// 006aae96  5f                   pop edi
// 006aae97  5e                   pop esi
// 006aae98  2bc1                 sub eax, ecx
// 006aae9a  5b                   pop ebx
// 006aae9b  83c408               add esp, 8
// 006aae9e  c3                   ret 
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??$_Copy_backward_opt@PAUEdgeGroup@EdgeData@Ogre@@PAU123@@std@@YAPAUEdgeGroup@EdgeData@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
