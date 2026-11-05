// from server: 100% by auto
// roc 2010-06 00402f20  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402f20
//
// 00402f20  8b542404             mov edx, dword ptr [esp + 4]
// 00402f24  6a04                 push 4
// 00402f26  8d44240c             lea eax, [esp + 0xc]
// 00402f2a  50                   push eax
// 00402f2b  8b01                 mov eax, dword ptr [ecx]
// 00402f2d  6a04                 push 4
// 00402f2f  6a00                 push 0
// 00402f31  52                   push edx
// 00402f32  50                   push eax
// 00402f33  ff151ca09e00         call dword ptr [0x9ea01c]
// 00402f39  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?SetDWORDValue@CRegKey@ATL@@QAEJPBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
