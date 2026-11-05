// from server: 100% by auto
// roc 2012-06 008c4680  unit: RBX::VClickDetector::?$EventDesc  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008c4680
//
// 008c4680  8b442404             mov eax, dword ptr [esp + 4]
// 008c4684  56                   push esi
// 008c4685  8bf1                 mov esi, ecx
// 008c4687  8b08                 mov ecx, dword ptr [eax]
// 008c4689  890e                 mov dword ptr [esi], ecx
// 008c468b  57                   push edi
// 008c468c  8b7804               mov edi, dword ptr [eax + 4]
// 008c468f  3b7e04               cmp edi, dword ptr [esi + 4]
// 008c4692  742d                 je 0x8c46c1
// 008c4694  85ff                 test edi, edi
// 008c4696  740c                 je 0x8c46a4
// 008c4698  8d5708               lea edx, [edi + 8]
// 008c469b  b801000000           mov eax, 1
// 008c46a0  f00fc102             lock xadd dword ptr [edx], eax
// 008c46a4  8b4e04               mov ecx, dword ptr [esi + 4]
// 008c46a7  85c9                 test ecx, ecx
// 008c46a9  7413                 je 0x8c46be
// 008c46ab  8d5108               lea edx, [ecx + 8]
// 008c46ae  83c8ff               or eax, 0xffffffff
// 008c46b1  f00fc102             lock xadd dword ptr [edx], eax
// 008c46b5  7507                 jne 0x8c46be
// 008c46b7  8b11                 mov edx, dword ptr [ecx]
// 008c46b9  8b4208               mov eax, dword ptr [edx + 8]
// 008c46bc  ffd0                 call eax
// 008c46be  897e04               mov dword ptr [esi + 4], edi
// 008c46c1  5f                   pop edi
// 008c46c2  8bc6                 mov eax, esi
// 008c46c4  5e                   pop esi
// 008c46c5  c20400               ret 4
// library templates-boost-1_40_0/deque_wp.cpp (function ??4?$weak_ptr@UT@@@boost@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 deque_wp.cpp
