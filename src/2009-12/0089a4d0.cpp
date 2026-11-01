// from server: 100% by auto
// roc 2009-12 0089a4d0  unit: CXTPRibbonBar  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0089a4d0
//
// 0089a4d0  8b442418             mov eax, dword ptr [esp + 0x18]
// 0089a4d4  83ec08               sub esp, 8
// 0089a4d7  53                   push ebx
// 0089a4d8  55                   push ebp
// 0089a4d9  56                   push esi
// 0089a4da  8b742418             mov esi, dword ptr [esp + 0x18]
// 0089a4de  57                   push edi
// 0089a4df  50                   push eax
// 0089a4e0  8bce                 mov ecx, esi
// 0089a4e2  e81dc70800           call 0x926c04
// 0089a4e7  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0089a4eb  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0089a4ef  53                   push ebx
// 0089a4f0  55                   push ebp
// 0089a4f1  8d4c2418             lea ecx, [esp + 0x18]
// 0089a4f5  51                   push ecx
// 0089a4f6  8bce                 mov ecx, esi
// 0089a4f8  8bf8                 mov edi, eax
// 0089a4fa  e843a2f5ff           call 0x7f4742
// 0089a4ff  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0089a503  8b442428             mov eax, dword ptr [esp + 0x28]
// 0089a507  03da                 add ebx, edx
// 0089a509  53                   push ebx
// 0089a50a  03e8                 add ebp, eax
// 0089a50c  55                   push ebp
// 0089a50d  8bce                 mov ecx, esi
// 0089a50f  e828a2f5ff           call 0x7f473c
// 0089a514  57                   push edi
// 0089a515  8bce                 mov ecx, esi
// 0089a517  e8e8c60800           call 0x926c04
// 0089a51c  5f                   pop edi
// 0089a51d  5e                   pop esi
// 0089a51e  5d                   pop ebp
// 0089a51f  5b                   pop ebx
// 0089a520  83c408               add esp, 8
// 0089a523  c21800               ret 0x18
// library xtp-15.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?Line@CXTPReportPaintManager@@QAEXPAVCDC@@HHHHPAVCPen@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportPaintManager.cpp
