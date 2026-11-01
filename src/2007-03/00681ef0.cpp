// from server: 100% by auto
// roc 2007-03 00681ef0  unit: seg_00680000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00681ef0
//
// 00681ef0  56                   push esi
// 00681ef1  6a40                 push 0x40
// 00681ef3  8bf1                 mov esi, ecx
// 00681ef5  6a00                 push 0
// 00681ef7  56                   push esi
// 00681ef8  c7463c00000000       mov dword ptr [esi + 0x3c], 0
// 00681eff  e818d1f9ff           call 0x61f01c
// 00681f04  83c40c               add esp, 0xc
// 00681f07  8bc6                 mov eax, esi
// 00681f09  5e                   pop esi
// 00681f0a  c3                   ret 
// library xtp-15.2.1/Source\Controls\Util\XTPGlobal.cpp (function ??0CXTPLogFont@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Util/XTPGlobal.cpp
