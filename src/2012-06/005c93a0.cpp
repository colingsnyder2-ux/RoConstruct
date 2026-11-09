// from server: 100% by auto
// roc 2012-06 005c93a0  unit: RBX::AdornRbxGfx  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005c93a0
//
// 005c93a0  8b442404             mov eax, dword ptr [esp + 4]
// 005c93a4  8b09                 mov ecx, dword ptr [ecx]
// 005c93a6  50                   push eax
// 005c93a7  51                   push ecx
// 005c93a8  ff15e421b200         call dword ptr [0xb221e4]
// 005c93ae  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?DeleteValue@CRegKey@ATL@@QAEJPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
