// from server: 100% by auto
// roc 2009-06 004040c0  unit: VCApp::?$CComObject  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004040c0
//
// 004040c0  56                   push esi
// 004040c1  8bf1                 mov esi, ecx
// 004040c3  8b06                 mov eax, dword ptr [esi]
// 004040c5  85c0                 test eax, eax
// 004040c7  740d                 je 0x4040d6
// 004040c9  50                   push eax
// 004040ca  ff1588e38900         call dword ptr [0x89e388]
// 004040d0  c70600000000         mov dword ptr [esi], 0
// 004040d6  5e                   pop esi
// 004040d7  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appui3.cpp (function ??1CRegKey@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui3.cpp
