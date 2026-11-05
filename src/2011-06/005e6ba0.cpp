// from server: 100% by auto
// roc 2011-06 005e6ba0  unit: RBX::DataModel  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005e6ba0
//
// 005e6ba0  8b09                 mov ecx, dword ptr [ecx]
// 005e6ba2  85c9                 test ecx, ecx
// 005e6ba4  7409                 je 0x5e6baf
// 005e6ba6  8b01                 mov eax, dword ptr [ecx]
// 005e6ba8  8b5004               mov edx, dword ptr [eax + 4]
// 005e6bab  6a01                 push 1
// 005e6bad  ffd2                 call edx
// 005e6baf  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ??1CSettingsStoreSP@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
