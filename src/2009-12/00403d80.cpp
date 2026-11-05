// from server: 100% by auto
// roc 2009-12 00403d80  unit: VCApp::?$CComObject  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00403d80
//
// 00403d80  56                   push esi
// 00403d81  8bf1                 mov esi, ecx
// 00403d83  8b06                 mov eax, dword ptr [esi]
// 00403d85  85c0                 test eax, eax
// 00403d87  740d                 je 0x403d96
// 00403d89  50                   push eax
// 00403d8a  ff155cb29800         call dword ptr [0x98b25c]
// 00403d90  c70600000000         mov dword ptr [esi], 0
// 00403d96  5e                   pop esi
// 00403d97  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appui3.cpp (function ??1CRegKey@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui3.cpp
