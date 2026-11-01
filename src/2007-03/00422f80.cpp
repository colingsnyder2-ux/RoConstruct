// from server: 100% by auto
// roc 2007-03 00422f80  unit: seg_00420000  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00422f80
//
// 00422f80  53                   push ebx
// 00422f81  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00422f85  807b1500             cmp byte ptr [ebx + 0x15], 0
// 00422f89  55                   push ebp
// 00422f8a  56                   push esi
// 00422f8b  8be9                 mov ebp, ecx
// 00422f8d  8bf3                 mov esi, ebx
// 00422f8f  7551                 jne 0x422fe2
// 00422f91  57                   push edi
// 00422f92  8b4608               mov eax, dword ptr [esi + 8]
// 00422f95  50                   push eax
// 00422f96  8bcd                 mov ecx, ebp
// 00422f98  e8e3ffffff           call 0x422f80
// 00422f9d  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 00422fa0  85ff                 test edi, edi
// 00422fa2  8b36                 mov esi, dword ptr [esi]
// 00422fa4  742a                 je 0x422fd0
// 00422fa6  8d4f04               lea ecx, [edi + 4]
// 00422fa9  83caff               or edx, 0xffffffff
// 00422fac  f00fc111             lock xadd dword ptr [ecx], edx
// 00422fb0  751e                 jne 0x422fd0
// 00422fb2  8b07                 mov eax, dword ptr [edi]
// 00422fb4  8b5004               mov edx, dword ptr [eax + 4]
// 00422fb7  8bcf                 mov ecx, edi
// 00422fb9  ffd2                 call edx
// 00422fbb  8d4708               lea eax, [edi + 8]
// 00422fbe  83c9ff               or ecx, 0xffffffff
// 00422fc1  f00fc108             lock xadd dword ptr [eax], ecx
// 00422fc5  7509                 jne 0x422fd0
// 00422fc7  8b17                 mov edx, dword ptr [edi]
// 00422fc9  8b4208               mov eax, dword ptr [edx + 8]
// 00422fcc  8bcf                 mov ecx, edi
// 00422fce  ffd0                 call eax
// 00422fd0  53                   push ebx
// 00422fd1  e81ab11f00           call 0x61e0f0
// 00422fd6  83c404               add esp, 4
// 00422fd9  807e1500             cmp byte ptr [esi + 0x15], 0
// 00422fdd  8bde                 mov ebx, esi
// 00422fdf  74b1                 je 0x422f92
// 00422fe1  5f                   pop edi
// 00422fe2  5e                   pop esi
// 00422fe3  5d                   pop ebp
// 00422fe4  5b                   pop ebx
// 00422fe5  c20400               ret 4
// library templates-boost-1_34_1/set_sp.cpp (function ?_Erase@?$_Tree@V?$_Tset_traits@V?$shared_ptr@UT@@@boost@@U?$less@V?$shared_ptr@UT@@@boost@@@std@@V?$allocator@V?$shared_ptr@UT@@@boost@@@4@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$shared_ptr@UT@@@boost@@U?$less@V?$shared_ptr@UT@@@boost@@@std@@V?$allocator@V?$shared_ptr@UT@@@boost@@@4@$0A@@std@@@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 set_sp.cpp
