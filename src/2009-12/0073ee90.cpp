// from server: 100% by auto
// roc 2009-12 0073ee90  unit: RBX::VInstance::V?$shared_ptr::V?$vector::V?$copy_on_write_ptr::?$sp_counted_impl_p  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0073ee90
//
// 0073ee90  53                   push ebx
// 0073ee91  56                   push esi
// 0073ee92  57                   push edi
// 0073ee93  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0073ee97  807f3100             cmp byte ptr [edi + 0x31], 0
// 0073ee9b  8bd9                 mov ebx, ecx
// 0073ee9d  8bf7                 mov esi, edi
// 0073ee9f  7526                 jne 0x73eec7
// 0073eea1  8b4608               mov eax, dword ptr [esi + 8]
// 0073eea4  50                   push eax
// 0073eea5  8bcb                 mov ecx, ebx
// 0073eea7  e8e4ffffff           call 0x73ee90
// 0073eeac  8b36                 mov esi, dword ptr [esi]
// 0073eeae  8d4f0c               lea ecx, [edi + 0xc]
// 0073eeb1  e80a84d3ff           call 0x4772c0
// 0073eeb6  57                   push edi
// 0073eeb7  e89e490b00           call 0x7f385a
// 0073eebc  83c404               add esp, 4
// 0073eebf  807e3100             cmp byte ptr [esi + 0x31], 0
// 0073eec3  8bfe                 mov edi, esi
// 0073eec5  74da                 je 0x73eea1
// 0073eec7  5f                   pop edi
// 0073eec8  5e                   pop esi
// 0073eec9  5b                   pop ebx
// 0073eeca  c20400               ret 4
// library templates-boost-1_34_1/map_str_sp.cpp (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$shared_ptr@UT@@@boost@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$shared_ptr@UT@@@boost@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$shared_ptr@UT@@@boost@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$shared_ptr@UT@@@boost@@@std@@@2@$0A@@std@@@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 map_str_sp.cpp
