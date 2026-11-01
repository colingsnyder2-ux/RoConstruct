// from server: 100% by auto
// roc 2009-06 0078c9b0  unit: CXTPPropertyGridView  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078c9b0
//
// 0078c9b0  56                   push esi
// 0078c9b1  8b742418             mov esi, dword ptr [esp + 0x18]
// 0078c9b5  8d542408             lea edx, [esp + 8]
// 0078c9b9  33c0                 xor eax, eax
// 0078c9bb  52                   push edx
// 0078c9bc  668906               mov word ptr [esi], ax
// 0078c9bf  e80c42fdff           call 0x760bd0
// 0078c9c4  85c0                 test eax, eax
// 0078c9c6  7515                 jne 0x78c9dd
// 0078c9c8  b803000000           mov eax, 3
// 0078c9cd  668906               mov word ptr [esi], ax
// 0078c9d0  c7460818000000       mov dword ptr [esi + 8], 0x18
// 0078c9d7  33c0                 xor eax, eax
// 0078c9d9  5e                   pop esi
// 0078c9da  c21400               ret 0x14
// 0078c9dd  b857000780           mov eax, 0x80070057
// 0078c9e2  5e                   pop esi
// 0078c9e3  c21400               ret 0x14
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleRole@CXTPPropertyGridView@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
