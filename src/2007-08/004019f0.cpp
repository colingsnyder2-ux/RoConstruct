// from server: 100% by auto
// roc 2007-08 004019f0  unit: VCContent::?$CComObject  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004019f0
//
// 004019f0  8b442408             mov eax, dword ptr [esp + 8]
// 004019f4  85c0                 test eax, eax
// 004019f6  7508                 jne 0x401a00
// 004019f8  b803400080           mov eax, 0x80004003
// 004019fd  c20800               ret 8
// 00401a00  c70001000000         mov dword ptr [eax], 1
// 00401a06  33c0                 xor eax, eax
// 00401a08  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?GetTypeInfoCount@XAccessible@CWnd@@UAGJPAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
