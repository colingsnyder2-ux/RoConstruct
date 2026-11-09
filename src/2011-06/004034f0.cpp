// from server: 100% by auto
// roc 2011-06 004034f0  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004034f0
//
// 004034f0  56                   push esi
// 004034f1  8b742408             mov esi, dword ptr [esp + 8]
// 004034f5  85f6                 test esi, esi
// 004034f7  742c                 je 0x403525
// 004034f9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004034fd  85c0                 test eax, eax
// 004034ff  7424                 je 0x403525
// 00403501  8b542410             mov edx, dword ptr [esp + 0x10]
// 00403505  52                   push edx
// 00403506  56                   push esi
// 00403507  6aff                 push -1
// 00403509  50                   push eax
// 0040350a  8b442424             mov eax, dword ptr [esp + 0x24]
// 0040350e  33c9                 xor ecx, ecx
// 00403510  51                   push ecx
// 00403511  50                   push eax
// 00403512  66890e               mov word ptr [esi], cx
// 00403515  ff159003a400         call dword ptr [0xa40390]
// 0040351b  f7d8                 neg eax
// 0040351d  1bc0                 sbb eax, eax
// 0040351f  23c6                 and eax, esi
// 00403521  5e                   pop esi
// 00403522  c21000               ret 0x10
// 00403525  33c0                 xor eax, eax
// 00403527  5e                   pop esi
// 00403528  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxglobalutils.cpp (function ?AtlA2WHelper@@YGPA_WPA_WPBDHI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxglobalutils.cpp
