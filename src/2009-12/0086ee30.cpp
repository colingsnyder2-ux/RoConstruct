// from server: 100% by auto
// roc 2009-12 0086ee30  unit: CXTPResourceManager  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086ee30
//
// 0086ee30  83c8ff               or eax, 0xffffffff
// 0086ee33  0bc8                 or ecx, eax
// 0086ee35  a3d4bab900           mov dword ptr [0xb9bad4], eax
// 0086ee3a  83ec08               sub esp, 8
// 0086ee3d  8d0424               lea eax, [esp]
// 0086ee40  50                   push eax
// 0086ee41  890dd8bab900         mov dword ptr [0xb9bad8], ecx
// 0086ee47  ff1538cc9800         call dword ptr [0x98cc38]
// 0086ee4d  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0086ee51  8b1424               mov edx, dword ptr [esp]
// 0086ee54  51                   push ecx
// 0086ee55  52                   push edx
// 0086ee56  ff1524ca9800         call dword ptr [0x98ca24]
// 0086ee5c  83c408               add esp, 8
// 0086ee5f  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMouseManager.cpp (function ?RefreshCursor@CXTPMouseManager@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMouseManager.cpp
