// from server: 100% by auto
// roc 2007-08 00644150  unit: CXTPCommandBar  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00644150
//
// 00644150  8b442404             mov eax, dword ptr [esp + 4]
// 00644154  c70000000000         mov dword ptr [eax], 0
// 0064415a  c7400400000000       mov dword ptr [eax + 4], 0
// 00644161  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxautohidedocksite.cpp (function ?StretchPane@CBasePane@@UAE?AVCSize@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidedocksite.cpp
