// from server: 100% by auto
// roc 2007-03 006f1e60  unit: seg_006f0000  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f1e60
//
// 006f1e60  8b442404             mov eax, dword ptr [esp + 4]
// 006f1e64  c70000000000         mov dword ptr [eax], 0
// 006f1e6a  33c0                 xor eax, eax
// 006f1e6c  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ?GetPropPageIDs@COleControl@@MAEPAU_GUID@@AAK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
