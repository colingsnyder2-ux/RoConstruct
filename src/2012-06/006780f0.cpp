// from server: 100% by auto
// roc 2012-06 006780f0  unit: RBX::XVGfxBinding::XV?$mf2::V?$bind_t::?$callable_slot  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006780f0
//
// 006780f0  8b442404             mov eax, dword ptr [esp + 4]
// 006780f4  a35421e000           mov dword ptr [0xe02154], eax
// 006780f9  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbutton.cpp (function ?EnableWindowsTheming@CMFCButton@@SGXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbutton.cpp
