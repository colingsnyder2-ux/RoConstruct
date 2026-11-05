// from server: 100% by auto
// roc 2008-06 0044df60  unit: CRobloxControlColorSelector  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044df60
//
// 0044df60  8b442408             mov eax, dword ptr [esp + 8]
// 0044df64  8b542404             mov edx, dword ptr [esp + 4]
// 0044df68  50                   push eax
// 0044df69  52                   push edx
// 0044df6a  51                   push ecx
// 0044df6b  ff152c2d8000         call dword ptr [0x802d2c]
// 0044df71  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxautohidebar.cpp (function ?PtInRect@CRect@@QBEHUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebar.cpp
