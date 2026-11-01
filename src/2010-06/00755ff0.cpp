// from server: 100% by auto
// roc 2010-06 00755ff0  unit: RBX::Block  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00755ff0
//
// 00755ff0  55                   push ebp
// 00755ff1  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00755ff5  57                   push edi
// 00755ff6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00755ffa  3bfd                 cmp edi, ebp
// 00755ffc  7436                 je 0x756034
// 00755ffe  53                   push ebx
// 00755fff  56                   push esi
// 00756000  8d771c               lea esi, [edi + 0x1c]
// 00756003  33db                 xor ebx, ebx
// 00756005  8b06                 mov eax, dword ptr [esi]
// 00756007  3bc3                 cmp eax, ebx
// 00756009  7409                 je 0x756014
// 0075600b  50                   push eax
// 0075600c  e889190500           call 0x7a799a
// 00756011  83c404               add esp, 4
// 00756014  8b46f4               mov eax, dword ptr [esi - 0xc]
// 00756017  50                   push eax
// 00756018  891e                 mov dword ptr [esi], ebx
// 0075601a  895e04               mov dword ptr [esi + 4], ebx
// 0075601d  895e08               mov dword ptr [esi + 8], ebx
// 00756020  e875190500           call 0x7a799a
// 00756025  83c728               add edi, 0x28
// 00756028  83c404               add esp, 4
// 0075602b  83c628               add esi, 0x28
// 0075602e  3bfd                 cmp edi, ebp
// 00756030  75d3                 jne 0x756005
// 00756032  5e                   pop esi
// 00756033  5b                   pop ebx
// 00756034  5f                   pop edi
// 00756035  5d                   pop ebp
// 00756036  c3                   ret 
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??$_Destroy_range@V?$allocator@UEdgeGroup@EdgeData@Ogre@@@std@@@std@@YAXPAUEdgeGroup@EdgeData@Ogre@@0AAV?$allocator@UEdgeGroup@EdgeData@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
