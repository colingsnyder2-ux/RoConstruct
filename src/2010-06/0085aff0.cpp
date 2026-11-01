// from server: 100% by auto
// roc 2010-06 0085aff0  unit: CXTPReportHeaderDropWnd  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085aff0
//
// 0085aff0  8b4160               mov eax, dword ptr [ecx + 0x60]
// 0085aff3  99                   cdq 
// 0085aff4  2bc2                 sub eax, edx
// 0085aff6  8b542408             mov edx, dword ptr [esp + 8]
// 0085affa  6a51                 push 0x51
// 0085affc  6a00                 push 0
// 0085affe  d1f8                 sar eax, 1
// 0085b000  2bd0                 sub edx, eax
// 0085b002  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0085b006  6a00                 push 0
// 0085b008  52                   push edx
// 0085b009  8b1578c79e00         mov edx, dword ptr [0x9ec778]
// 0085b00f  83c0fa               add eax, -6
// 0085b012  50                   push eax
// 0085b013  52                   push edx
// 0085b014  e853cdf4ff           call 0x7a7d6c
// 0085b019  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\ReportControl\XTPReportDragDrop.cpp (function ?SetWindowPos@CXTPReportHeaderDropWnd@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/ReportControl/XTPReportDragDrop.cpp
