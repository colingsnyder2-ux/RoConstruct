// from server: 100% by auto
// roc 2011-06 004048b0  unit: VCApp::?$CComObject  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004048b0
//
// 004048b0  56                   push esi
// 004048b1  8bf1                 mov esi, ecx
// 004048b3  8b06                 mov eax, dword ptr [esi]
// 004048b5  85c0                 test eax, eax
// 004048b7  740d                 je 0x4048c6
// 004048b9  50                   push eax
// 004048ba  ff157c03a400         call dword ptr [0xa4037c]
// 004048c0  c70600000000         mov dword ptr [esi], 0
// 004048c6  5e                   pop esi
// 004048c7  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appui3.cpp (function ??1CRegKey@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui3.cpp
