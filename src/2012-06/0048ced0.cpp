// from server: 100% by auto
// roc 2012-06 0048ced0  unit: CRobloxDoc  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0048ced0
//
// 0048ced0  8b442404             mov eax, dword ptr [esp + 4]
// 0048ced4  8b542408             mov edx, dword ptr [esp + 8]
// 0048ced8  50                   push eax
// 0048ced9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0048cedc  52                   push edx
// 0048cedd  6880000000           push 0x80
// 0048cee2  50                   push eax
// 0048cee3  ff15043cb200         call dword ptr [0xb23c04]
// 0048cee9  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?SetIcon@CWnd@@QAEPAUHICON__@@PAU2@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
