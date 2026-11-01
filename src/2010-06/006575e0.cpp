// from server: 100% by auto
// roc 2010-06 006575e0  unit: RBX::Network::P8Player::?$GetSetImpl  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006575e0
//
// 006575e0  83ec08               sub esp, 8
// 006575e3  8b542414             mov edx, dword ptr [esp + 0x14]
// 006575e7  53                   push ebx
// 006575e8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 006575ec  56                   push esi
// 006575ed  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 006575f1  57                   push edi
// 006575f2  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 006575f6  32c0                 xor al, al
// 006575f8  88442410             mov byte ptr [esp + 0x10], al
// 006575fc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00657600  8844240c             mov byte ptr [esp + 0xc], al
// 00657604  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00657608  50                   push eax
// 00657609  51                   push ecx
// 0065760a  52                   push edx
// 0065760b  56                   push esi
// 0065760c  57                   push edi
// 0065760d  53                   push ebx
// 0065760e  e84dfaffff           call 0x657060
// 00657613  8bc7                 mov eax, edi
// 00657615  2bc3                 sub eax, ebx
// 00657617  83c418               add esp, 0x18
// 0065761a  c1f805               sar eax, 5
// 0065761d  c1e005               shl eax, 5
// 00657620  5f                   pop edi
// 00657621  03c6                 add eax, esi
// 00657623  5e                   pop esi
// 00657624  5b                   pop ebx
// 00657625  83c408               add esp, 8
// 00657628  c3                   ret 
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??$_Copy_opt@PAUEdgeGroup@EdgeData@Ogre@@PAU123@@std@@YAPAUEdgeGroup@EdgeData@Ogre@@PAU123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
