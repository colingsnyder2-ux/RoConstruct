// from server: 100% by auto
// roc 2007-03 006394e0  unit: seg_00630000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006394e0
//
// 006394e0  8b442404             mov eax, dword ptr [esp + 4]
// 006394e4  c70000000000         mov dword ptr [eax], 0
// 006394ea  c7400400000000       mov dword ptr [eax + 4], 0
// 006394f1  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxautohidedocksite.cpp (function ?StretchPane@CBasePane@@UAE?AVCSize@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidedocksite.cpp
