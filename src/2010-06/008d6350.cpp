// from server: 100% by auto
// roc 2010-06 008d6350  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d6350
//
// 008d6350  83ec08               sub esp, 8
// 008d6353  8b542414             mov edx, dword ptr [esp + 0x14]
// 008d6357  53                   push ebx
// 008d6358  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008d635c  56                   push esi
// 008d635d  8b742418             mov esi, dword ptr [esp + 0x18]
// 008d6361  57                   push edi
// 008d6362  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008d6366  32c0                 xor al, al
// 008d6368  88442410             mov byte ptr [esp + 0x10], al
// 008d636c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008d6370  8844240c             mov byte ptr [esp + 0xc], al
// 008d6374  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008d6378  50                   push eax
// 008d6379  51                   push ecx
// 008d637a  52                   push edx
// 008d637b  57                   push edi
// 008d637c  56                   push esi
// 008d637d  53                   push ebx
// 008d637e  e89dfaffff           call 0x8d5e20
// 008d6383  2bf3                 sub esi, ebx
// 008d6385  b8310cc330           mov eax, 0x30c30c31
// 008d638a  f7ee                 imul esi
// 008d638c  c1fa04               sar edx, 4
// 008d638f  8bc2                 mov eax, edx
// 008d6391  c1e81f               shr eax, 0x1f
// 008d6394  03c2                 add eax, edx
// 008d6396  6bc054               imul eax, eax, 0x54
// 008d6399  83c418               add esp, 0x18
// 008d639c  03c7                 add eax, edi
// 008d639e  5f                   pop edi
// 008d639f  5e                   pop esi
// 008d63a0  5b                   pop ebx
// 008d63a1  83c408               add esp, 8
// 008d63a4  c3                   ret 
// library boost-1.40.0/libs\program_options\src\cmdline.cpp (function ??$_Copy_opt@PAV?$basic_option@D@program_options@boost@@PAV123@@std@@YAPAV?$basic_option@D@program_options@boost@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/program_options/src/cmdline.cpp
