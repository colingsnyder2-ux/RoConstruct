// from server: 100% by auto
// roc 2007-08 0068f840  unit: CXTPDockingPane  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0068f840
//
// 0068f840  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0068f844  85c9                 test ecx, ecx
// 0068f846  7408                 je 0x68f850
// 0068f848  8b442408             mov eax, dword ptr [esp + 8]
// 0068f84c  85c0                 test eax, eax
// 0068f84e  7505                 jne 0x68f855
// 0068f850  e8cb06faff           call 0x62ff20
// 0068f855  8b09                 mov ecx, dword ptr [ecx]
// 0068f857  33d2                 xor edx, edx
// 0068f859  3b08                 cmp ecx, dword ptr [eax]
// 0068f85b  0f94c2               sete dl
// 0068f85e  8bc2                 mov eax, edx
// 0068f860  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\occmgr.cpp (function ??$CompareElements@PAVIControlSiteFactory@@PAV1@@@YGHPBQAVIControlSiteFactory@@0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/occmgr.cpp
