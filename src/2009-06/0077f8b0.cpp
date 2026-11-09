// from server: 100% by auto
// roc 2009-06 0077f8b0  unit: CXTPStatusBar  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077f8b0
//
// 0077f8b0  83792000             cmp dword ptr [ecx + 0x20], 0
// 0077f8b4  7420                 je 0x77f8d6
// 0077f8b6  8b442404             mov eax, dword ptr [esp + 4]
// 0077f8ba  33442408             xor eax, dword ptr [esp + 8]
// 0077f8be  a9000f0000           test eax, 0xf00
// 0077f8c3  7411                 je 0x77f8d6
// 0077f8c5  6a33                 push 0x33
// 0077f8c7  6a00                 push 0
// 0077f8c9  6a00                 push 0
// 0077f8cb  6a00                 push 0
// 0077f8cd  6a00                 push 0
// 0077f8cf  6a00                 push 0
// 0077f8d1  e82e95f9ff           call 0x718e04
// 0077f8d6  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\barstat.cpp (function ?OnBarStyleChange@CStatusBar@@UAEXKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/barstat.cpp
