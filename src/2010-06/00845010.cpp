// from server: 100% by auto
// roc 2010-06 00845010  unit: CXTPDockBar  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00845010
//
// 00845010  8b442404             mov eax, dword ptr [esp + 4]
// 00845014  8b4804               mov ecx, dword ptr [eax + 4]
// 00845017  8b542408             mov edx, dword ptr [esp + 8]
// 0084501b  33c0                 xor eax, eax
// 0084501d  3b4a04               cmp ecx, dword ptr [edx + 4]
// 00845020  0f9dc0               setge al
// 00845023  8d4400ff             lea eax, [eax + eax - 1]
// 00845027  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPDockBar.cpp (function ?CompareFunc@CDockInfoArray@CXTPDockBar@@SAHPBX0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDockBar.cpp
