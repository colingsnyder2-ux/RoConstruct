// from server: 100% by auto
// roc 2010-06 009616b0  unit: RBX::SceneUpdater  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009616b0
//
// 009616b0  8b442404             mov eax, dword ptr [esp + 4]
// 009616b4  57                   push edi
// 009616b5  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 009616b9  3bc7                 cmp eax, edi
// 009616bb  7423                 je 0x9616e0
// 009616bd  56                   push esi
// 009616be  8b742414             mov esi, dword ptr [esp + 0x14]
// 009616c2  8b0e                 mov ecx, dword ptr [esi]
// 009616c4  8b5604               mov edx, dword ptr [esi + 4]
// 009616c7  85c9                 test ecx, ecx
// 009616c9  7404                 je 0x9616cf
// 009616cb  8b09                 mov ecx, dword ptr [ecx]
// 009616cd  eb02                 jmp 0x9616d1
// 009616cf  33c9                 xor ecx, ecx
// 009616d1  8b09                 mov ecx, dword ptr [ecx]
// 009616d3  8908                 mov dword ptr [eax], ecx
// 009616d5  895004               mov dword ptr [eax + 4], edx
// 009616d8  83c008               add eax, 8
// 009616db  3bc7                 cmp eax, edi
// 009616dd  75e3                 jne 0x9616c2
// 009616df  5e                   pop esi
// 009616e0  5f                   pop edi
// 009616e1  c3                   ret 
// library ogre-1.7.0/OgreMesh.cpp (function ??$_Fill@PAU_List_position@?$_Hash@V?$_Hmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@GV?$hash_compare@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@stdext@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@@2@$0A@@stdext@@@stdext@@V?$_Iterator@$00@?$list@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@@2@@std@@@std@@YAXPAU_List_position@?$_Hash@V?$_Hmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@GV?$hash_compare@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@stdext@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@@2@$0A@@stdext@@@stdext@@0ABV?$_Iterator@$00@?$list@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@@2@@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMesh.cpp
