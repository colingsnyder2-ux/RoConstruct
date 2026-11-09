// from server: 100% by auto
// roc 2010-06 007638f0  unit: RBX::Assembly  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007638f0
//
// 007638f0  55                   push ebp
// 007638f1  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007638f5  56                   push esi
// 007638f6  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007638fa  3bf5                 cmp esi, ebp
// 007638fc  7448                 je 0x763946
// 007638fe  53                   push ebx
// 007638ff  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00763903  57                   push edi
// 00763904  8b03                 mov eax, dword ptr [ebx]
// 00763906  8906                 mov dword ptr [esi], eax
// 00763908  8b7b04               mov edi, dword ptr [ebx + 4]
// 0076390b  3b7e04               cmp edi, dword ptr [esi + 4]
// 0076390e  742d                 je 0x76393d
// 00763910  85ff                 test edi, edi
// 00763912  740c                 je 0x763920
// 00763914  8d4f08               lea ecx, [edi + 8]
// 00763917  ba01000000           mov edx, 1
// 0076391c  f00fc111             lock xadd dword ptr [ecx], edx
// 00763920  8b4e04               mov ecx, dword ptr [esi + 4]
// 00763923  85c9                 test ecx, ecx
// 00763925  7413                 je 0x76393a
// 00763927  8d4108               lea eax, [ecx + 8]
// 0076392a  83caff               or edx, 0xffffffff
// 0076392d  f00fc110             lock xadd dword ptr [eax], edx
// 00763931  7507                 jne 0x76393a
// 00763933  8b01                 mov eax, dword ptr [ecx]
// 00763935  8b5008               mov edx, dword ptr [eax + 8]
// 00763938  ffd2                 call edx
// 0076393a  897e04               mov dword ptr [esi + 4], edi
// 0076393d  83c608               add esi, 8
// 00763940  3bf5                 cmp esi, ebp
// 00763942  75c0                 jne 0x763904
// 00763944  5f                   pop edi
// 00763945  5b                   pop ebx
// 00763946  5e                   pop esi
// 00763947  5d                   pop ebp
// 00763948  c3                   ret 
// library templates-boost-1_40_0/vector_wp.cpp (function ??$_Fill@PAV?$weak_ptr@UT@@@boost@@V12@@std@@YAXPAV?$weak_ptr@UT@@@boost@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 vector_wp.cpp
