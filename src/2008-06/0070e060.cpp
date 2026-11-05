// from server: 100% by auto
// roc 2008-06 0070e060  unit: CXTPStatusBar  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0070e060
//
// 0070e060  83792000             cmp dword ptr [ecx + 0x20], 0
// 0070e064  7420                 je 0x70e086
// 0070e066  8b442404             mov eax, dword ptr [esp + 4]
// 0070e06a  33442408             xor eax, dword ptr [esp + 8]
// 0070e06e  a9000f0000           test eax, 0xf00
// 0070e073  7411                 je 0x70e086
// 0070e075  6a33                 push 0x33
// 0070e077  6a00                 push 0
// 0070e079  6a00                 push 0
// 0070e07b  6a00                 push 0
// 0070e07d  6a00                 push 0
// 0070e07f  6a00                 push 0
// 0070e081  e8c029f9ff           call 0x6a0a46
// 0070e086  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\barstat.cpp (function ?OnBarStyleChange@CStatusBar@@UAEXKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/barstat.cpp
