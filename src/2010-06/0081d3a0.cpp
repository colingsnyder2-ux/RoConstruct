// from server: 100% by auto
// roc 2010-06 0081d3a0  unit: CXTPPropertyGridView  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081d3a0
//
// 0081d3a0  56                   push esi
// 0081d3a1  8bf1                 mov esi, ecx
// 0081d3a3  e8c8abf8ff           call 0x7a7f70
// 0081d3a8  8bce                 mov ecx, esi
// 0081d3aa  e8e1feffff           call 0x81d290
// 0081d3af  8b4620               mov eax, dword ptr [esi + 0x20]
// 0081d3b2  6a00                 push 0
// 0081d3b4  6a00                 push 0
// 0081d3b6  50                   push eax
// 0081d3b7  ff1578ba9e00         call dword ptr [0x9eba78]
// 0081d3bd  5e                   pop esi
// 0081d3be  c20c00               ret 0xc
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?OnSize@CXTPPropertyGridView@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
