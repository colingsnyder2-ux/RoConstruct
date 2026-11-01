// from server: 100% by auto
// roc 2009-06 007230b0  unit: CXTPPaintManager  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007230b0
//
// 007230b0  8b442418             mov eax, dword ptr [esp + 0x18]
// 007230b4  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007230b8  8b542410             mov edx, dword ptr [esp + 0x10]
// 007230bc  50                   push eax
// 007230bd  8b442410             mov eax, dword ptr [esp + 0x10]
// 007230c1  51                   push ecx
// 007230c2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007230c6  52                   push edx
// 007230c7  8b542410             mov edx, dword ptr [esp + 0x10]
// 007230cb  50                   push eax
// 007230cc  51                   push ecx
// 007230cd  52                   push edx
// 007230ce  e89df40400           call 0x772570
// 007230d3  8bc8                 mov ecx, eax
// 007230d5  e896f50400           call 0x772670
// 007230da  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?GradientFill@CXTPPaintManager@@QAEXPAVCDC@@PAUtagRECT@@KKHPBU3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
