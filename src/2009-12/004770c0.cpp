// from server: 100% by auto
// roc 2009-12 004770c0  unit: VCContent::?$CComObject  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004770c0
//
// 004770c0  8b442408             mov eax, dword ptr [esp + 8]
// 004770c4  85c0                 test eax, eax
// 004770c6  7508                 jne 0x4770d0
// 004770c8  b803400080           mov eax, 0x80004003
// 004770cd  c20800               ret 8
// 004770d0  c70001000000         mov dword ptr [eax], 1
// 004770d6  33c0                 xor eax, eax
// 004770d8  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?GetTypeInfoCount@XAccessible@CWnd@@UAGJPAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
