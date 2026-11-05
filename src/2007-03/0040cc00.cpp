// from server: 100% by auto
// roc 2007-03 0040cc00  unit: seg_00400000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0040cc00
//
// 0040cc00  8b442408             mov eax, dword ptr [esp + 8]
// 0040cc04  85c0                 test eax, eax
// 0040cc06  7508                 jne 0x40cc10
// 0040cc08  b803400080           mov eax, 0x80004003
// 0040cc0d  c20800               ret 8
// 0040cc10  c70001000000         mov dword ptr [eax], 1
// 0040cc16  33c0                 xor eax, eax
// 0040cc18  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\wincore.cpp (function ?GetTypeInfoCount@XAccessible@CWnd@@UAGJPAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/wincore.cpp
