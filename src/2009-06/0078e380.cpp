// from server: 100% by auto
// roc 2009-06 0078e380  unit: CXTPPropertyGridView  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078e380
//
// 0078e380  56                   push esi
// 0078e381  8bf1                 mov esi, ecx
// 0078e383  e880acf8ff           call 0x719008
// 0078e388  8bce                 mov ecx, esi
// 0078e38a  e8e1feffff           call 0x78e270
// 0078e38f  8b4620               mov eax, dword ptr [esi + 0x20]
// 0078e392  6a00                 push 0
// 0078e394  6a00                 push 0
// 0078e396  50                   push eax
// 0078e397  ff157cee8900         call dword ptr [0x89ee7c]
// 0078e39d  5e                   pop esi
// 0078e39e  c20c00               ret 0xc
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?OnSize@CXTPPropertyGridView@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
