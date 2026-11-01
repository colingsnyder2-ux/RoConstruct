// from server: 100% by auto
// roc 2009-12 00402ed0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402ed0
//
// 00402ed0  8b542404             mov edx, dword ptr [esp + 4]
// 00402ed4  6a04                 push 4
// 00402ed6  8d44240c             lea eax, [esp + 0xc]
// 00402eda  50                   push eax
// 00402edb  8b01                 mov eax, dword ptr [ecx]
// 00402edd  6a04                 push 4
// 00402edf  6a00                 push 0
// 00402ee1  52                   push edx
// 00402ee2  50                   push eax
// 00402ee3  ff1514b09800         call dword ptr [0x98b014]
// 00402ee9  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?SetDWORDValue@CRegKey@ATL@@QAEJPBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
