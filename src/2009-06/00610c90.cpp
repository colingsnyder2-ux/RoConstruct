// from server: 100% by auto
// roc 2009-06 00610c90  unit: RBX::ModelInstance  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00610c90
//
// 00610c90  8b442404             mov eax, dword ptr [esp + 4]
// 00610c94  56                   push esi
// 00610c95  8bf1                 mov esi, ecx
// 00610c97  8b08                 mov ecx, dword ptr [eax]
// 00610c99  890e                 mov dword ptr [esi], ecx
// 00610c9b  57                   push edi
// 00610c9c  8b7804               mov edi, dword ptr [eax + 4]
// 00610c9f  3b7e04               cmp edi, dword ptr [esi + 4]
// 00610ca2  742d                 je 0x610cd1
// 00610ca4  85ff                 test edi, edi
// 00610ca6  740c                 je 0x610cb4
// 00610ca8  8d5708               lea edx, [edi + 8]
// 00610cab  b801000000           mov eax, 1
// 00610cb0  f00fc102             lock xadd dword ptr [edx], eax
// 00610cb4  8b4e04               mov ecx, dword ptr [esi + 4]
// 00610cb7  85c9                 test ecx, ecx
// 00610cb9  7413                 je 0x610cce
// 00610cbb  8d5108               lea edx, [ecx + 8]
// 00610cbe  83c8ff               or eax, 0xffffffff
// 00610cc1  f00fc102             lock xadd dword ptr [edx], eax
// 00610cc5  7507                 jne 0x610cce
// 00610cc7  8b11                 mov edx, dword ptr [ecx]
// 00610cc9  8b4208               mov eax, dword ptr [edx + 8]
// 00610ccc  ffd0                 call eax
// 00610cce  897e04               mov dword ptr [esi + 4], edi
// 00610cd1  5f                   pop edi
// 00610cd2  8bc6                 mov eax, esi
// 00610cd4  5e                   pop esi
// 00610cd5  c20400               ret 4
// library templates-boost-1_40_0/deque_wp.cpp (function ??4?$weak_ptr@UT@@@boost@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 deque_wp.cpp
