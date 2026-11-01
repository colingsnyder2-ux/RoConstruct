// from server: 100% by auto
// roc 2009-12 0073ccb0  unit: RBX::VUDim2::?$TypedPropertyDescriptor  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0073ccb0
//
// 0073ccb0  56                   push esi
// 0073ccb1  8b742408             mov esi, dword ptr [esp + 8]
// 0073ccb5  57                   push edi
// 0073ccb6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0073ccba  3bf7                 cmp esi, edi
// 0073ccbc  7423                 je 0x73cce1
// 0073ccbe  8bff                 mov edi, edi
// 0073ccc0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0073ccc3  85c9                 test ecx, ecx
// 0073ccc5  7413                 je 0x73ccda
// 0073ccc7  8d4108               lea eax, [ecx + 8]
// 0073ccca  83caff               or edx, 0xffffffff
// 0073cccd  f00fc110             lock xadd dword ptr [eax], edx
// 0073ccd1  7507                 jne 0x73ccda
// 0073ccd3  8b01                 mov eax, dword ptr [ecx]
// 0073ccd5  8b5008               mov edx, dword ptr [eax + 8]
// 0073ccd8  ffd2                 call edx
// 0073ccda  83c608               add esi, 8
// 0073ccdd  3bf7                 cmp esi, edi
// 0073ccdf  75df                 jne 0x73ccc0
// 0073cce1  5f                   pop edi
// 0073cce2  5e                   pop esi
// 0073cce3  c3                   ret 
// library templates-boost-1_34_1/vector_wp.cpp (function ??$_Destroy_range@V?$allocator@V?$weak_ptr@UT@@@boost@@@std@@@std@@YAXPAV?$weak_ptr@UT@@@boost@@0AAV?$allocator@V?$weak_ptr@UT@@@boost@@@0@U_Nonscalar_ptr_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 vector_wp.cpp
