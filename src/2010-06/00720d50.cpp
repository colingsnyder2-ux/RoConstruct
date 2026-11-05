// from server: 100% by auto
// roc 2010-06 00720d50  unit: RBX::UniversalTool  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00720d50
//
// 00720d50  8b442404             mov eax, dword ptr [esp + 4]
// 00720d54  56                   push esi
// 00720d55  8bf1                 mov esi, ecx
// 00720d57  8b08                 mov ecx, dword ptr [eax]
// 00720d59  890e                 mov dword ptr [esi], ecx
// 00720d5b  57                   push edi
// 00720d5c  8b7804               mov edi, dword ptr [eax + 4]
// 00720d5f  3b7e04               cmp edi, dword ptr [esi + 4]
// 00720d62  742d                 je 0x720d91
// 00720d64  85ff                 test edi, edi
// 00720d66  740c                 je 0x720d74
// 00720d68  8d5708               lea edx, [edi + 8]
// 00720d6b  b801000000           mov eax, 1
// 00720d70  f00fc102             lock xadd dword ptr [edx], eax
// 00720d74  8b4e04               mov ecx, dword ptr [esi + 4]
// 00720d77  85c9                 test ecx, ecx
// 00720d79  7413                 je 0x720d8e
// 00720d7b  8d5108               lea edx, [ecx + 8]
// 00720d7e  83c8ff               or eax, 0xffffffff
// 00720d81  f00fc102             lock xadd dword ptr [edx], eax
// 00720d85  7507                 jne 0x720d8e
// 00720d87  8b11                 mov edx, dword ptr [ecx]
// 00720d89  8b4208               mov eax, dword ptr [edx + 8]
// 00720d8c  ffd0                 call eax
// 00720d8e  897e04               mov dword ptr [esi + 4], edi
// 00720d91  5f                   pop edi
// 00720d92  8bc6                 mov eax, esi
// 00720d94  5e                   pop esi
// 00720d95  c20400               ret 4
// library templates-boost-1_40_0/deque_wp.cpp (function ??4?$weak_ptr@UT@@@boost@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 deque_wp.cpp
