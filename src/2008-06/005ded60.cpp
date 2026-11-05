// from server: 100% by auto
// roc 2008-06 005ded60  unit: RBX::Message  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005ded60
//
// 005ded60  d9442404             fld dword ptr [esp + 4]
// 005ded64  51                   push ecx
// 005ded65  d91c24               fstp dword ptr [esp]
// 005ded68  e853d1feff           call 0x5cbec0
// 005ded6d  d91c24               fstp dword ptr [esp]
// 005ded70  e86bffffff           call 0x5dece0
// 005ded75  83c404               add esp, 4
// 005ded78  c3                   ret 
// library wildmagic-2-core/Math\WmlMath.cpp (function ?Gamma@?$Math@M@Wml@@SAMM@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Math/WmlMath.cpp
