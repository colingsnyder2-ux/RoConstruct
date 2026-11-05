// from server: 100% by auto
// roc 2007-03 006c0f20  unit: seg_006c0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c0f20
//
// 006c0f20  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006c0f24  85c9                 test ecx, ecx
// 006c0f26  7408                 je 0x6c0f30
// 006c0f28  8b442408             mov eax, dword ptr [esp + 8]
// 006c0f2c  85c0                 test eax, eax
// 006c0f2e  7505                 jne 0x6c0f35
// 006c0f30  e879d4f5ff           call 0x61e3ae
// 006c0f35  8b09                 mov ecx, dword ptr [ecx]
// 006c0f37  33d2                 xor edx, edx
// 006c0f39  3b08                 cmp ecx, dword ptr [eax]
// 006c0f3b  0f94c2               sete dl
// 006c0f3e  8bc2                 mov eax, edx
// 006c0f40  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\occmgr.cpp (function ??$CompareElements@PAVIControlSiteFactory@@PAV1@@@YGHPBQAVIControlSiteFactory@@0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/occmgr.cpp
