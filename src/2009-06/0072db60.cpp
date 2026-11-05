// from server: 100% by auto
// roc 2009-06 0072db60  unit: CXTPCommandBar  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0072db60
//
// 0072db60  8b442404             mov eax, dword ptr [esp + 4]
// 0072db64  c70000000000         mov dword ptr [eax], 0
// 0072db6a  c7400400000000       mov dword ptr [eax + 4], 0
// 0072db71  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxautohidedocksite.cpp (function ?StretchPane@CBasePane@@UAE?AVCSize@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidedocksite.cpp
