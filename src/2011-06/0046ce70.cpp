// from server: 100% by auto
// roc 2011-06 0046ce70  unit: CRobloxControlColorSelector  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0046ce70
//
// 0046ce70  8b442408             mov eax, dword ptr [esp + 8]
// 0046ce74  8b542404             mov edx, dword ptr [esp + 4]
// 0046ce78  50                   push eax
// 0046ce79  52                   push edx
// 0046ce7a  51                   push ecx
// 0046ce7b  ff15101ca400         call dword ptr [0xa41c10]
// 0046ce81  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxautohidebar.cpp (function ?PtInRect@CRect@@QBEHUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxautohidebar.cpp
