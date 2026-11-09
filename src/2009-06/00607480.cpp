// from server: 100% by auto
// roc 2009-06 00607480  unit: RBX::GuiTarget  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00607480
//
// 00607480  8b442404             mov eax, dword ptr [esp + 4]
// 00607484  c70000000000         mov dword ptr [eax], 0
// 0060748a  c7400400000000       mov dword ptr [eax + 4], 0
// 00607491  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxautohidebar.cpp (function ?CalcSize@CPane@@UAE?AVCSize@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebar.cpp
