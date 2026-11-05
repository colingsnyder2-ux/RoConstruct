// from server: 100% by auto
// roc 2011-06 007b6e30  unit: RBX::SpatialFilter  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007b6e30
//
// 007b6e30  53                   push ebx
// 007b6e31  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 007b6e35  55                   push ebp
// 007b6e36  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007b6e3a  3beb                 cmp ebp, ebx
// 007b6e3c  7451                 je 0x7b6e8f
// 007b6e3e  56                   push esi
// 007b6e3f  8b742418             mov esi, dword ptr [esp + 0x18]
// 007b6e43  57                   push edi
// 007b6e44  8b43f8               mov eax, dword ptr [ebx - 8]
// 007b6e47  83eb08               sub ebx, 8
// 007b6e4a  83ee08               sub esi, 8
// 007b6e4d  8906                 mov dword ptr [esi], eax
// 007b6e4f  8b7b04               mov edi, dword ptr [ebx + 4]
// 007b6e52  3b7e04               cmp edi, dword ptr [esi + 4]
// 007b6e55  742d                 je 0x7b6e84
// 007b6e57  85ff                 test edi, edi
// 007b6e59  740c                 je 0x7b6e67
// 007b6e5b  8d4f08               lea ecx, [edi + 8]
// 007b6e5e  ba01000000           mov edx, 1
// 007b6e63  f00fc111             lock xadd dword ptr [ecx], edx
// 007b6e67  8b4e04               mov ecx, dword ptr [esi + 4]
// 007b6e6a  85c9                 test ecx, ecx
// 007b6e6c  7413                 je 0x7b6e81
// 007b6e6e  8d4108               lea eax, [ecx + 8]
// 007b6e71  83caff               or edx, 0xffffffff
// 007b6e74  f00fc110             lock xadd dword ptr [eax], edx
// 007b6e78  7507                 jne 0x7b6e81
// 007b6e7a  8b01                 mov eax, dword ptr [ecx]
// 007b6e7c  8b5008               mov edx, dword ptr [eax + 8]
// 007b6e7f  ffd2                 call edx
// 007b6e81  897e04               mov dword ptr [esi + 4], edi
// 007b6e84  3bdd                 cmp ebx, ebp
// 007b6e86  75bc                 jne 0x7b6e44
// 007b6e88  5f                   pop edi
// 007b6e89  8bc6                 mov eax, esi
// 007b6e8b  5e                   pop esi
// 007b6e8c  5d                   pop ebp
// 007b6e8d  5b                   pop ebx
// 007b6e8e  c3                   ret 
// 007b6e8f  8b442414             mov eax, dword ptr [esp + 0x14]
// 007b6e93  5d                   pop ebp
// 007b6e94  5b                   pop ebx
// 007b6e95  c3                   ret 
// library templates-boost-1_40_0/vector_wp.cpp (function ??$_Copy_backward_opt@PAV?$weak_ptr@UT@@@boost@@PAV12@Uforward_iterator_tag@std@@@std@@YAPAV?$weak_ptr@UT@@@boost@@PAV12@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 vector_wp.cpp
