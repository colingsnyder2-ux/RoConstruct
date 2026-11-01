// from server: 100% by auto
// roc 2011-06 00407490  unit: VCApp::?$CComObject  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00407490
//
// 00407490  56                   push esi
// 00407491  8bf1                 mov esi, ecx
// 00407493  807e0400             cmp byte ptr [esi + 4], 0
// 00407497  740d                 je 0x4074a6
// 00407499  8b06                 mov eax, dword ptr [esi]
// 0040749b  50                   push eax
// 0040749c  ff158003a400         call dword ptr [0xa40380]
// 004074a2  c6460400             mov byte ptr [esi + 4], 0
// 004074a6  5e                   pop esi
// 004074a7  c3                   ret 
// library atl-8.0/atl.cpp (function ??1?$CComCritSecLock@VCComCriticalSection@ATL@@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
