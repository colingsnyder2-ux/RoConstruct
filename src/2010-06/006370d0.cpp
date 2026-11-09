// from server: 100% by auto
// roc 2010-06 006370d0  unit: RBX::Profiling::Profiler  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006370d0
//
// 006370d0  53                   push ebx
// 006370d1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 006370d5  55                   push ebp
// 006370d6  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 006370da  3beb                 cmp ebp, ebx
// 006370dc  7451                 je 0x63712f
// 006370de  56                   push esi
// 006370df  8b742418             mov esi, dword ptr [esp + 0x18]
// 006370e3  57                   push edi
// 006370e4  8b43f8               mov eax, dword ptr [ebx - 8]
// 006370e7  83eb08               sub ebx, 8
// 006370ea  83ee08               sub esi, 8
// 006370ed  8906                 mov dword ptr [esi], eax
// 006370ef  8b7b04               mov edi, dword ptr [ebx + 4]
// 006370f2  3b7e04               cmp edi, dword ptr [esi + 4]
// 006370f5  742d                 je 0x637124
// 006370f7  85ff                 test edi, edi
// 006370f9  740c                 je 0x637107
// 006370fb  8d4f08               lea ecx, [edi + 8]
// 006370fe  ba01000000           mov edx, 1
// 00637103  f00fc111             lock xadd dword ptr [ecx], edx
// 00637107  8b4e04               mov ecx, dword ptr [esi + 4]
// 0063710a  85c9                 test ecx, ecx
// 0063710c  7413                 je 0x637121
// 0063710e  8d4108               lea eax, [ecx + 8]
// 00637111  83caff               or edx, 0xffffffff
// 00637114  f00fc110             lock xadd dword ptr [eax], edx
// 00637118  7507                 jne 0x637121
// 0063711a  8b01                 mov eax, dword ptr [ecx]
// 0063711c  8b5008               mov edx, dword ptr [eax + 8]
// 0063711f  ffd2                 call edx
// 00637121  897e04               mov dword ptr [esi + 4], edi
// 00637124  3bdd                 cmp ebx, ebp
// 00637126  75bc                 jne 0x6370e4
// 00637128  5f                   pop edi
// 00637129  8bc6                 mov eax, esi
// 0063712b  5e                   pop esi
// 0063712c  5d                   pop ebp
// 0063712d  5b                   pop ebx
// 0063712e  c3                   ret 
// 0063712f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00637133  5d                   pop ebp
// 00637134  5b                   pop ebx
// 00637135  c3                   ret 
// library templates-boost-1_40_0/vector_wp.cpp (function ??$_Copy_backward_opt@PAV?$weak_ptr@UT@@@boost@@PAV12@Uforward_iterator_tag@std@@@std@@YAPAV?$weak_ptr@UT@@@boost@@PAV12@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 vector_wp.cpp
