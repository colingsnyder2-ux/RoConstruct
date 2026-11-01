// from server: 100% by auto
// roc 2007-03 00705ca0  unit: seg_00700000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00705ca0
//
// 00705ca0  56                   push esi
// 00705ca1  8bf1                 mov esi, ecx
// 00705ca3  e8c084f1ff           call 0x61e168
// 00705ca8  807e7400             cmp byte ptr [esi + 0x74], 0
// 00705cac  740d                 je 0x705cbb
// 00705cae  8b06                 mov eax, dword ptr [esi]
// 00705cb0  8b908c010000         mov edx, dword ptr [eax + 0x18c]
// 00705cb6  8bce                 mov ecx, esi
// 00705cb8  5e                   pop esi
// 00705cb9  ffe2                 jmp edx
// 00705cbb  5e                   pop esi
// 00705cbc  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?PreSubclassWindow@CXTButton@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
