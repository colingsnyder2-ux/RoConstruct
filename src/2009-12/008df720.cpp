// from server: 100% by auto
// roc 2009-12 008df720  unit: CXTPRichRender::XTextHost  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008df720
//
// 008df720  8b442404             mov eax, dword ptr [esp + 4]
// 008df724  c70000000000         mov dword ptr [eax], 0
// 008df72a  33c0                 xor eax, eax
// 008df72c  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ?GetPropPageIDs@COleControl@@MAEPAU_GUID@@AAK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
