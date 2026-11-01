// from server: 100% by auto
// roc 2009-12 0057cdc0  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057cdc0
//
// 0057cdc0  8b442404             mov eax, dword ptr [esp + 4]
// 0057cdc4  57                   push edi
// 0057cdc5  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0057cdc9  3bc7                 cmp eax, edi
// 0057cdcb  7423                 je 0x57cdf0
// 0057cdcd  56                   push esi
// 0057cdce  8b742414             mov esi, dword ptr [esp + 0x14]
// 0057cdd2  8b0e                 mov ecx, dword ptr [esi]
// 0057cdd4  8b5604               mov edx, dword ptr [esi + 4]
// 0057cdd7  85c9                 test ecx, ecx
// 0057cdd9  7404                 je 0x57cddf
// 0057cddb  8b09                 mov ecx, dword ptr [ecx]
// 0057cddd  eb02                 jmp 0x57cde1
// 0057cddf  33c9                 xor ecx, ecx
// 0057cde1  8b09                 mov ecx, dword ptr [ecx]
// 0057cde3  8908                 mov dword ptr [eax], ecx
// 0057cde5  895004               mov dword ptr [eax + 4], edx
// 0057cde8  83c008               add eax, 8
// 0057cdeb  3bc7                 cmp eax, edi
// 0057cded  75e3                 jne 0x57cdd2
// 0057cdef  5e                   pop esi
// 0057cdf0  5f                   pop edi
// 0057cdf1  c3                   ret 
// library ogre-1.7.0/OgreMesh.cpp (function ??$_Fill@PAU_List_position@?$_Hash@V?$_Hmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@GV?$hash_compare@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@stdext@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@@2@$0A@@stdext@@@stdext@@V?$_Iterator@$00@?$list@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@@2@@std@@@std@@YAXPAU_List_position@?$_Hash@V?$_Hmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@GV?$hash_compare@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@stdext@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@@2@$0A@@stdext@@@stdext@@0ABV?$_Iterator@$00@?$list@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@@2@@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMesh.cpp
