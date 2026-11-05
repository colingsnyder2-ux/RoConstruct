// from server: 100% by auto
// roc 2012-06 007e7dd0  unit: RBX::GuiTarget  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007e7dd0
//
// 007e7dd0  8b09                 mov ecx, dword ptr [ecx]
// 007e7dd2  85c9                 test ecx, ecx
// 007e7dd4  7409                 je 0x7e7ddf
// 007e7dd6  8b01                 mov eax, dword ptr [ecx]
// 007e7dd8  8b5004               mov edx, dword ptr [eax + 4]
// 007e7ddb  6a01                 push 1
// 007e7ddd  ffd2                 call edx
// 007e7ddf  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ??1CSettingsStoreSP@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
