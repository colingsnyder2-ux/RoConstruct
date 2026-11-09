// from server: 100% by auto
// roc 2007-08 00680130  unit: CXTPBufferDC  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00680130
//
// 00680130  8b442408             mov eax, dword ptr [esp + 8]
// 00680134  8b542404             mov edx, dword ptr [esp + 4]
// 00680138  50                   push eax
// 00680139  8b4104               mov eax, dword ptr [ecx + 4]
// 0068013c  52                   push edx
// 0068013d  50                   push eax
// 0068013e  ff15d4d07700         call dword ptr [0x77d0d4]
// 00680144  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\bardock.cpp (function ?DeleteMenu@CMenu@@QAEHII@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardock.cpp
