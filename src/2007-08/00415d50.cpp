// from server: 100% by tester
// roc 2007-03 00416d90  unit: seg_00410000  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00416d90
//
// 00416d90  57                   push edi
// 00416d91  8b7c2408             mov edi, dword ptr [esp + 8]
// 00416d95  85ff                 test edi, edi
// 00416d97  742a                 je 0x416dc3
// 00416d99  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00416d9d  85c0                 test eax, eax
// 00416d9f  7422                 je 0x416dc3
// 00416da1  56                   push esi
// 00416da2  50                   push eax
// 00416da3  ff15f8ec7700         call dword ptr [0x77ecf8]
// 00416da9  0fb7f0               movzx esi, ax
// 00416dac  8d44240c             lea eax, [esp + 0xc]
// 00416db0  50                   push eax
// 00416db1  8d4f20               lea ecx, [edi + 0x20]
// 00416db4  89742410             mov dword ptr [esp + 0x10], esi
// 00416db8  e8f3e7ffff           call 0x4155b0
// 00416dbd  0fb7c6               movzx eax, si
// 00416dc0  5e                   pop esi
// 00416dc1  5f                   pop edi
// 00416dc2  c3                   ret 
// 00416dc3  33c0                 xor eax, eax
// 00416dc5  5f                   pop edi
// 00416dc6  c3                   ret 
// library atl-8.0/atl.cpp (function ?RegisterClassExA@AtlModuleRegisterWndClassInfoParamA@ATL@@SAGPAU_ATL_WIN_MODULE70@2@PBUtagWNDCLASSEXA@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
