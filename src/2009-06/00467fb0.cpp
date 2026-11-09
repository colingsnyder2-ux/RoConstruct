// from server: 100% by auto
// roc 2009-06 00467fb0  unit: CSettingsDialog  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00467fb0
//
// 00467fb0  8b01                 mov eax, dword ptr [ecx]
// 00467fb2  50                   push eax
// 00467fb3  ff1584ef8900         call dword ptr [0x89ef84]
// 00467fb9  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
