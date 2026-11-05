// from server: 100% by auto
// roc 2010-06 007bb6c0  unit: CXTPCommandBar  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bb6c0
//
// 007bb6c0  51                   push ecx
// 007bb6c1  8d442408             lea eax, [esp + 8]
// 007bb6c5  50                   push eax
// 007bb6c6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007bb6ca  8d542404             lea edx, [esp + 4]
// 007bb6ce  52                   push edx
// 007bb6cf  50                   push eax
// 007bb6d0  e83b04ffff           call 0x7abb10
// 007bb6d5  85c0                 test eax, eax
// 007bb6d7  7504                 jne 0x7bb6dd
// 007bb6d9  59                   pop ecx
// 007bb6da  c20800               ret 8
// 007bb6dd  8b4804               mov ecx, dword ptr [eax + 4]
// 007bb6e0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007bb6e4  890a                 mov dword ptr [edx], ecx
// 007bb6e6  b801000000           mov eax, 1
// 007bb6eb  59                   pop ecx
// 007bb6ec  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcmdusagecount.cpp (function ?Lookup@?$CMap@IIII@@QBEHIAAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcmdusagecount.cpp
