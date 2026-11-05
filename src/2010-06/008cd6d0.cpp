// from server: 100% by auto
// roc 2010-06 008cd6d0  unit: Ogre::RbxMeshLoader  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008cd6d0
//
// 008cd6d0  83ec08               sub esp, 8
// 008cd6d3  8b542414             mov edx, dword ptr [esp + 0x14]
// 008cd6d7  53                   push ebx
// 008cd6d8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008cd6dc  56                   push esi
// 008cd6dd  8b742418             mov esi, dword ptr [esp + 0x18]
// 008cd6e1  57                   push edi
// 008cd6e2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008cd6e6  32c0                 xor al, al
// 008cd6e8  88442410             mov byte ptr [esp + 0x10], al
// 008cd6ec  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008cd6f0  8844240c             mov byte ptr [esp + 0xc], al
// 008cd6f4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008cd6f8  50                   push eax
// 008cd6f9  51                   push ecx
// 008cd6fa  52                   push edx
// 008cd6fb  57                   push edi
// 008cd6fc  56                   push esi
// 008cd6fd  53                   push ebx
// 008cd6fe  e8ddf0ffff           call 0x8cc7e0
// 008cd703  2bf3                 sub esi, ebx
// 008cd705  83c418               add esp, 0x18
// 008cd708  c1fe05               sar esi, 5
// 008cd70b  c1e605               shl esi, 5
// 008cd70e  8bc7                 mov eax, edi
// 008cd710  5f                   pop edi
// 008cd711  2bc6                 sub eax, esi
// 008cd713  5e                   pop esi
// 008cd714  5b                   pop ebx
// 008cd715  83c408               add esp, 8
// 008cd718  c3                   ret 
// library boost-1.40.0/libs\program_options\src\cmdline.cpp (function ??$_Copy_backward_opt@PAV?$function1@V?$vector@V?$basic_option@D@program_options@boost@@V?$allocator@V?$basic_option@D@program_options@boost@@@std@@@std@@AAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@boost@@PAV12@@std@@YAPAV?$function1@V?$vector@V?$basic_option@D@program_options@boost@@V?$allocator@V?$basic_option@D@program_options@boost@@@std@@@std@@AAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@boost@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/program_options/src/cmdline.cpp
