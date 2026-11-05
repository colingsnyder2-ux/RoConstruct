// from server: 100% by auto
// roc 2010-06 00403de0  unit: VCApp::?$CComObject  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00403de0
//
// 00403de0  56                   push esi
// 00403de1  8bf1                 mov esi, ecx
// 00403de3  8b06                 mov eax, dword ptr [esi]
// 00403de5  85c0                 test eax, eax
// 00403de7  740d                 je 0x403df6
// 00403de9  50                   push eax
// 00403dea  ff15cca39e00         call dword ptr [0x9ea3cc]
// 00403df0  c70600000000         mov dword ptr [esi], 0
// 00403df6  5e                   pop esi
// 00403df7  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appui3.cpp (function ??1CRegKey@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui3.cpp
