// from server: 100% by auto
// roc 2008-06 004112c0  unit: boost::bad_weak_ptr  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004112c0
//
// 004112c0  8b442404             mov eax, dword ptr [esp + 4]
// 004112c4  85c0                 test eax, eax
// 004112c6  7515                 jne 0x4112dd
// 004112c8  8b542408             mov edx, dword ptr [esp + 8]
// 004112cc  52                   push edx
// 004112cd  50                   push eax
// 004112ce  8b4120               mov eax, dword ptr [ecx + 0x20]
// 004112d1  6a30                 push 0x30
// 004112d3  50                   push eax
// 004112d4  ff15142e8000         call dword ptr [0x802e14]
// 004112da  c20800               ret 8
// 004112dd  8b542408             mov edx, dword ptr [esp + 8]
// 004112e1  8b4004               mov eax, dword ptr [eax + 4]
// 004112e4  52                   push edx
// 004112e5  50                   push eax
// 004112e6  8b4120               mov eax, dword ptr [ecx + 0x20]
// 004112e9  6a30                 push 0x30
// 004112eb  50                   push eax
// 004112ec  ff15142e8000         call dword ptr [0x802e14]
// 004112f2  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?SetFont@CWnd@@QAEXPAVCFont@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
