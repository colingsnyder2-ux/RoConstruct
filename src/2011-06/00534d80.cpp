// from server: 100% by auto
// roc 2011-06 00534d80  unit: seg_00530000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00534d80
//
// 00534d80  8b442404             mov eax, dword ptr [esp + 4]
// 00534d84  8b09                 mov ecx, dword ptr [ecx]
// 00534d86  50                   push eax
// 00534d87  51                   push ecx
// 00534d88  ff15a803a400         call dword ptr [0xa403a8]
// 00534d8e  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?DeleteValue@CRegKey@ATL@@QAEJPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
