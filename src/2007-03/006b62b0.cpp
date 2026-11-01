// from server: 100% by auto
// roc 2007-03 006b62b0  unit: seg_006b0000  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b62b0
//
// 006b62b0  8b442418             mov eax, dword ptr [esp + 0x18]
// 006b62b4  83ec08               sub esp, 8
// 006b62b7  53                   push ebx
// 006b62b8  55                   push ebp
// 006b62b9  56                   push esi
// 006b62ba  8b742418             mov esi, dword ptr [esp + 0x18]
// 006b62be  57                   push edi
// 006b62bf  50                   push eax
// 006b62c0  8bce                 mov ecx, esi
// 006b62c2  e87b4f0800           call 0x73b242
// 006b62c7  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 006b62cb  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 006b62cf  53                   push ebx
// 006b62d0  55                   push ebp
// 006b62d1  8d4c2418             lea ecx, [esp + 0x18]
// 006b62d5  51                   push ecx
// 006b62d6  8bce                 mov ecx, esi
// 006b62d8  8bf8                 mov edi, eax
// 006b62da  e8198bf6ff           call 0x61edf8
// 006b62df  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 006b62e3  8b442428             mov eax, dword ptr [esp + 0x28]
// 006b62e7  03da                 add ebx, edx
// 006b62e9  53                   push ebx
// 006b62ea  03e8                 add ebp, eax
// 006b62ec  55                   push ebp
// 006b62ed  8bce                 mov ecx, esi
// 006b62ef  e8fe8af6ff           call 0x61edf2
// 006b62f4  57                   push edi
// 006b62f5  8bce                 mov ecx, esi
// 006b62f7  e8464f0800           call 0x73b242
// 006b62fc  5f                   pop edi
// 006b62fd  5e                   pop esi
// 006b62fe  5d                   pop ebp
// 006b62ff  5b                   pop ebx
// 006b6300  83c408               add esp, 8
// 006b6303  c21800               ret 0x18
// library xtp-15.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?Line@CXTPReportPaintManager@@QAEXPAVCDC@@HHHHPAVCPen@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportPaintManager.cpp
