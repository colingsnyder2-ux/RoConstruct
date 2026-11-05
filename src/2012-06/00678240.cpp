// from server: 100% by auto
// roc 2012-06 00678240  unit: RBX::XVGfxBinding::XV?$mf2::V?$bind_t::?$callable_slot  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00678240
//
// 00678240  8b442404             mov eax, dword ptr [esp + 4]
// 00678244  a3bc8be500           mov dword ptr [0xe58bbc], eax
// 00678249  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?EnableWindowsTheming@CMFCButton@@SGXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
