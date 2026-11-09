// from server: 100% by auto
// roc 2011-06 0047d1c0  unit: CRobloxDoc  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0047d1c0
//
// 0047d1c0  8b442404             mov eax, dword ptr [esp + 4]
// 0047d1c4  8b542408             mov edx, dword ptr [esp + 8]
// 0047d1c8  50                   push eax
// 0047d1c9  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0047d1cc  52                   push edx
// 0047d1cd  6880000000           push 0x80
// 0047d1d2  50                   push eax
// 0047d1d3  ff15c019a400         call dword ptr [0xa419c0]
// 0047d1d9  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbasetabbedpane.cpp (function ?SetIcon@CWnd@@QAEPAUHICON__@@PAU2@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabbedpane.cpp
