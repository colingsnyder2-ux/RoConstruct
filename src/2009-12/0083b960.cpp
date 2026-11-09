// from server: 100% by auto
// roc 2009-12 0083b960  unit: CXTPToolBar::CControlButtonExpand  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083b960
//
// 0083b960  56                   push esi
// 0083b961  8bf1                 mov esi, ecx
// 0083b963  56                   push esi
// 0083b964  ff1550b29800         call dword ptr [0x98b250]
// 0083b96a  8bc6                 mov eax, esi
// 0083b96c  5e                   pop esi
// 0083b96d  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ??0CComVariant@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
