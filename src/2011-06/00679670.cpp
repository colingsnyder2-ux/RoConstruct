// from server: 100% by auto
// roc 2011-06 00679670  unit: RBX::SpecialShape  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00679670
//
// 00679670  8b01                 mov eax, dword ptr [ecx]
// 00679672  8b542404             mov edx, dword ptr [esp + 4]
// 00679676  8902                 mov dword ptr [edx], eax
// 00679678  8b4104               mov eax, dword ptr [ecx + 4]
// 0067967b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0067967f  8901                 mov dword ptr [ecx], eax
// 00679681  c20800               ret 8
// library wildmagic-2-core/Math\WmlGMatrix.cpp (function ?GetSize@?$GMatrix@M@Wml@@QBEXAAH0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Math/WmlGMatrix.cpp
