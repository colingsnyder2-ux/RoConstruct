// from server: 100% by auto
// roc 2009-06 0048c5c0  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048c5c0
//
// 0048c5c0  83ec08               sub esp, 8
// 0048c5c3  8b542414             mov edx, dword ptr [esp + 0x14]
// 0048c5c7  53                   push ebx
// 0048c5c8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0048c5cc  56                   push esi
// 0048c5cd  8b742418             mov esi, dword ptr [esp + 0x18]
// 0048c5d1  57                   push edi
// 0048c5d2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0048c5d6  32c0                 xor al, al
// 0048c5d8  88442410             mov byte ptr [esp + 0x10], al
// 0048c5dc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0048c5e0  8844240c             mov byte ptr [esp + 0xc], al
// 0048c5e4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0048c5e8  50                   push eax
// 0048c5e9  51                   push ecx
// 0048c5ea  52                   push edx
// 0048c5eb  57                   push edi
// 0048c5ec  56                   push esi
// 0048c5ed  53                   push ebx
// 0048c5ee  e8ddf3ffff           call 0x48b9d0
// 0048c5f3  2bf3                 sub esi, ebx
// 0048c5f5  83c418               add esp, 0x18
// 0048c5f8  c1fe05               sar esi, 5
// 0048c5fb  c1e605               shl esi, 5
// 0048c5fe  8bc7                 mov eax, edi
// 0048c600  5f                   pop edi
// 0048c601  2bc6                 sub eax, esi
// 0048c603  5e                   pop esi
// 0048c604  5b                   pop ebx
// 0048c605  83c408               add esp, 8
// 0048c608  c3                   ret 
// library boost-1.40.0/libs\program_options\src\cmdline.cpp (function ??$_Copy_backward_opt@PAV?$function1@V?$vector@V?$basic_option@D@program_options@boost@@V?$allocator@V?$basic_option@D@program_options@boost@@@std@@@std@@AAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@boost@@PAV12@@std@@YAPAV?$function1@V?$vector@V?$basic_option@D@program_options@boost@@V?$allocator@V?$basic_option@D@program_options@boost@@@std@@@std@@AAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@boost@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/program_options/src/cmdline.cpp
