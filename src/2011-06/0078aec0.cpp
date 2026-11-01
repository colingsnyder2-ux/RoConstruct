// from server: 100% by auto
// roc 2011-06 0078aec0  unit: RBX::Block  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0078aec0
//
// 0078aec0  55                   push ebp
// 0078aec1  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0078aec5  57                   push edi
// 0078aec6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0078aeca  3bfd                 cmp edi, ebp
// 0078aecc  742a                 je 0x78aef8
// 0078aece  53                   push ebx
// 0078aecf  56                   push esi
// 0078aed0  8d7714               lea esi, [edi + 0x14]
// 0078aed3  33db                 xor ebx, ebx
// 0078aed5  8b06                 mov eax, dword ptr [esi]
// 0078aed7  3bc3                 cmp eax, ebx
// 0078aed9  7409                 je 0x78aee4
// 0078aedb  50                   push eax
// 0078aedc  e877f10700           call 0x80a058
// 0078aee1  83c404               add esp, 4
// 0078aee4  891e                 mov dword ptr [esi], ebx
// 0078aee6  895e04               mov dword ptr [esi + 4], ebx
// 0078aee9  895e08               mov dword ptr [esi + 8], ebx
// 0078aeec  83c720               add edi, 0x20
// 0078aeef  83c620               add esi, 0x20
// 0078aef2  3bfd                 cmp edi, ebp
// 0078aef4  75df                 jne 0x78aed5
// 0078aef6  5e                   pop esi
// 0078aef7  5b                   pop ebx
// 0078aef8  5f                   pop edi
// 0078aef9  5d                   pop ebp
// 0078aefa  c3                   ret 
// library ogre-1.7.0/OgreEdgeListBuilder.cpp (function ??$_Destroy_range@UEdgeGroup@EdgeData@Ogre@@V?$allocator@UEdgeGroup@EdgeData@Ogre@@@std@@@std@@YAXPAUEdgeGroup@EdgeData@Ogre@@0AAV?$allocator@UEdgeGroup@EdgeData@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreEdgeListBuilder.cpp
