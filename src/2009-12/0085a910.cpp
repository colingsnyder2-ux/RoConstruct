// from server: 100% by auto
// roc 2009-12 0085a910  unit: CXTPStatusBar  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085a910
//
// 0085a910  83792000             cmp dword ptr [ecx + 0x20], 0
// 0085a914  7420                 je 0x85a936
// 0085a916  8b442404             mov eax, dword ptr [esp + 4]
// 0085a91a  33442408             xor eax, dword ptr [esp + 8]
// 0085a91e  a9000f0000           test eax, 0xf00
// 0085a923  7411                 je 0x85a936
// 0085a925  6a33                 push 0x33
// 0085a927  6a00                 push 0
// 0085a929  6a00                 push 0
// 0085a92b  6a00                 push 0
// 0085a92d  6a00                 push 0
// 0085a92f  6a00                 push 0
// 0085a931  e8f692f9ff           call 0x7f3c2c
// 0085a936  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?OnBarStyleChange@CStatusBar@@UAEXKK@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
