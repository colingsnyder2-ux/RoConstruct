// from server: 100% by auto
// roc 2009-12 0057ba80  unit: RBX::VCylinderMesh::?$FactoryProduct::Creator  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057ba80
//
// 0057ba80  8b442404             mov eax, dword ptr [esp + 4]
// 0057ba84  56                   push esi
// 0057ba85  8bf1                 mov esi, ecx
// 0057ba87  8b08                 mov ecx, dword ptr [eax]
// 0057ba89  890e                 mov dword ptr [esi], ecx
// 0057ba8b  57                   push edi
// 0057ba8c  8b7804               mov edi, dword ptr [eax + 4]
// 0057ba8f  3b7e04               cmp edi, dword ptr [esi + 4]
// 0057ba92  742d                 je 0x57bac1
// 0057ba94  85ff                 test edi, edi
// 0057ba96  740c                 je 0x57baa4
// 0057ba98  8d5708               lea edx, [edi + 8]
// 0057ba9b  b801000000           mov eax, 1
// 0057baa0  f00fc102             lock xadd dword ptr [edx], eax
// 0057baa4  8b4e04               mov ecx, dword ptr [esi + 4]
// 0057baa7  85c9                 test ecx, ecx
// 0057baa9  7413                 je 0x57babe
// 0057baab  8d5108               lea edx, [ecx + 8]
// 0057baae  83c8ff               or eax, 0xffffffff
// 0057bab1  f00fc102             lock xadd dword ptr [edx], eax
// 0057bab5  7507                 jne 0x57babe
// 0057bab7  8b11                 mov edx, dword ptr [ecx]
// 0057bab9  8b4208               mov eax, dword ptr [edx + 8]
// 0057babc  ffd0                 call eax
// 0057babe  897e04               mov dword ptr [esi + 4], edi
// 0057bac1  5f                   pop edi
// 0057bac2  8bc6                 mov eax, esi
// 0057bac4  5e                   pop esi
// 0057bac5  c20400               ret 4
// library templates-boost-1_40_0/deque_wp.cpp (function ??4?$weak_ptr@UT@@@boost@@QAEAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_40_0 deque_wp.cpp
