// from server: 100% by auto
// roc 2007-08 00555570  unit: RBX::GuiTarget  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00555570
//
// 00555570  8b442404             mov eax, dword ptr [esp + 4]
// 00555574  c70000000000         mov dword ptr [eax], 0
// 0055557a  c7400400000000       mov dword ptr [eax + 4], 0
// 00555581  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxautohidebar.cpp (function ?CalcSize@CPane@@UAE?AVCSize@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebar.cpp
