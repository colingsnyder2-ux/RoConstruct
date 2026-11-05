// from server: 100% by auto
// roc 2010-06 00649520  unit: RBX::LaserTool  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00649520
//
// 00649520  8b01                 mov eax, dword ptr [ecx]
// 00649522  8b542404             mov edx, dword ptr [esp + 4]
// 00649526  8902                 mov dword ptr [edx], eax
// 00649528  8b4104               mov eax, dword ptr [ecx + 4]
// 0064952b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0064952f  8901                 mov dword ptr [ecx], eax
// 00649531  c20800               ret 8
// library wildmagic-2-core/Math\WmlGMatrix.cpp (function ?GetSize@?$GMatrix@M@Wml@@QBEXAAH0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Math/WmlGMatrix.cpp
