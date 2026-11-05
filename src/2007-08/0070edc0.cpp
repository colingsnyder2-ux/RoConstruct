// from server: 100% by auto
// roc 2007-08 0070edc0  unit: CXTPRichRender::XTextHost  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0070edc0
//
// 0070edc0  8b442404             mov eax, dword ptr [esp + 4]
// 0070edc4  c70000000000         mov dword ptr [eax], 0
// 0070edca  33c0                 xor eax, eax
// 0070edcc  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ?GetPropPageIDs@COleControl@@MAEPAU_GUID@@AAK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
