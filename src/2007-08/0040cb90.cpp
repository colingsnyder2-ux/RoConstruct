// from server: 100% by auto
// roc 2007-08 0040cb90  unit: boost::bad_weak_ptr  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040cb90
//
// 0040cb90  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040cb94  8b542408             mov edx, dword ptr [esp + 8]
// 0040cb98  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0040cb9b  50                   push eax
// 0040cb9c  8b442408             mov eax, dword ptr [esp + 8]
// 0040cba0  52                   push edx
// 0040cba1  50                   push eax
// 0040cba2  51                   push ecx
// 0040cba3  ff15d0ec7700         call dword ptr [0x77ecd0]
// 0040cba9  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?PostMessageA@CWnd@@QAEHIIJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
