// from server: 100% by auto
// roc 2009-12 008704c0  unit: CXTPNewToolbarDlg  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008704c0
//
// 008704c0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008704c4  85c9                 test ecx, ecx
// 008704c6  7408                 je 0x8704d0
// 008704c8  8b442408             mov eax, dword ptr [esp + 8]
// 008704cc  85c0                 test eax, eax
// 008704ce  7505                 jne 0x8704d5
// 008704d0  e83736f8ff           call 0x7f3b0c
// 008704d5  8b09                 mov ecx, dword ptr [ecx]
// 008704d7  33d2                 xor edx, edx
// 008704d9  3b08                 cmp ecx, dword ptr [eax]
// 008704db  0f94c2               sete dl
// 008704de  8bc2                 mov eax, edx
// 008704e0  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\occmgr.cpp (function ??$CompareElements@PAVIControlSiteFactory@@PAV1@@@YGHPBQAVIControlSiteFactory@@0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/occmgr.cpp
