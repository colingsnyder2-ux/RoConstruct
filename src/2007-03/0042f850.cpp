// from server: 100% by auto
// roc 2007-03 0042f850  unit: seg_00420000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0042f850
//
// 0042f850  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0042f854  8b542408             mov edx, dword ptr [esp + 8]
// 0042f858  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0042f85b  50                   push eax
// 0042f85c  8b442408             mov eax, dword ptr [esp + 8]
// 0042f860  52                   push edx
// 0042f861  50                   push eax
// 0042f862  51                   push ecx
// 0042f863  ff1550ee7700         call dword ptr [0x77ee50]
// 0042f869  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?PostMessageA@CWnd@@QAEHIIJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
