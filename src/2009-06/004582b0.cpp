// from server: 100% by auto
// roc 2009-06 004582b0  unit: CRobloxView  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004582b0
//
// 004582b0  8b09                 mov ecx, dword ptr [ecx]
// 004582b2  85c9                 test ecx, ecx
// 004582b4  7409                 je 0x4582bf
// 004582b6  8b01                 mov eax, dword ptr [ecx]
// 004582b8  8b5004               mov edx, dword ptr [eax + 4]
// 004582bb  6a01                 push 1
// 004582bd  ffd2                 call edx
// 004582bf  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ??1CSettingsStoreSP@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
