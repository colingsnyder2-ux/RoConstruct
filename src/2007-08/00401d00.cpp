// from server: 100% by auto
// roc 2007-08 00401d00  unit: VCWorkspace::?$CComObject  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401d00
//
// 00401d00  8b542404             mov edx, dword ptr [esp + 4]
// 00401d04  6a04                 push 4
// 00401d06  8d44240c             lea eax, [esp + 0xc]
// 00401d0a  50                   push eax
// 00401d0b  8b01                 mov eax, dword ptr [ecx]
// 00401d0d  6a04                 push 4
// 00401d0f  6a00                 push 0
// 00401d11  52                   push edx
// 00401d12  50                   push eax
// 00401d13  ff1514d07700         call dword ptr [0x77d014]
// 00401d19  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?SetDWORDValue@CRegKey@ATL@@QAEJPBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
