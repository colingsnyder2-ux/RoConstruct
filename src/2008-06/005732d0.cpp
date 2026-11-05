// from server: 100% by auto
// roc 2008-06 005732d0  unit: RBX::GuiTarget  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005732d0
//
// 005732d0  8b442404             mov eax, dword ptr [esp + 4]
// 005732d4  c70000000000         mov dword ptr [eax], 0
// 005732da  c7400400000000       mov dword ptr [eax + 4], 0
// 005732e1  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxautohidebar.cpp (function ?CalcSize@CPane@@UAE?AVCSize@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebar.cpp
