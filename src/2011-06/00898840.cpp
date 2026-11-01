// from server: 100% by auto
// roc 2011-06 00898840  unit: XTPPaintThemes::CXTPOfficeTheme  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00898840
//
// 00898840  8b542408             mov edx, dword ptr [esp + 8]
// 00898844  6a10                 push 0x10
// 00898846  6a10                 push 0x10
// 00898848  83ec10               sub esp, 0x10
// 0089884b  8bc4                 mov eax, esp
// 0089884d  8910                 mov dword ptr [eax], edx
// 0089884f  8b542424             mov edx, dword ptr [esp + 0x24]
// 00898853  895004               mov dword ptr [eax + 4], edx
// 00898856  8b542428             mov edx, dword ptr [esp + 0x28]
// 0089885a  895008               mov dword ptr [eax + 8], edx
// 0089885d  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00898861  89500c               mov dword ptr [eax + 0xc], edx
// 00898864  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00898868  50                   push eax
// 00898869  e8426ff7ff           call 0x80f7b0
// 0089886e  c21c00               ret 0x1c
// library xtp-13.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawStatusBarPaneBorder@CXTPOfficeTheme@@MAEXPAVCDC@@VCRect@@PAVCXTPStatusBarPane@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOfficeTheme.cpp
