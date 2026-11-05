// from server: 100% by auto
// roc 2010-06 0081b9d0  unit: CXTPPropertyGridView  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081b9d0
//
// 0081b9d0  56                   push esi
// 0081b9d1  8b742418             mov esi, dword ptr [esp + 0x18]
// 0081b9d5  8d542408             lea edx, [esp + 8]
// 0081b9d9  33c0                 xor eax, eax
// 0081b9db  52                   push edx
// 0081b9dc  668906               mov word ptr [esi], ax
// 0081b9df  e80c41fdff           call 0x7efaf0
// 0081b9e4  85c0                 test eax, eax
// 0081b9e6  7515                 jne 0x81b9fd
// 0081b9e8  b803000000           mov eax, 3
// 0081b9ed  668906               mov word ptr [esi], ax
// 0081b9f0  c7460818000000       mov dword ptr [esi + 8], 0x18
// 0081b9f7  33c0                 xor eax, eax
// 0081b9f9  5e                   pop esi
// 0081b9fa  c21400               ret 0x14
// 0081b9fd  b857000780           mov eax, 0x80070057
// 0081ba02  5e                   pop esi
// 0081ba03  c21400               ret 0x14
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetAccessibleRole@CXTPPropertyGridView@@MAEJUtagVARIANT@@PAU2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
