// from server: 100% by auto
// roc 2007-08 00692340  unit: CXTPStatusBar  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00692340
//
// 00692340  83792000             cmp dword ptr [ecx + 0x20], 0
// 00692344  7420                 je 0x692366
// 00692346  8b442404             mov eax, dword ptr [esp + 4]
// 0069234a  33442408             xor eax, dword ptr [esp + 8]
// 0069234e  a9000f0000           test eax, 0xf00
// 00692353  7411                 je 0x692366
// 00692355  6a33                 push 0x33
// 00692357  6a00                 push 0
// 00692359  6a00                 push 0
// 0069235b  6a00                 push 0
// 0069235d  6a00                 push 0
// 0069235f  6a00                 push 0
// 00692361  e8c8dcf9ff           call 0x63002e
// 00692366  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?OnBarStyleChange@CStatusBar@@UAEXKK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
