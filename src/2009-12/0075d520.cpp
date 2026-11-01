// from server: 100% by auto
// roc 2009-12 0075d520  unit: RBX::VLuaDragger::?$FactoryProduct  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0075d520
//
// 0075d520  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0075d524  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0075d528  56                   push esi
// 0075d529  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0075d52d  3bce                 cmp ecx, esi
// 0075d52f  742a                 je 0x75d55b
// 0075d531  57                   push edi
// 0075d532  85c0                 test eax, eax
// 0075d534  741a                 je 0x75d550
// 0075d536  8b11                 mov edx, dword ptr [ecx]
// 0075d538  8910                 mov dword ptr [eax], edx
// 0075d53a  8b5104               mov edx, dword ptr [ecx + 4]
// 0075d53d  895004               mov dword ptr [eax + 4], edx
// 0075d540  85d2                 test edx, edx
// 0075d542  740c                 je 0x75d550
// 0075d544  83c208               add edx, 8
// 0075d547  bf01000000           mov edi, 1
// 0075d54c  f00fc13a             lock xadd dword ptr [edx], edi
// 0075d550  83c108               add ecx, 8
// 0075d553  83c008               add eax, 8
// 0075d556  3bce                 cmp ecx, esi
// 0075d558  75d8                 jne 0x75d532
// 0075d55a  5f                   pop edi
// 0075d55b  5e                   pop esi
// 0075d55c  c3                   ret 
// library templates-boost-1_34_1/vector_wp.cpp (function ??$_Uninit_copy@PBV?$weak_ptr@UT@@@boost@@PAV12@V?$allocator@V?$weak_ptr@UT@@@boost@@@std@@@std@@YAPAV?$weak_ptr@UT@@@boost@@PBV12@0PAV12@AAV?$allocator@V?$weak_ptr@UT@@@boost@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 vector_wp.cpp
