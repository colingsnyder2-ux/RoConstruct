// from server: 100% by auto
// roc 2010-06 007ada40  unit: CXTPPaintManager  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ada40
//
// 007ada40  8b442418             mov eax, dword ptr [esp + 0x18]
// 007ada44  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007ada48  8b542410             mov edx, dword ptr [esp + 0x10]
// 007ada4c  50                   push eax
// 007ada4d  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ada51  51                   push ecx
// 007ada52  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007ada56  52                   push edx
// 007ada57  8b542410             mov edx, dword ptr [esp + 0x10]
// 007ada5b  50                   push eax
// 007ada5c  51                   push ecx
// 007ada5d  52                   push edx
// 007ada5e  e89d380500           call 0x801300
// 007ada63  8bc8                 mov ecx, eax
// 007ada65  e896390500           call 0x801400
// 007ada6a  c21800               ret 0x18
// library xtp-13.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?GradientFill@CXTPPaintManager@@QAEXPAVCDC@@PAUtagRECT@@KKHPBU3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPaintManager.cpp
