// from server: 100% by auto
// roc 2010-06 00455ef0  unit: VCContent::?$CComObject  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00455ef0
//
// 00455ef0  8b442408             mov eax, dword ptr [esp + 8]
// 00455ef4  85c0                 test eax, eax
// 00455ef6  7508                 jne 0x455f00
// 00455ef8  b803400080           mov eax, 0x80004003
// 00455efd  c20800               ret 8
// 00455f00  c70001000000         mov dword ptr [eax], 1
// 00455f06  33c0                 xor eax, eax
// 00455f08  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?GetTypeInfoCount@XAccessible@CWnd@@UAGJPAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
