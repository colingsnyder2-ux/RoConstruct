// from server: 100% by auto
// roc 2007-03 00401c80  unit: seg_00400000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401c80
//
// 00401c80  56                   push esi
// 00401c81  8bf1                 mov esi, ecx
// 00401c83  8b0e                 mov ecx, dword ptr [esi]
// 00401c85  33c0                 xor eax, eax
// 00401c87  85c9                 test ecx, ecx
// 00401c89  740d                 je 0x401c98
// 00401c8b  51                   push ecx
// 00401c8c  ff152cd07700         call dword ptr [0x77d02c]
// 00401c92  c70600000000         mov dword ptr [esi], 0
// 00401c98  5e                   pop esi
// 00401c99  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appui3.cpp (function ?Close@CRegKey@ATL@@QAEJXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui3.cpp
