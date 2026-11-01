// from server: 100% by auto
// roc 2011-06 009295b0  unit: Ogre::RBXSSAO::MRTListener  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009295b0
//
// 009295b0  8b01                 mov eax, dword ptr [ecx]
// 009295b2  85c0                 test eax, eax
// 009295b4  7406                 je 0x9295bc
// 009295b6  50                   push eax
// 009295b7  e804f8ffff           call 0x928dc0
// 009295bc  c3                   ret 
// library atl-8.0/atl.cpp (function ??1CDynamicStdCallThunk@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
