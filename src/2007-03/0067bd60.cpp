// from server: 100% by auto
// roc 2007-03 0067bd60  unit: seg_00670000  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067bd60
//
// 0067bd60  83792000             cmp dword ptr [ecx + 0x20], 0
// 0067bd64  7420                 je 0x67bd86
// 0067bd66  8b442404             mov eax, dword ptr [esp + 4]
// 0067bd6a  33442408             xor eax, dword ptr [esp + 8]
// 0067bd6e  a9000f0000           test eax, 0xf00
// 0067bd73  7411                 je 0x67bd86
// 0067bd75  6a33                 push 0x33
// 0067bd77  6a00                 push 0
// 0067bd79  6a00                 push 0
// 0067bd7b  6a00                 push 0
// 0067bd7d  6a00                 push 0
// 0067bd7f  6a00                 push 0
// 0067bd81  e83027faff           call 0x61e4b6
// 0067bd86  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?OnBarStyleChange@CStatusBar@@UAEXKK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
