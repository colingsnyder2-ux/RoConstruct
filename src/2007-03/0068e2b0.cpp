// from server: 100% by auto
// roc 2007-03 0068e2b0  unit: seg_00680000  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068e2b0
//
// 0068e2b0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0068e2b4  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 0068e2b7  83ec10               sub esp, 0x10
// 0068e2ba  8bc4                 mov eax, esp
// 0068e2bc  8910                 mov dword ptr [eax], edx
// 0068e2be  8b542420             mov edx, dword ptr [esp + 0x20]
// 0068e2c2  895004               mov dword ptr [eax + 4], edx
// 0068e2c5  8b542424             mov edx, dword ptr [esp + 0x24]
// 0068e2c9  895008               mov dword ptr [eax + 8], edx
// 0068e2cc  8b542428             mov edx, dword ptr [esp + 0x28]
// 0068e2d0  89500c               mov dword ptr [eax + 0xc], edx
// 0068e2d3  8b442418             mov eax, dword ptr [esp + 0x18]
// 0068e2d7  8b542414             mov edx, dword ptr [esp + 0x14]
// 0068e2db  50                   push eax
// 0068e2dc  52                   push edx
// 0068e2dd  e8aec20500           call 0x6ea590
// 0068e2e2  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?DrawTabControl@CXTPTabPaintManagerAppearanceSet@@UAEXPAVCXTPTabManager@@PAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
