// from server: 100% by auto
// roc 2009-12 007fdf70  unit: CXTPPaintManager  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fdf70
//
// 007fdf70  8b442418             mov eax, dword ptr [esp + 0x18]
// 007fdf74  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007fdf78  8b542410             mov edx, dword ptr [esp + 0x10]
// 007fdf7c  50                   push eax
// 007fdf7d  8b442410             mov eax, dword ptr [esp + 0x10]
// 007fdf81  51                   push ecx
// 007fdf82  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007fdf86  52                   push edx
// 007fdf87  8b542410             mov edx, dword ptr [esp + 0x10]
// 007fdf8b  50                   push eax
// 007fdf8c  51                   push ecx
// 007fdf8d  52                   push edx
// 007fdf8e  e80df30400           call 0x84d2a0
// 007fdf93  8bc8                 mov ecx, eax
// 007fdf95  e806f40400           call 0x84d3a0
// 007fdf9a  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?GradientFill@CXTPPaintManager@@QAEXPAVCDC@@PAUtagRECT@@KKHPBU3@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
