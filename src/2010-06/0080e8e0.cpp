// from server: 100% by auto
// roc 2010-06 0080e8e0  unit: CXTPStatusBar  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080e8e0
//
// 0080e8e0  83792000             cmp dword ptr [ecx + 0x20], 0
// 0080e8e4  7420                 je 0x80e906
// 0080e8e6  8b442404             mov eax, dword ptr [esp + 4]
// 0080e8ea  33442408             xor eax, dword ptr [esp + 8]
// 0080e8ee  a9000f0000           test eax, 0xf00
// 0080e8f3  7411                 je 0x80e906
// 0080e8f5  6a33                 push 0x33
// 0080e8f7  6a00                 push 0
// 0080e8f9  6a00                 push 0
// 0080e8fb  6a00                 push 0
// 0080e8fd  6a00                 push 0
// 0080e8ff  6a00                 push 0
// 0080e901  e86694f9ff           call 0x7a7d6c
// 0080e906  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\barstat.cpp (function ?OnBarStyleChange@CStatusBar@@UAEXKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/barstat.cpp
