// from server: 100% by auto
// roc 2009-12 006cc050  unit: RBX::PartInstance  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006cc050
//
// 006cc050  55                   push ebp
// 006cc051  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 006cc055  56                   push esi
// 006cc056  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006cc05a  3bf5                 cmp esi, ebp
// 006cc05c  7448                 je 0x6cc0a6
// 006cc05e  53                   push ebx
// 006cc05f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006cc063  57                   push edi
// 006cc064  8b03                 mov eax, dword ptr [ebx]
// 006cc066  8906                 mov dword ptr [esi], eax
// 006cc068  8b7b04               mov edi, dword ptr [ebx + 4]
// 006cc06b  3b7e04               cmp edi, dword ptr [esi + 4]
// 006cc06e  742d                 je 0x6cc09d
// 006cc070  85ff                 test edi, edi
// 006cc072  740c                 je 0x6cc080
// 006cc074  8d4f08               lea ecx, [edi + 8]
// 006cc077  ba01000000           mov edx, 1
// 006cc07c  f00fc111             lock xadd dword ptr [ecx], edx
// 006cc080  8b4e04               mov ecx, dword ptr [esi + 4]
// 006cc083  85c9                 test ecx, ecx
// 006cc085  7413                 je 0x6cc09a
// 006cc087  8d4108               lea eax, [ecx + 8]
// 006cc08a  83caff               or edx, 0xffffffff
// 006cc08d  f00fc110             lock xadd dword ptr [eax], edx
// 006cc091  7507                 jne 0x6cc09a
// 006cc093  8b01                 mov eax, dword ptr [ecx]
// 006cc095  8b5008               mov edx, dword ptr [eax + 8]
// 006cc098  ffd2                 call edx
// 006cc09a  897e04               mov dword ptr [esi + 4], edi
// 006cc09d  83c608               add esi, 8
// 006cc0a0  3bf5                 cmp esi, ebp
// 006cc0a2  75c0                 jne 0x6cc064
// 006cc0a4  5f                   pop edi
// 006cc0a5  5b                   pop ebx
// 006cc0a6  5e                   pop esi
// 006cc0a7  5d                   pop ebp
// 006cc0a8  c3                   ret 
// library templates-boost-1_40_0/vector_wp.cpp (function ??$_Fill@PAV?$weak_ptr@UT@@@boost@@V12@@std@@YAXPAV?$weak_ptr@UT@@@boost@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 vector_wp.cpp
