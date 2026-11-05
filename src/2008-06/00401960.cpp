// from server: 100% by auto
// roc 2008-06 00401960  unit: VCContent::?$CComObject  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401960
//
// 00401960  8b442408             mov eax, dword ptr [esp + 8]
// 00401964  85c0                 test eax, eax
// 00401966  7508                 jne 0x401970
// 00401968  b803400080           mov eax, 0x80004003
// 0040196d  c20800               ret 8
// 00401970  c70001000000         mov dword ptr [eax], 1
// 00401976  33c0                 xor eax, eax
// 00401978  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?GetTypeInfoCount@XAccessible@CWnd@@UAGJPAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
