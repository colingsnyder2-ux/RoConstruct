// from server: 100% by auto
// roc 2009-12 0085ccf0  unit: CXTPDockingPane  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085ccf0
//
// 0085ccf0  56                   push esi
// 0085ccf1  8b742418             mov esi, dword ptr [esp + 0x18]
// 0085ccf5  8d542408             lea edx, [esp + 8]
// 0085ccf9  33c0                 xor eax, eax
// 0085ccfb  52                   push edx
// 0085ccfc  668906               mov word ptr [esi], ax
// 0085ccff  e89cecfdff           call 0x83b9a0
// 0085cd04  85c0                 test eax, eax
// 0085cd06  7515                 jne 0x85cd1d
// 0085cd08  b803000000           mov eax, 3
// 0085cd0d  668906               mov word ptr [esi], ax
// 0085cd10  c7460825000000       mov dword ptr [esi + 8], 0x25
// 0085cd17  33c0                 xor eax, eax
// 0085cd19  5e                   pop esi
// 0085cd1a  c21400               ret 0x14
// 0085cd1d  b857000780           mov eax, 0x80070057
// 0085cd22  5e                   pop esi
// 0085cd23  c21400               ret 0x14
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?GetAccessibleRole@CXTPDockingPane@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
