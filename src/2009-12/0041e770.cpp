// from server: 100% by auto
// roc 2009-12 0041e770  unit: CSelectionTreeCtrl  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041e770
//
// 0041e770  53                   push ebx
// 0041e771  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0041e775  807b1500             cmp byte ptr [ebx + 0x15], 0
// 0041e779  55                   push ebp
// 0041e77a  56                   push esi
// 0041e77b  8be9                 mov ebp, ecx
// 0041e77d  8bf3                 mov esi, ebx
// 0041e77f  7551                 jne 0x41e7d2
// 0041e781  57                   push edi
// 0041e782  8b4608               mov eax, dword ptr [esi + 8]
// 0041e785  50                   push eax
// 0041e786  8bcd                 mov ecx, ebp
// 0041e788  e8e3ffffff           call 0x41e770
// 0041e78d  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 0041e790  8b36                 mov esi, dword ptr [esi]
// 0041e792  85ff                 test edi, edi
// 0041e794  742a                 je 0x41e7c0
// 0041e796  8d4f04               lea ecx, [edi + 4]
// 0041e799  83caff               or edx, 0xffffffff
// 0041e79c  f00fc111             lock xadd dword ptr [ecx], edx
// 0041e7a0  751e                 jne 0x41e7c0
// 0041e7a2  8b07                 mov eax, dword ptr [edi]
// 0041e7a4  8b5004               mov edx, dword ptr [eax + 4]
// 0041e7a7  8bcf                 mov ecx, edi
// 0041e7a9  ffd2                 call edx
// 0041e7ab  8d4708               lea eax, [edi + 8]
// 0041e7ae  83c9ff               or ecx, 0xffffffff
// 0041e7b1  f00fc108             lock xadd dword ptr [eax], ecx
// 0041e7b5  7509                 jne 0x41e7c0
// 0041e7b7  8b17                 mov edx, dword ptr [edi]
// 0041e7b9  8b4208               mov eax, dword ptr [edx + 8]
// 0041e7bc  8bcf                 mov ecx, edi
// 0041e7be  ffd0                 call eax
// 0041e7c0  53                   push ebx
// 0041e7c1  e894503d00           call 0x7f385a
// 0041e7c6  83c404               add esp, 4
// 0041e7c9  807e1500             cmp byte ptr [esi + 0x15], 0
// 0041e7cd  8bde                 mov ebx, esi
// 0041e7cf  74b1                 je 0x41e782
// 0041e7d1  5f                   pop edi
// 0041e7d2  5e                   pop esi
// 0041e7d3  5d                   pop ebp
// 0041e7d4  5b                   pop ebx
// 0041e7d5  c20400               ret 4
// library templates-boost-1_34_1/set_sp.cpp (function ?_Erase@?$_Tree@V?$_Tset_traits@V?$shared_ptr@UT@@@boost@@U?$less@V?$shared_ptr@UT@@@boost@@@std@@V?$allocator@V?$shared_ptr@UT@@@boost@@@4@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$shared_ptr@UT@@@boost@@U?$less@V?$shared_ptr@UT@@@boost@@@std@@V?$allocator@V?$shared_ptr@UT@@@boost@@@4@$0A@@std@@@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 set_sp.cpp
