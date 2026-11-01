// from server: 100% by auto
// roc 2009-06 00781c90  unit: CXTPDockingPane  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00781c90
//
// 00781c90  56                   push esi
// 00781c91  8b742418             mov esi, dword ptr [esp + 0x18]
// 00781c95  8d542408             lea edx, [esp + 8]
// 00781c99  33c0                 xor eax, eax
// 00781c9b  52                   push edx
// 00781c9c  668906               mov word ptr [esi], ax
// 00781c9f  e82ceffdff           call 0x760bd0
// 00781ca4  85c0                 test eax, eax
// 00781ca6  7515                 jne 0x781cbd
// 00781ca8  b803000000           mov eax, 3
// 00781cad  668906               mov word ptr [esi], ax
// 00781cb0  c7460825000000       mov dword ptr [esi + 8], 0x25
// 00781cb7  33c0                 xor eax, eax
// 00781cb9  5e                   pop esi
// 00781cba  c21400               ret 0x14
// 00781cbd  b857000780           mov eax, 0x80070057
// 00781cc2  5e                   pop esi
// 00781cc3  c21400               ret 0x14
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?GetAccessibleRole@CXTPDockingPane@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
