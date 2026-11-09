// roc 2012-06 004ca360  unit: Ogre::RBXSSAO::MRTListener  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ca360
//
// 004ca360  8b01                 mov eax, dword ptr [ecx]
// 004ca362  85c0                 test eax, eax
// 004ca364  7406                 je 0x4ca36c
// 004ca366  50                   push eax
// 004ca367  e8e4f7ffff           call 0x4c9b50
// 004ca36c  c3                   ret 
// library atl-8.0/atl.cpp (function ??1CDynamicStdCallThunk@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
