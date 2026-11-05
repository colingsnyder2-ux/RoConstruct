// from server: 100% by auto
// roc 2010-06 00810cd0  unit: CXTPDockingPane  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00810cd0
//
// 00810cd0  56                   push esi
// 00810cd1  8b742418             mov esi, dword ptr [esp + 0x18]
// 00810cd5  8d542408             lea edx, [esp + 8]
// 00810cd9  33c0                 xor eax, eax
// 00810cdb  52                   push edx
// 00810cdc  668906               mov word ptr [esi], ax
// 00810cdf  e80ceefdff           call 0x7efaf0
// 00810ce4  85c0                 test eax, eax
// 00810ce6  7515                 jne 0x810cfd
// 00810ce8  b803000000           mov eax, 3
// 00810ced  668906               mov word ptr [esi], ax
// 00810cf0  c7460825000000       mov dword ptr [esi + 8], 0x25
// 00810cf7  33c0                 xor eax, eax
// 00810cf9  5e                   pop esi
// 00810cfa  c21400               ret 0x14
// 00810cfd  b857000780           mov eax, 0x80070057
// 00810d02  5e                   pop esi
// 00810d03  c21400               ret 0x14
// library xtp-13.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?GetAccessibleRole@CXTPDockingPane@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPane.cpp
