// from server: 100% by auto
// roc 2011-06 00421950  unit: RBX::FunctionMarshaller  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00421950
//
// 00421950  57                   push edi
// 00421951  8b7c2408             mov edi, dword ptr [esp + 8]
// 00421955  85ff                 test edi, edi
// 00421957  742a                 je 0x421983
// 00421959  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0042195d  85c0                 test eax, eax
// 0042195f  7422                 je 0x421983
// 00421961  56                   push esi
// 00421962  50                   push eax
// 00421963  ff15a41ca400         call dword ptr [0xa41ca4]
// 00421969  0fb7f0               movzx esi, ax
// 0042196c  8d44240c             lea eax, [esp + 0xc]
// 00421970  50                   push eax
// 00421971  8d4f20               lea ecx, [edi + 0x20]
// 00421974  89742410             mov dword ptr [esp + 0x10], esi
// 00421978  e813feffff           call 0x421790
// 0042197d  0fb7c6               movzx eax, si
// 00421980  5e                   pop esi
// 00421981  5f                   pop edi
// 00421982  c3                   ret 
// 00421983  33c0                 xor eax, eax
// 00421985  5f                   pop edi
// 00421986  c3                   ret 
// library atl-8.0/atl.cpp (function ?RegisterClassExA@AtlModuleRegisterWndClassInfoParamA@ATL@@SAGPAU_ATL_WIN_MODULE70@2@PBUtagWNDCLASSEXA@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
