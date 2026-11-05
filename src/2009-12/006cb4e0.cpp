// from server: 100% by auto
// roc 2009-12 006cb4e0  unit: RBX::Profiling::Profiler  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006cb4e0
//
// 006cb4e0  53                   push ebx
// 006cb4e1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 006cb4e5  55                   push ebp
// 006cb4e6  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 006cb4ea  3beb                 cmp ebp, ebx
// 006cb4ec  7451                 je 0x6cb53f
// 006cb4ee  56                   push esi
// 006cb4ef  8b742418             mov esi, dword ptr [esp + 0x18]
// 006cb4f3  57                   push edi
// 006cb4f4  8b43f8               mov eax, dword ptr [ebx - 8]
// 006cb4f7  83eb08               sub ebx, 8
// 006cb4fa  83ee08               sub esi, 8
// 006cb4fd  8906                 mov dword ptr [esi], eax
// 006cb4ff  8b7b04               mov edi, dword ptr [ebx + 4]
// 006cb502  3b7e04               cmp edi, dword ptr [esi + 4]
// 006cb505  742d                 je 0x6cb534
// 006cb507  85ff                 test edi, edi
// 006cb509  740c                 je 0x6cb517
// 006cb50b  8d4f08               lea ecx, [edi + 8]
// 006cb50e  ba01000000           mov edx, 1
// 006cb513  f00fc111             lock xadd dword ptr [ecx], edx
// 006cb517  8b4e04               mov ecx, dword ptr [esi + 4]
// 006cb51a  85c9                 test ecx, ecx
// 006cb51c  7413                 je 0x6cb531
// 006cb51e  8d4108               lea eax, [ecx + 8]
// 006cb521  83caff               or edx, 0xffffffff
// 006cb524  f00fc110             lock xadd dword ptr [eax], edx
// 006cb528  7507                 jne 0x6cb531
// 006cb52a  8b01                 mov eax, dword ptr [ecx]
// 006cb52c  8b5008               mov edx, dword ptr [eax + 8]
// 006cb52f  ffd2                 call edx
// 006cb531  897e04               mov dword ptr [esi + 4], edi
// 006cb534  3bdd                 cmp ebx, ebp
// 006cb536  75bc                 jne 0x6cb4f4
// 006cb538  5f                   pop edi
// 006cb539  8bc6                 mov eax, esi
// 006cb53b  5e                   pop esi
// 006cb53c  5d                   pop ebp
// 006cb53d  5b                   pop ebx
// 006cb53e  c3                   ret 
// 006cb53f  8b442414             mov eax, dword ptr [esp + 0x14]
// 006cb543  5d                   pop ebp
// 006cb544  5b                   pop ebx
// 006cb545  c3                   ret 
// library templates-boost-1_40_0/vector_wp.cpp (function ??$_Copy_backward_opt@PAV?$weak_ptr@UT@@@boost@@PAV12@Uforward_iterator_tag@std@@@std@@YAPAV?$weak_ptr@UT@@@boost@@PAV12@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 vector_wp.cpp
