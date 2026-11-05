// from server: 100% by auto
// roc 2010-06 0082bb90  unit: XTPPaintThemes::CXTPDefaultTheme  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0082bb90
//
// 0082bb90  83ec10               sub esp, 0x10
// 0082bb93  837c243000           cmp dword ptr [esp + 0x30], 0
// 0082bb98  7440                 je 0x82bbda
// 0082bb9a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0082bb9e  8b542420             mov edx, dword ptr [esp + 0x20]
// 0082bba2  890424               mov dword ptr [esp], eax
// 0082bba5  8b442424             mov eax, dword ptr [esp + 0x24]
// 0082bba9  89442408             mov dword ptr [esp + 8], eax
// 0082bbad  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0082bbb1  89542404             mov dword ptr [esp + 4], edx
// 0082bbb5  8b542428             mov edx, dword ptr [esp + 0x28]
// 0082bbb9  4a                   dec edx
// 0082bbba  f7d8                 neg eax
// 0082bbbc  1bc0                 sbb eax, eax
// 0082bbbe  83c003               add eax, 3
// 0082bbc1  50                   push eax
// 0082bbc2  89542410             mov dword ptr [esp + 0x10], edx
// 0082bbc6  e84515f8ff           call 0x7ad110
// 0082bbcb  50                   push eax
// 0082bbcc  8d4c2404             lea ecx, [esp + 4]
// 0082bbd0  51                   push ecx
// 0082bbd1  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0082bbd5  e864cbf7ff           call 0x7a873e
// 0082bbda  8b442414             mov eax, dword ptr [esp + 0x14]
// 0082bbde  c70000000000         mov dword ptr [eax], 0
// 0082bbe4  c7400408000000       mov dword ptr [eax + 4], 8
// 0082bbeb  83c410               add esp, 0x10
// 0082bbee  c22000               ret 0x20
// library xtp-13.2.1/Source\CommandBars\XTPDefaultTheme.cpp (function ?DrawTearOffGripper@CXTPDefaultTheme@@UAE?AVCSize@@PAVCDC@@VCRect@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDefaultTheme.cpp
