// from server: 100% by auto
// roc 2009-06 0065c870  unit: RBX::PartInstance  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0065c870
//
// 0065c870  55                   push ebp
// 0065c871  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0065c875  56                   push esi
// 0065c876  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0065c87a  3bf5                 cmp esi, ebp
// 0065c87c  7448                 je 0x65c8c6
// 0065c87e  53                   push ebx
// 0065c87f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0065c883  57                   push edi
// 0065c884  8b03                 mov eax, dword ptr [ebx]
// 0065c886  8906                 mov dword ptr [esi], eax
// 0065c888  8b7b04               mov edi, dword ptr [ebx + 4]
// 0065c88b  3b7e04               cmp edi, dword ptr [esi + 4]
// 0065c88e  742d                 je 0x65c8bd
// 0065c890  85ff                 test edi, edi
// 0065c892  740c                 je 0x65c8a0
// 0065c894  8d4f08               lea ecx, [edi + 8]
// 0065c897  ba01000000           mov edx, 1
// 0065c89c  f00fc111             lock xadd dword ptr [ecx], edx
// 0065c8a0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0065c8a3  85c9                 test ecx, ecx
// 0065c8a5  7413                 je 0x65c8ba
// 0065c8a7  8d4108               lea eax, [ecx + 8]
// 0065c8aa  83caff               or edx, 0xffffffff
// 0065c8ad  f00fc110             lock xadd dword ptr [eax], edx
// 0065c8b1  7507                 jne 0x65c8ba
// 0065c8b3  8b01                 mov eax, dword ptr [ecx]
// 0065c8b5  8b5008               mov edx, dword ptr [eax + 8]
// 0065c8b8  ffd2                 call edx
// 0065c8ba  897e04               mov dword ptr [esi + 4], edi
// 0065c8bd  83c608               add esi, 8
// 0065c8c0  3bf5                 cmp esi, ebp
// 0065c8c2  75c0                 jne 0x65c884
// 0065c8c4  5f                   pop edi
// 0065c8c5  5b                   pop ebx
// 0065c8c6  5e                   pop esi
// 0065c8c7  5d                   pop ebp
// 0065c8c8  c3                   ret 
// library templates-boost-1_40_0/vector_wp.cpp (function ??$_Fill@PAV?$weak_ptr@UT@@@boost@@V12@@std@@YAXPAV?$weak_ptr@UT@@@boost@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 vector_wp.cpp
