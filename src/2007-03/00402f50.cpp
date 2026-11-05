// from server: 100% by auto
// roc 2007-03 00402f50  unit: seg_00400000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00402f50
//
// 00402f50  56                   push esi
// 00402f51  8bf1                 mov esi, ecx
// 00402f53  8b06                 mov eax, dword ptr [esi]
// 00402f55  85c0                 test eax, eax
// 00402f57  740d                 je 0x402f66
// 00402f59  50                   push eax
// 00402f5a  ff152cd07700         call dword ptr [0x77d02c]
// 00402f60  c70600000000         mov dword ptr [esi], 0
// 00402f66  5e                   pop esi
// 00402f67  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appui3.cpp (function ??1CRegKey@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui3.cpp
