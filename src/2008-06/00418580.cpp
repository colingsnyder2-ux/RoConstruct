// from server: 100% by auto
// roc 2008-06 00418580  unit: VCContent::?$CComContainedObject  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00418580
//
// 00418580  57                   push edi
// 00418581  8b7c2408             mov edi, dword ptr [esp + 8]
// 00418585  85ff                 test edi, edi
// 00418587  742a                 je 0x4185b3
// 00418589  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041858d  85c0                 test eax, eax
// 0041858f  7422                 je 0x4185b3
// 00418591  56                   push esi
// 00418592  50                   push eax
// 00418593  ff15c82d8000         call dword ptr [0x802dc8]
// 00418599  0fb7f0               movzx esi, ax
// 0041859c  8d44240c             lea eax, [esp + 0xc]
// 004185a0  50                   push eax
// 004185a1  8d4f20               lea ecx, [edi + 0x20]
// 004185a4  89742410             mov dword ptr [esp + 0x10], esi
// 004185a8  e883eeffff           call 0x417430
// 004185ad  0fb7c6               movzx eax, si
// 004185b0  5e                   pop esi
// 004185b1  5f                   pop edi
// 004185b2  c3                   ret 
// 004185b3  33c0                 xor eax, eax
// 004185b5  5f                   pop edi
// 004185b6  c3                   ret 
// library atl-8.0/atl.cpp (function ?RegisterClassExA@AtlModuleRegisterWndClassInfoParamA@ATL@@SAGPAU_ATL_WIN_MODULE70@2@PBUtagWNDCLASSEXA@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
