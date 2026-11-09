// from server: 100% by auto
// roc 2007-08 00401c90  unit: VCWorkspace::?$CComObject  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401c90
//
// 00401c90  56                   push esi
// 00401c91  8bf1                 mov esi, ecx
// 00401c93  8b0e                 mov ecx, dword ptr [esi]
// 00401c95  33c0                 xor eax, eax
// 00401c97  85c9                 test ecx, ecx
// 00401c99  740d                 je 0x401ca8
// 00401c9b  51                   push ecx
// 00401c9c  ff1508d07700         call dword ptr [0x77d008]
// 00401ca2  c70600000000         mov dword ptr [esi], 0
// 00401ca8  5e                   pop esi
// 00401ca9  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appui3.cpp (function ?Close@CRegKey@ATL@@QAEJXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui3.cpp
