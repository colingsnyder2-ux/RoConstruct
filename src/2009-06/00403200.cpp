// from server: 100% by auto
// roc 2009-06 00403200  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00403200
//
// 00403200  8b542404             mov edx, dword ptr [esp + 4]
// 00403204  6a04                 push 4
// 00403206  8d44240c             lea eax, [esp + 0xc]
// 0040320a  50                   push eax
// 0040320b  8b01                 mov eax, dword ptr [ecx]
// 0040320d  6a04                 push 4
// 0040320f  6a00                 push 0
// 00403211  52                   push edx
// 00403212  50                   push eax
// 00403213  ff1514e08900         call dword ptr [0x89e014]
// 00403219  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?SetDWORDValue@CRegKey@ATL@@QAEJPBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
