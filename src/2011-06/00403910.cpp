// from server: 100% by auto
// roc 2011-06 00403910  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403910
//
// 00403910  8b542404             mov edx, dword ptr [esp + 4]
// 00403914  6a04                 push 4
// 00403916  8d44240c             lea eax, [esp + 0xc]
// 0040391a  50                   push eax
// 0040391b  8b01                 mov eax, dword ptr [ecx]
// 0040391d  6a04                 push 4
// 0040391f  6a00                 push 0
// 00403921  52                   push edx
// 00403922  50                   push eax
// 00403923  ff154400a400         call dword ptr [0xa40044]
// 00403929  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?SetDWORDValue@CRegKey@ATL@@QAEJPBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
