// from server: 100% by auto
// roc 2007-03 00401cf0  unit: seg_00400000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401cf0
//
// 00401cf0  8b542404             mov edx, dword ptr [esp + 4]
// 00401cf4  6a04                 push 4
// 00401cf6  8d44240c             lea eax, [esp + 0xc]
// 00401cfa  50                   push eax
// 00401cfb  8b01                 mov eax, dword ptr [ecx]
// 00401cfd  6a04                 push 4
// 00401cff  6a00                 push 0
// 00401d01  52                   push edx
// 00401d02  50                   push eax
// 00401d03  ff1520d07700         call dword ptr [0x77d020]
// 00401d09  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?SetDWORDValue@CRegKey@ATL@@QAEJPBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
