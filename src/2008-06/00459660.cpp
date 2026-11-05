// from server: 100% by auto
// roc 2008-06 00459660  unit: CRobloxView  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00459660
//
// 00459660  8b09                 mov ecx, dword ptr [ecx]
// 00459662  85c9                 test ecx, ecx
// 00459664  7409                 je 0x45966f
// 00459666  8b01                 mov eax, dword ptr [ecx]
// 00459668  8b5004               mov edx, dword ptr [eax + 4]
// 0045966b  6a01                 push 1
// 0045966d  ffd2                 call edx
// 0045966f  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ??1CSettingsStoreSP@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
