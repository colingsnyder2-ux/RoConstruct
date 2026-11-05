// from server: 100% by auto
// roc 2011-06 00407100  unit: VCRbxObject::?$CComObjectNoLock  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00407100
//
// 00407100  8b442408             mov eax, dword ptr [esp + 8]
// 00407104  85c0                 test eax, eax
// 00407106  7508                 jne 0x407110
// 00407108  b803400080           mov eax, 0x80004003
// 0040710d  c20800               ret 8
// 00407110  c70001000000         mov dword ptr [eax], 1
// 00407116  33c0                 xor eax, eax
// 00407118  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?GetTypeInfoCount@XAccessible@CWnd@@UAGJPAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
