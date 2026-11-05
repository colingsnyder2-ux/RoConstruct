// from server: 100% by auto
// roc 2008-06 00401ce0  unit: VCWorkspace::?$CComObject  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401ce0
//
// 00401ce0  8b542404             mov edx, dword ptr [esp + 4]
// 00401ce4  6a04                 push 4
// 00401ce6  8d44240c             lea eax, [esp + 0xc]
// 00401cea  50                   push eax
// 00401ceb  8b01                 mov eax, dword ptr [ecx]
// 00401ced  6a04                 push 4
// 00401cef  6a00                 push 0
// 00401cf1  52                   push edx
// 00401cf2  50                   push eax
// 00401cf3  ff1514208000         call dword ptr [0x802014]
// 00401cf9  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?SetDWORDValue@CRegKey@ATL@@QAEJPBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
