// from server: 100% by auto
// roc 2009-12 006cd560  unit: G3D::VVector3::?$TypedPropertyDescriptor  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006cd560
//
// 006cd560  8b542408             mov edx, dword ptr [esp + 8]
// 006cd564  85d2                 test edx, edx
// 006cd566  7632                 jbe 0x6cd59a
// 006cd568  8b442404             mov eax, dword ptr [esp + 4]
// 006cd56c  56                   push esi
// 006cd56d  8b742410             mov esi, dword ptr [esp + 0x10]
// 006cd571  57                   push edi
// 006cd572  85c0                 test eax, eax
// 006cd574  741a                 je 0x6cd590
// 006cd576  8b0e                 mov ecx, dword ptr [esi]
// 006cd578  8908                 mov dword ptr [eax], ecx
// 006cd57a  8b4e04               mov ecx, dword ptr [esi + 4]
// 006cd57d  894804               mov dword ptr [eax + 4], ecx
// 006cd580  85c9                 test ecx, ecx
// 006cd582  740c                 je 0x6cd590
// 006cd584  83c108               add ecx, 8
// 006cd587  bf01000000           mov edi, 1
// 006cd58c  f00fc139             lock xadd dword ptr [ecx], edi
// 006cd590  4a                   dec edx
// 006cd591  83c008               add eax, 8
// 006cd594  85d2                 test edx, edx
// 006cd596  77da                 ja 0x6cd572
// 006cd598  5f                   pop edi
// 006cd599  5e                   pop esi
// 006cd59a  c3                   ret 
// library templates-boost-1_34_1/vector_wp.cpp (function ??$_Uninit_fill_n@PAV?$weak_ptr@UT@@@boost@@IV12@V?$allocator@V?$weak_ptr@UT@@@boost@@@std@@@std@@YAXPAV?$weak_ptr@UT@@@boost@@IABV12@AAV?$allocator@V?$weak_ptr@UT@@@boost@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 vector_wp.cpp
