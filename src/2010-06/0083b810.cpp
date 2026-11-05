// from server: 100% by auto
// roc 2010-06 0083b810  unit: XTPPaintThemes::CXTPOfficeTheme  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0083b810
//
// 0083b810  8b542408             mov edx, dword ptr [esp + 8]
// 0083b814  6a10                 push 0x10
// 0083b816  6a10                 push 0x10
// 0083b818  83ec10               sub esp, 0x10
// 0083b81b  8bc4                 mov eax, esp
// 0083b81d  8910                 mov dword ptr [eax], edx
// 0083b81f  8b542424             mov edx, dword ptr [esp + 0x24]
// 0083b823  895004               mov dword ptr [eax + 4], edx
// 0083b826  8b542428             mov edx, dword ptr [esp + 0x28]
// 0083b82a  895008               mov dword ptr [eax + 8], edx
// 0083b82d  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0083b831  89500c               mov dword ptr [eax + 0xc], edx
// 0083b834  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0083b838  50                   push eax
// 0083b839  e8d21af7ff           call 0x7ad310
// 0083b83e  c21c00               ret 0x1c
// library xtp-13.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawStatusBarPaneBorder@CXTPOfficeTheme@@MAEXPAVCDC@@VCRect@@PAVCXTPStatusBarPane@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOfficeTheme.cpp
