// from server: 100% by auto
// roc 2007-08 00683df0  unit: CXTPPropertyGrid  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00683df0
//
// 00683df0  56                   push esi
// 00683df1  57                   push edi
// 00683df2  8bf1                 mov esi, ecx
// 00683df4  e847ffffff           call 0x683d40
// 00683df9  8b06                 mov eax, dword ptr [esi]
// 00683dfb  8b9058010000         mov edx, dword ptr [eax + 0x158]
// 00683e01  6a00                 push 0
// 00683e03  8bce                 mov ecx, esi
// 00683e05  ffd2                 call edx
// 00683e07  8b3e                 mov edi, dword ptr [esi]
// 00683e09  8bce                 mov ecx, esi
// 00683e0b  e8a0470b00           call 0x7385b0
// 00683e10  50                   push eax
// 00683e11  8b874c010000         mov eax, dword ptr [edi + 0x14c]
// 00683e17  6a01                 push 1
// 00683e19  8bce                 mov ecx, esi
// 00683e1b  ffd0                 call eax
// 00683e1d  5f                   pop edi
// 00683e1e  5e                   pop esi
// 00683e1f  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnSortChanged@CXTPPropertyGrid@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
