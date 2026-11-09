// from server: 100% by auto
// roc 2012-06 00750d10  unit: RBX::PartInstance  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00750d10
//
// 00750d10  53                   push ebx
// 00750d11  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00750d15  55                   push ebp
// 00750d16  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00750d1a  3beb                 cmp ebp, ebx
// 00750d1c  7451                 je 0x750d6f
// 00750d1e  56                   push esi
// 00750d1f  8b742418             mov esi, dword ptr [esp + 0x18]
// 00750d23  57                   push edi
// 00750d24  8b43f8               mov eax, dword ptr [ebx - 8]
// 00750d27  83eb08               sub ebx, 8
// 00750d2a  83ee08               sub esi, 8
// 00750d2d  8906                 mov dword ptr [esi], eax
// 00750d2f  8b7b04               mov edi, dword ptr [ebx + 4]
// 00750d32  3b7e04               cmp edi, dword ptr [esi + 4]
// 00750d35  742d                 je 0x750d64
// 00750d37  85ff                 test edi, edi
// 00750d39  740c                 je 0x750d47
// 00750d3b  8d4f08               lea ecx, [edi + 8]
// 00750d3e  ba01000000           mov edx, 1
// 00750d43  f00fc111             lock xadd dword ptr [ecx], edx
// 00750d47  8b4e04               mov ecx, dword ptr [esi + 4]
// 00750d4a  85c9                 test ecx, ecx
// 00750d4c  7413                 je 0x750d61
// 00750d4e  8d4108               lea eax, [ecx + 8]
// 00750d51  83caff               or edx, 0xffffffff
// 00750d54  f00fc110             lock xadd dword ptr [eax], edx
// 00750d58  7507                 jne 0x750d61
// 00750d5a  8b01                 mov eax, dword ptr [ecx]
// 00750d5c  8b5008               mov edx, dword ptr [eax + 8]
// 00750d5f  ffd2                 call edx
// 00750d61  897e04               mov dword ptr [esi + 4], edi
// 00750d64  3bdd                 cmp ebx, ebp
// 00750d66  75bc                 jne 0x750d24
// 00750d68  5f                   pop edi
// 00750d69  8bc6                 mov eax, esi
// 00750d6b  5e                   pop esi
// 00750d6c  5d                   pop ebp
// 00750d6d  5b                   pop ebx
// 00750d6e  c3                   ret 
// 00750d6f  8b442414             mov eax, dword ptr [esp + 0x14]
// 00750d73  5d                   pop ebp
// 00750d74  5b                   pop ebx
// 00750d75  c3                   ret 
// library templates-boost-1_40_0/vector_wp.cpp (function ??$_Copy_backward_opt@PAV?$weak_ptr@UT@@@boost@@PAV12@Uforward_iterator_tag@std@@@std@@YAPAV?$weak_ptr@UT@@@boost@@PAV12@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 vector_wp.cpp
