// from server: 100% by auto
// roc 2009-12 00854890  unit: CXTPTabManagerAtom  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00854890
//
// 00854890  8b01                 mov eax, dword ptr [ecx]
// 00854892  8b5004               mov edx, dword ptr [eax + 4]
// 00854895  ffe2                 jmp edx
// library mfc-8.0/atlmfc\src\mfc\isapi.cpp (function ?Abort@CHtmlStream@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/isapi.cpp
