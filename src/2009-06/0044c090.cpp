// from server: 100% by auto
// roc 2009-06 0044c090  unit: CRobloxControlColorSelector  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044c090
//
// 0044c090  8b442408             mov eax, dword ptr [esp + 8]
// 0044c094  8b542404             mov edx, dword ptr [esp + 4]
// 0044c098  50                   push eax
// 0044c099  52                   push edx
// 0044c09a  51                   push ecx
// 0044c09b  ff15c0ed8900         call dword ptr [0x89edc0]
// 0044c0a1  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxautohidebar.cpp (function ?PtInRect@CRect@@QBEHUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebar.cpp
