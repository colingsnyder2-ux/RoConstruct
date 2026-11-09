// from server: 100% by auto
// roc 2011-06 00736850  unit: RBX::VStudioTool::?$EventDesc  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00736850
//
// 00736850  8b442404             mov eax, dword ptr [esp + 4]
// 00736854  56                   push esi
// 00736855  8bf1                 mov esi, ecx
// 00736857  8b08                 mov ecx, dword ptr [eax]
// 00736859  890e                 mov dword ptr [esi], ecx
// 0073685b  57                   push edi
// 0073685c  8b7804               mov edi, dword ptr [eax + 4]
// 0073685f  3b7e04               cmp edi, dword ptr [esi + 4]
// 00736862  742d                 je 0x736891
// 00736864  85ff                 test edi, edi
// 00736866  740c                 je 0x736874
// 00736868  8d5708               lea edx, [edi + 8]
// 0073686b  b801000000           mov eax, 1
// 00736870  f00fc102             lock xadd dword ptr [edx], eax
// 00736874  8b4e04               mov ecx, dword ptr [esi + 4]
// 00736877  85c9                 test ecx, ecx
// 00736879  7413                 je 0x73688e
// 0073687b  8d5108               lea edx, [ecx + 8]
// 0073687e  83c8ff               or eax, 0xffffffff
// 00736881  f00fc102             lock xadd dword ptr [edx], eax
// 00736885  7507                 jne 0x73688e
// 00736887  8b11                 mov edx, dword ptr [ecx]
// 00736889  8b4208               mov eax, dword ptr [edx + 8]
// 0073688c  ffd0                 call eax
// 0073688e  897e04               mov dword ptr [esi + 4], edi
// 00736891  5f                   pop edi
// 00736892  8bc6                 mov eax, esi
// 00736894  5e                   pop esi
// 00736895  c20400               ret 4
// library templates-boost-1_40_0/deque_wp.cpp (function ??4?$weak_ptr@UT@@@boost@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 deque_wp.cpp
