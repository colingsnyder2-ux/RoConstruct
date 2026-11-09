// from server: 100% by auto
// roc 2012-06 00404460  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404460
//
// 00404460  8b542404             mov edx, dword ptr [esp + 4]
// 00404464  6a04                 push 4
// 00404466  8d44240c             lea eax, [esp + 0xc]
// 0040446a  50                   push eax
// 0040446b  8b01                 mov eax, dword ptr [ecx]
// 0040446d  6a04                 push 4
// 0040446f  6a00                 push 0
// 00404471  52                   push edx
// 00404472  50                   push eax
// 00404473  ff151020b200         call dword ptr [0xb22010]
// 00404479  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?SetDWORDValue@CRegKey@ATL@@QAEJPBDK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
