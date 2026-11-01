// from server: 100% by auto
// roc 2009-06 0078c9f0  unit: CXTPPropertyGridView  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078c9f0
//
// 0078c9f0  56                   push esi
// 0078c9f1  8b742418             mov esi, dword ptr [esp + 0x18]
// 0078c9f5  8d542408             lea edx, [esp + 8]
// 0078c9f9  b803000000           mov eax, 3
// 0078c9fe  52                   push edx
// 0078c9ff  668906               mov word ptr [esi], ax
// 0078ca02  c7460800000000       mov dword ptr [esi + 8], 0
// 0078ca09  e8c241fdff           call 0x760bd0
// 0078ca0e  85c0                 test eax, eax
// 0078ca10  7507                 jne 0x78ca19
// 0078ca12  c7460800001000       mov dword ptr [esi + 8], 0x100000
// 0078ca19  33c0                 xor eax, eax
// 0078ca1b  5e                   pop esi
// 0078ca1c  c21400               ret 0x14
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleState@CXTPPropertyGridView@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
