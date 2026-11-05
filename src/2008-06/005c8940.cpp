// from server: 100% by auto
// roc 2008-06 005c8940  unit: RBX::LaserTool  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c8940
//
// 005c8940  8b01                 mov eax, dword ptr [ecx]
// 005c8942  8b542404             mov edx, dword ptr [esp + 4]
// 005c8946  8902                 mov dword ptr [edx], eax
// 005c8948  8b4104               mov eax, dword ptr [ecx + 4]
// 005c894b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005c894f  8901                 mov dword ptr [ecx], eax
// 005c8951  c20800               ret 8
// library wildmagic-2-core/Math\WmlGMatrix.cpp (function ?GetSize@?$GMatrix@M@Wml@@QBEXAAH0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Math/WmlGMatrix.cpp
