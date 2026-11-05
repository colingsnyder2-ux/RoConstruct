// from server: 100% by auto
// roc 2010-06 0084e660  unit: CXTPRibbonBar  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0084e660
//
// 0084e660  8b442418             mov eax, dword ptr [esp + 0x18]
// 0084e664  83ec08               sub esp, 8
// 0084e667  53                   push ebx
// 0084e668  55                   push ebp
// 0084e669  56                   push esi
// 0084e66a  8b742418             mov esi, dword ptr [esp + 0x18]
// 0084e66e  57                   push edi
// 0084e66f  50                   push eax
// 0084e670  8bce                 mov ecx, esi
// 0084e672  e8cfee1200           call 0x97d546
// 0084e677  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0084e67b  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0084e67f  53                   push ebx
// 0084e680  55                   push ebp
// 0084e681  8d4c2418             lea ecx, [esp + 0x18]
// 0084e685  51                   push ecx
// 0084e686  8bce                 mov ecx, esi
// 0084e688  8bf8                 mov edi, eax
// 0084e68a  e8eda1f5ff           call 0x7a887c
// 0084e68f  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0084e693  8b442428             mov eax, dword ptr [esp + 0x28]
// 0084e697  03da                 add ebx, edx
// 0084e699  53                   push ebx
// 0084e69a  03e8                 add ebp, eax
// 0084e69c  55                   push ebp
// 0084e69d  8bce                 mov ecx, esi
// 0084e69f  e8d2a1f5ff           call 0x7a8876
// 0084e6a4  57                   push edi
// 0084e6a5  8bce                 mov ecx, esi
// 0084e6a7  e89aee1200           call 0x97d546
// 0084e6ac  5f                   pop edi
// 0084e6ad  5e                   pop esi
// 0084e6ae  5d                   pop ebp
// 0084e6af  5b                   pop ebx
// 0084e6b0  83c408               add esp, 8
// 0084e6b3  c21800               ret 0x18
// library xtp-13.2.1/Source\ReportControl\XTPReportPaintManager.cpp (function ?Line@CXTPReportPaintManager@@QAEXPAVCDC@@HHHHPAVCPen@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportPaintManager.cpp
