// from server: 100% by auto
// roc 2009-12 006f5fb0  unit: G3D::VRay::?$TypedPropertyDescriptor  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006f5fb0
//
// 006f5fb0  53                   push ebx
// 006f5fb1  56                   push esi
// 006f5fb2  57                   push edi
// 006f5fb3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006f5fb7  807f1500             cmp byte ptr [edi + 0x15], 0
// 006f5fbb  8bd9                 mov ebx, ecx
// 006f5fbd  8bf7                 mov esi, edi
// 006f5fbf  7538                 jne 0x6f5ff9
// 006f5fc1  8b4608               mov eax, dword ptr [esi + 8]
// 006f5fc4  50                   push eax
// 006f5fc5  8bcb                 mov ecx, ebx
// 006f5fc7  e8e4ffffff           call 0x6f5fb0
// 006f5fcc  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 006f5fcf  8b36                 mov esi, dword ptr [esi]
// 006f5fd1  85c9                 test ecx, ecx
// 006f5fd3  7413                 je 0x6f5fe8
// 006f5fd5  8d5108               lea edx, [ecx + 8]
// 006f5fd8  83c8ff               or eax, 0xffffffff
// 006f5fdb  f00fc102             lock xadd dword ptr [edx], eax
// 006f5fdf  7507                 jne 0x6f5fe8
// 006f5fe1  8b11                 mov edx, dword ptr [ecx]
// 006f5fe3  8b4208               mov eax, dword ptr [edx + 8]
// 006f5fe6  ffd0                 call eax
// 006f5fe8  57                   push edi
// 006f5fe9  e86cd80f00           call 0x7f385a
// 006f5fee  83c404               add esp, 4
// 006f5ff1  807e1500             cmp byte ptr [esi + 0x15], 0
// 006f5ff5  8bfe                 mov edi, esi
// 006f5ff7  74c8                 je 0x6f5fc1
// 006f5ff9  5f                   pop edi
// 006f5ffa  5e                   pop esi
// 006f5ffb  5b                   pop ebx
// 006f5ffc  c20400               ret 4
// library templates-boost-1_34_1/set_wp.cpp (function ?_Erase@?$_Tree@V?$_Tset_traits@V?$weak_ptr@UT@@@boost@@U?$less@V?$weak_ptr@UT@@@boost@@@std@@V?$allocator@V?$weak_ptr@UT@@@boost@@@4@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$weak_ptr@UT@@@boost@@U?$less@V?$weak_ptr@UT@@@boost@@@std@@V?$allocator@V?$weak_ptr@UT@@@boost@@@4@$0A@@std@@@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 set_wp.cpp
