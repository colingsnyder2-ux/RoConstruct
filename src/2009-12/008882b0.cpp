// from server: 100% by auto
// roc 2009-12 008882b0  unit: XTPPaintThemes::CXTPOfficeTheme  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008882b0
//
// 008882b0  8b542408             mov edx, dword ptr [esp + 8]
// 008882b4  6a10                 push 0x10
// 008882b6  6a10                 push 0x10
// 008882b8  83ec10               sub esp, 0x10
// 008882bb  8bc4                 mov eax, esp
// 008882bd  8910                 mov dword ptr [eax], edx
// 008882bf  8b542424             mov edx, dword ptr [esp + 0x24]
// 008882c3  895004               mov dword ptr [eax + 4], edx
// 008882c6  8b542428             mov edx, dword ptr [esp + 0x28]
// 008882ca  895008               mov dword ptr [eax + 8], edx
// 008882cd  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 008882d1  89500c               mov dword ptr [eax + 0xc], edx
// 008882d4  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008882d8  50                   push eax
// 008882d9  e86255f7ff           call 0x7fd840
// 008882de  c21c00               ret 0x1c
// library xtp-13.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawStatusBarPaneBorder@CXTPOfficeTheme@@MAEXPAVCDC@@VCRect@@PAVCXTPStatusBarPane@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOfficeTheme.cpp
