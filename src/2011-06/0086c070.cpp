// from server: 100% by auto
// roc 2011-06 0086c070  unit: CXTPStatusBar  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086c070
//
// 0086c070  83792000             cmp dword ptr [ecx + 0x20], 0
// 0086c074  7420                 je 0x86c096
// 0086c076  8b442404             mov eax, dword ptr [esp + 4]
// 0086c07a  33442408             xor eax, dword ptr [esp + 8]
// 0086c07e  a9000f0000           test eax, 0xf00
// 0086c083  7411                 je 0x86c096
// 0086c085  6a33                 push 0x33
// 0086c087  6a00                 push 0
// 0086c089  6a00                 push 0
// 0086c08b  6a00                 push 0
// 0086c08d  6a00                 push 0
// 0086c08f  6a00                 push 0
// 0086c091  e894e3f9ff           call 0x80a42a
// 0086c096  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\barstat.cpp (function ?OnBarStyleChange@CStatusBar@@UAEXKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/barstat.cpp
