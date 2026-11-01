// from server: 100% by auto
// roc 2009-06 007b2450  unit: CXTPDockBar  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b2450
//
// 007b2450  8b442404             mov eax, dword ptr [esp + 4]
// 007b2454  8b4804               mov ecx, dword ptr [eax + 4]
// 007b2457  8b542408             mov edx, dword ptr [esp + 8]
// 007b245b  33c0                 xor eax, eax
// 007b245d  3b4a04               cmp ecx, dword ptr [edx + 4]
// 007b2460  0f9dc0               setge al
// 007b2463  8d4400ff             lea eax, [eax + eax - 1]
// 007b2467  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ?CompareFunc@CDockInfoArray@CXTPDockBar@@SAHPBX0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp
