// from server: 100% by auto
// roc 2010-06 008939c0  unit: CXTPRichRender::XTextHost  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008939c0
//
// 008939c0  8b442404             mov eax, dword ptr [esp + 4]
// 008939c4  c70000000000         mov dword ptr [eax], 0
// 008939ca  33c0                 xor eax, eax
// 008939cc  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ?GetPropPageIDs@COleControl@@MAEPAU_GUID@@AAK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
