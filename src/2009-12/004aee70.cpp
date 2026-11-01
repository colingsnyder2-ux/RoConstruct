// from server: 100% by auto
// roc 2009-12 004aee70  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004aee70
//
// 004aee70  83ec08               sub esp, 8
// 004aee73  8b542414             mov edx, dword ptr [esp + 0x14]
// 004aee77  53                   push ebx
// 004aee78  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004aee7c  56                   push esi
// 004aee7d  8b742418             mov esi, dword ptr [esp + 0x18]
// 004aee81  57                   push edi
// 004aee82  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004aee86  32c0                 xor al, al
// 004aee88  88442410             mov byte ptr [esp + 0x10], al
// 004aee8c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004aee90  8844240c             mov byte ptr [esp + 0xc], al
// 004aee94  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004aee98  50                   push eax
// 004aee99  51                   push ecx
// 004aee9a  52                   push edx
// 004aee9b  57                   push edi
// 004aee9c  56                   push esi
// 004aee9d  53                   push ebx
// 004aee9e  e81dfdffff           call 0x4aebc0
// 004aeea3  2bf3                 sub esi, ebx
// 004aeea5  b8310cc330           mov eax, 0x30c30c31
// 004aeeaa  f7ee                 imul esi
// 004aeeac  c1fa04               sar edx, 4
// 004aeeaf  8bc2                 mov eax, edx
// 004aeeb1  c1e81f               shr eax, 0x1f
// 004aeeb4  03c2                 add eax, edx
// 004aeeb6  6bc054               imul eax, eax, 0x54
// 004aeeb9  83c418               add esp, 0x18
// 004aeebc  03c7                 add eax, edi
// 004aeebe  5f                   pop edi
// 004aeebf  5e                   pop esi
// 004aeec0  5b                   pop ebx
// 004aeec1  83c408               add esp, 8
// 004aeec4  c3                   ret 
// library boost-1.40.0/libs\program_options\src\cmdline.cpp (function ??$_Copy_opt@PAV?$basic_option@D@program_options@boost@@PAV123@@std@@YAPAV?$basic_option@D@program_options@boost@@PAV123@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/program_options/src/cmdline.cpp
