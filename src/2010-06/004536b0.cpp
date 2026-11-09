// from server: 100% by auto
// roc 2010-06 004536b0  unit: CRobloxControlColorSelector  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004536b0
//
// 004536b0  8b442408             mov eax, dword ptr [esp + 8]
// 004536b4  8b542404             mov edx, dword ptr [esp + 4]
// 004536b8  50                   push eax
// 004536b9  52                   push edx
// 004536ba  51                   push ecx
// 004536bb  ff15e0bb9e00         call dword ptr [0x9ebbe0]
// 004536c1  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxautohidebar.cpp (function ?PtInRect@CRect@@QBEHUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebar.cpp
