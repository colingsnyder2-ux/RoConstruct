// from server: 100% by auto
// roc 2011-06 007b6fa0  unit: RBX::SpatialFilter  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007b6fa0
//
// 007b6fa0  55                   push ebp
// 007b6fa1  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007b6fa5  56                   push esi
// 007b6fa6  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007b6faa  3bf5                 cmp esi, ebp
// 007b6fac  7448                 je 0x7b6ff6
// 007b6fae  53                   push ebx
// 007b6faf  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007b6fb3  57                   push edi
// 007b6fb4  8b03                 mov eax, dword ptr [ebx]
// 007b6fb6  8906                 mov dword ptr [esi], eax
// 007b6fb8  8b7b04               mov edi, dword ptr [ebx + 4]
// 007b6fbb  3b7e04               cmp edi, dword ptr [esi + 4]
// 007b6fbe  742d                 je 0x7b6fed
// 007b6fc0  85ff                 test edi, edi
// 007b6fc2  740c                 je 0x7b6fd0
// 007b6fc4  8d4f08               lea ecx, [edi + 8]
// 007b6fc7  ba01000000           mov edx, 1
// 007b6fcc  f00fc111             lock xadd dword ptr [ecx], edx
// 007b6fd0  8b4e04               mov ecx, dword ptr [esi + 4]
// 007b6fd3  85c9                 test ecx, ecx
// 007b6fd5  7413                 je 0x7b6fea
// 007b6fd7  8d4108               lea eax, [ecx + 8]
// 007b6fda  83caff               or edx, 0xffffffff
// 007b6fdd  f00fc110             lock xadd dword ptr [eax], edx
// 007b6fe1  7507                 jne 0x7b6fea
// 007b6fe3  8b01                 mov eax, dword ptr [ecx]
// 007b6fe5  8b5008               mov edx, dword ptr [eax + 8]
// 007b6fe8  ffd2                 call edx
// 007b6fea  897e04               mov dword ptr [esi + 4], edi
// 007b6fed  83c608               add esi, 8
// 007b6ff0  3bf5                 cmp esi, ebp
// 007b6ff2  75c0                 jne 0x7b6fb4
// 007b6ff4  5f                   pop edi
// 007b6ff5  5b                   pop ebx
// 007b6ff6  5e                   pop esi
// 007b6ff7  5d                   pop ebp
// 007b6ff8  c3                   ret 
// library templates-boost-1_40_0/vector_wp.cpp (function ??$_Fill@PAV?$weak_ptr@UT@@@boost@@V12@@std@@YAXPAV?$weak_ptr@UT@@@boost@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 vector_wp.cpp
