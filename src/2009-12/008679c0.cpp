// from server: 100% by auto
// roc 2009-12 008679c0  unit: CXTPPropertyGridView  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008679c0
//
// 008679c0  56                   push esi
// 008679c1  8b742418             mov esi, dword ptr [esp + 0x18]
// 008679c5  8d542408             lea edx, [esp + 8]
// 008679c9  33c0                 xor eax, eax
// 008679cb  52                   push edx
// 008679cc  668906               mov word ptr [esi], ax
// 008679cf  e8cc3ffdff           call 0x83b9a0
// 008679d4  85c0                 test eax, eax
// 008679d6  7515                 jne 0x8679ed
// 008679d8  b803000000           mov eax, 3
// 008679dd  668906               mov word ptr [esi], ax
// 008679e0  c7460818000000       mov dword ptr [esi + 8], 0x18
// 008679e7  33c0                 xor eax, eax
// 008679e9  5e                   pop esi
// 008679ea  c21400               ret 0x14
// 008679ed  b857000780           mov eax, 0x80070057
// 008679f2  5e                   pop esi
// 008679f3  c21400               ret 0x14
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleRole@CXTPPropertyGridView@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
