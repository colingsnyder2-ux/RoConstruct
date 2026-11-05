// from server: 100% by auto
// roc 2008-06 006b55f0  unit: CXTPCommandBar  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006b55f0
//
// 006b55f0  8b442404             mov eax, dword ptr [esp + 4]
// 006b55f4  c70000000000         mov dword ptr [eax], 0
// 006b55fa  c7400400000000       mov dword ptr [eax + 4], 0
// 006b5601  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxautohidedocksite.cpp (function ?StretchPane@CBasePane@@UAE?AVCSize@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidedocksite.cpp
