// from server: 100% by auto
// roc 2011-06 008b89a0  unit: CXTPReportHyperlinks  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b89a0
//
// 008b89a0  8b01                 mov eax, dword ptr [ecx]
// 008b89a2  85c0                 test eax, eax
// 008b89a4  7407                 je 0x8b89ad
// 008b89a6  50                   push eax
// 008b89a7  ff150400a400         call dword ptr [0xa40004]
// 008b89ad  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgtempl.cpp (function ??1CDialogTemplate@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgtempl.cpp
