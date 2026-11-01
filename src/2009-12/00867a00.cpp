// from server: 100% by auto
// roc 2009-12 00867a00  unit: CXTPPropertyGridView  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00867a00
//
// 00867a00  56                   push esi
// 00867a01  8b742418             mov esi, dword ptr [esp + 0x18]
// 00867a05  8d542408             lea edx, [esp + 8]
// 00867a09  b803000000           mov eax, 3
// 00867a0e  52                   push edx
// 00867a0f  668906               mov word ptr [esi], ax
// 00867a12  c7460800000000       mov dword ptr [esi + 8], 0
// 00867a19  e8823ffdff           call 0x83b9a0
// 00867a1e  85c0                 test eax, eax
// 00867a20  7507                 jne 0x867a29
// 00867a22  c7460800001000       mov dword ptr [esi + 8], 0x100000
// 00867a29  33c0                 xor eax, eax
// 00867a2b  5e                   pop esi
// 00867a2c  c21400               ret 0x14
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleState@CXTPPropertyGridView@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
