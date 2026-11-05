// from server: 100% by auto
// roc 2008-06 0078c580  unit: CXTPRichRender::XTextHost  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0078c580
//
// 0078c580  8b442404             mov eax, dword ptr [esp + 4]
// 0078c584  c70000000000         mov dword ptr [eax], 0
// 0078c58a  33c0                 xor eax, eax
// 0078c58c  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ?GetPropPageIDs@COleControl@@MAEPAU_GUID@@AAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
