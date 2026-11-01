// from server: 100% by auto
// roc 2007-03 0057fdb0  unit: seg_00570000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0057fdb0
//
// 0057fdb0  8b01                 mov eax, dword ptr [ecx]
// 0057fdb2  8b542404             mov edx, dword ptr [esp + 4]
// 0057fdb6  8902                 mov dword ptr [edx], eax
// 0057fdb8  8b4104               mov eax, dword ptr [ecx + 4]
// 0057fdbb  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0057fdbf  8901                 mov dword ptr [ecx], eax
// 0057fdc1  c20800               ret 8
// library wildmagic-2-core/Math\WmlGMatrix.cpp (function ?GetSize@?$GMatrix@M@Wml@@QBEXAAH0@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Math/WmlGMatrix.cpp
