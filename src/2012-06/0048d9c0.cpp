// from server: 100% by auto
// roc 2012-06 0048d9c0  unit: VCRbxObject::?$CComObjectNoLock  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0048d9c0
//
// 0048d9c0  8b442408             mov eax, dword ptr [esp + 8]
// 0048d9c4  85c0                 test eax, eax
// 0048d9c6  7508                 jne 0x48d9d0
// 0048d9c8  b803400080           mov eax, 0x80004003
// 0048d9cd  c20800               ret 8
// 0048d9d0  c70001000000         mov dword ptr [eax], 1
// 0048d9d6  33c0                 xor eax, eax
// 0048d9d8  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?GetTypeInfoCount@XAccessible@CWnd@@UAGJPAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
