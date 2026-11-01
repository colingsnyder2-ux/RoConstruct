// from server: 100% by auto
// roc 2009-12 00669650  unit: RBX::VInstance::?$NonFactoryProduct  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00669650
//
// 00669650  53                   push ebx
// 00669651  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00669655  807b1900             cmp byte ptr [ebx + 0x19], 0
// 00669659  55                   push ebp
// 0066965a  56                   push esi
// 0066965b  8be9                 mov ebp, ecx
// 0066965d  8bf3                 mov esi, ebx
// 0066965f  7551                 jne 0x6696b2
// 00669661  57                   push edi
// 00669662  8b4608               mov eax, dword ptr [esi + 8]
// 00669665  50                   push eax
// 00669666  8bcd                 mov ecx, ebp
// 00669668  e8e3ffffff           call 0x669650
// 0066966d  8b7b14               mov edi, dword ptr [ebx + 0x14]
// 00669670  8b36                 mov esi, dword ptr [esi]
// 00669672  85ff                 test edi, edi
// 00669674  742a                 je 0x6696a0
// 00669676  8d4f04               lea ecx, [edi + 4]
// 00669679  83caff               or edx, 0xffffffff
// 0066967c  f00fc111             lock xadd dword ptr [ecx], edx
// 00669680  751e                 jne 0x6696a0
// 00669682  8b07                 mov eax, dword ptr [edi]
// 00669684  8b5004               mov edx, dword ptr [eax + 4]
// 00669687  8bcf                 mov ecx, edi
// 00669689  ffd2                 call edx
// 0066968b  8d4708               lea eax, [edi + 8]
// 0066968e  83c9ff               or ecx, 0xffffffff
// 00669691  f00fc108             lock xadd dword ptr [eax], ecx
// 00669695  7509                 jne 0x6696a0
// 00669697  8b17                 mov edx, dword ptr [edi]
// 00669699  8b4208               mov eax, dword ptr [edx + 8]
// 0066969c  8bcf                 mov ecx, edi
// 0066969e  ffd0                 call eax
// 006696a0  53                   push ebx
// 006696a1  e8b4a11800           call 0x7f385a
// 006696a6  83c404               add esp, 4
// 006696a9  807e1900             cmp byte ptr [esi + 0x19], 0
// 006696ad  8bde                 mov ebx, esi
// 006696af  74b1                 je 0x669662
// 006696b1  5f                   pop edi
// 006696b2  5e                   pop esi
// 006696b3  5d                   pop ebp
// 006696b4  5b                   pop ebx
// 006696b5  c20400               ret 4
// library templates-boost-1_34_1/map_int_sp.cpp (function ?_Erase@?$_Tree@V?$_Tmap_traits@HV?$shared_ptr@UT@@@boost@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$shared_ptr@UT@@@boost@@@std@@@4@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$shared_ptr@UT@@@boost@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$shared_ptr@UT@@@boost@@@std@@@4@$0A@@std@@@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 map_int_sp.cpp
