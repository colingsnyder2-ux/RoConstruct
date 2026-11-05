// from server: 100% by auto
// roc 2011-06 008ec570  unit: CXTPRichRender::XTextHost  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008ec570
//
// 008ec570  8b442404             mov eax, dword ptr [esp + 4]
// 008ec574  c70000000000         mov dword ptr [eax], 0
// 008ec57a  33c0                 xor eax, eax
// 008ec57c  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ?GetPropPageIDs@COleControl@@MAEPAU_GUID@@AAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
