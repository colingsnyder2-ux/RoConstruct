// from server: 100% by auto
// roc 2009-06 006563e0  unit: RBX::LaserTool  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006563e0
//
// 006563e0  8b01                 mov eax, dword ptr [ecx]
// 006563e2  8b542404             mov edx, dword ptr [esp + 4]
// 006563e6  8902                 mov dword ptr [edx], eax
// 006563e8  8b4104               mov eax, dword ptr [ecx + 4]
// 006563eb  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006563ef  8901                 mov dword ptr [ecx], eax
// 006563f1  c20800               ret 8
// library wildmagic-2-core/Math\WmlGMatrix.cpp (function ?GetSize@?$GMatrix@M@Wml@@QBEXAAH0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Math/WmlGMatrix.cpp
