// from server: 100% by auto
// roc 2009-06 0046dda0  unit: VCContent::?$CComObject  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046dda0
//
// 0046dda0  8b442408             mov eax, dword ptr [esp + 8]
// 0046dda4  85c0                 test eax, eax
// 0046dda6  7508                 jne 0x46ddb0
// 0046dda8  b803400080           mov eax, 0x80004003
// 0046ddad  c20800               ret 8
// 0046ddb0  c70001000000         mov dword ptr [eax], 1
// 0046ddb6  33c0                 xor eax, eax
// 0046ddb8  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?GetTypeInfoCount@XAccessible@CWnd@@UAGJPAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
