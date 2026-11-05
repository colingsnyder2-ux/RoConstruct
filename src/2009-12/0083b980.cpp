// from server: 100% by auto
// roc 2009-12 0083b980  unit: CXTPToolBar::CControlButtonExpand  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083b980
//
// 0083b980  8b01                 mov eax, dword ptr [ecx]
// 0083b982  50                   push eax
// 0083b983  ff1504b29800         call dword ptr [0x98b204]
// 0083b989  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxabort.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxabort.cpp
