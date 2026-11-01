// from server: 100% by auto
// roc 2011-06 008f2380  unit: CXTCaptionButton  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f2380
//
// 008f2380  56                   push esi
// 008f2381  8bf1                 mov esi, ecx
// 008f2383  e83c7df1ff           call 0x80a0c4
// 008f2388  807e7400             cmp byte ptr [esi + 0x74], 0
// 008f238c  740d                 je 0x8f239b
// 008f238e  8b06                 mov eax, dword ptr [esi]
// 008f2390  8b9094010000         mov edx, dword ptr [eax + 0x194]
// 008f2396  8bce                 mov ecx, esi
// 008f2398  5e                   pop esi
// 008f2399  ffe2                 jmp edx
// 008f239b  5e                   pop esi
// 008f239c  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Controls\Deprecated\XTButton.cpp (function ?PreSubclassWindow@CXTButton@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Deprecated/XTButton.cpp
