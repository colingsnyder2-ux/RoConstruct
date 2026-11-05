// from server: 100% by auto
// roc 2010-06 0069ff90  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0069ff90
//
// 0069ff90  8b01                 mov eax, dword ptr [ecx]
// 0069ff92  50                   push eax
// 0069ff93  ff15f4bc9e00         call dword ptr [0x9ebcf4]
// 0069ff99  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
