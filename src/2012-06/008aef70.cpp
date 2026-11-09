// from server: 100% by auto
// roc 2012-06 008aef70  unit: RBX::Flag  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008aef70
//
// 008aef70  55                   push ebp
// 008aef71  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 008aef75  56                   push esi
// 008aef76  8b74240c             mov esi, dword ptr [esp + 0xc]
// 008aef7a  3bf5                 cmp esi, ebp
// 008aef7c  7448                 je 0x8aefc6
// 008aef7e  53                   push ebx
// 008aef7f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 008aef83  57                   push edi
// 008aef84  8b03                 mov eax, dword ptr [ebx]
// 008aef86  8906                 mov dword ptr [esi], eax
// 008aef88  8b7b04               mov edi, dword ptr [ebx + 4]
// 008aef8b  3b7e04               cmp edi, dword ptr [esi + 4]
// 008aef8e  742d                 je 0x8aefbd
// 008aef90  85ff                 test edi, edi
// 008aef92  740c                 je 0x8aefa0
// 008aef94  8d4f08               lea ecx, [edi + 8]
// 008aef97  ba01000000           mov edx, 1
// 008aef9c  f00fc111             lock xadd dword ptr [ecx], edx
// 008aefa0  8b4e04               mov ecx, dword ptr [esi + 4]
// 008aefa3  85c9                 test ecx, ecx
// 008aefa5  7413                 je 0x8aefba
// 008aefa7  8d4108               lea eax, [ecx + 8]
// 008aefaa  83caff               or edx, 0xffffffff
// 008aefad  f00fc110             lock xadd dword ptr [eax], edx
// 008aefb1  7507                 jne 0x8aefba
// 008aefb3  8b01                 mov eax, dword ptr [ecx]
// 008aefb5  8b5008               mov edx, dword ptr [eax + 8]
// 008aefb8  ffd2                 call edx
// 008aefba  897e04               mov dword ptr [esi + 4], edi
// 008aefbd  83c608               add esi, 8
// 008aefc0  3bf5                 cmp esi, ebp
// 008aefc2  75c0                 jne 0x8aef84
// 008aefc4  5f                   pop edi
// 008aefc5  5b                   pop ebx
// 008aefc6  5e                   pop esi
// 008aefc7  5d                   pop ebp
// 008aefc8  c3                   ret 
// library templates-boost-1_40_0/vector_wp.cpp (function ??$_Fill@PAV?$weak_ptr@UT@@@boost@@V12@@std@@YAXPAV?$weak_ptr@UT@@@boost@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 vector_wp.cpp
