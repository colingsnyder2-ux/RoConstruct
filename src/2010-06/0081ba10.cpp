// from server: 100% by auto
// roc 2010-06 0081ba10  unit: CXTPPropertyGridView  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081ba10
//
// 0081ba10  56                   push esi
// 0081ba11  8b742418             mov esi, dword ptr [esp + 0x18]
// 0081ba15  8d542408             lea edx, [esp + 8]
// 0081ba19  b803000000           mov eax, 3
// 0081ba1e  52                   push edx
// 0081ba1f  668906               mov word ptr [esi], ax
// 0081ba22  c7460800000000       mov dword ptr [esi + 8], 0
// 0081ba29  e8c240fdff           call 0x7efaf0
// 0081ba2e  85c0                 test eax, eax
// 0081ba30  7507                 jne 0x81ba39
// 0081ba32  c7460800001000       mov dword ptr [esi + 8], 0x100000
// 0081ba39  33c0                 xor eax, eax
// 0081ba3b  5e                   pop esi
// 0081ba3c  c21400               ret 0x14
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleState@CXTPPropertyGridView@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
