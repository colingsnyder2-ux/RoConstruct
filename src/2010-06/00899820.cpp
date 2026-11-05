// from server: 100% by auto
// roc 2010-06 00899820  unit: CXTCaptionButton  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00899820
//
// 00899820  56                   push esi
// 00899821  8bf1                 mov esi, ecx
// 00899823  e8dee1f0ff           call 0x7a7a06
// 00899828  807e7400             cmp byte ptr [esi + 0x74], 0
// 0089982c  740d                 je 0x89983b
// 0089982e  8b06                 mov eax, dword ptr [esi]
// 00899830  8b9094010000         mov edx, dword ptr [eax + 0x194]
// 00899836  8bce                 mov ecx, esi
// 00899838  5e                   pop esi
// 00899839  ffe2                 jmp edx
// 0089983b  5e                   pop esi
// 0089983c  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Controls\XTButton.cpp (function ?PreSubclassWindow@CXTButton@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTButton.cpp
