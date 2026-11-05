// from server: 100% by auto
// roc 2010-06 008f5ae0  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f5ae0
//
// 008f5ae0  83ec08               sub esp, 8
// 008f5ae3  8b542414             mov edx, dword ptr [esp + 0x14]
// 008f5ae7  53                   push ebx
// 008f5ae8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008f5aec  56                   push esi
// 008f5aed  8b742418             mov esi, dword ptr [esp + 0x18]
// 008f5af1  57                   push edi
// 008f5af2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008f5af6  32c0                 xor al, al
// 008f5af8  88442410             mov byte ptr [esp + 0x10], al
// 008f5afc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008f5b00  8844240c             mov byte ptr [esp + 0xc], al
// 008f5b04  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008f5b08  50                   push eax
// 008f5b09  51                   push ecx
// 008f5b0a  52                   push edx
// 008f5b0b  57                   push edi
// 008f5b0c  56                   push esi
// 008f5b0d  53                   push ebx
// 008f5b0e  e8fdfeffff           call 0x8f5a10
// 008f5b13  2bf3                 sub esi, ebx
// 008f5b15  83c418               add esp, 0x18
// 008f5b18  c1fe05               sar esi, 5
// 008f5b1b  c1e605               shl esi, 5
// 008f5b1e  8bc7                 mov eax, edi
// 008f5b20  5f                   pop edi
// 008f5b21  2bc6                 sub eax, esi
// 008f5b23  5e                   pop esi
// 008f5b24  5b                   pop ebx
// 008f5b25  83c408               add esp, 8
// 008f5b28  c3                   ret 
// library boost-1.40.0/libs\program_options\src\cmdline.cpp (function ??$_Copy_backward_opt@PAV?$function1@V?$vector@V?$basic_option@D@program_options@boost@@V?$allocator@V?$basic_option@D@program_options@boost@@@std@@@std@@AAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@boost@@PAV12@@std@@YAPAV?$function1@V?$vector@V?$basic_option@D@program_options@boost@@V?$allocator@V?$basic_option@D@program_options@boost@@@std@@@std@@AAV?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@@boost@@PAV12@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 libs/program_options/src/cmdline.cpp
