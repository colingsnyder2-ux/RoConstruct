// from server: 100% by auto
// roc 2009-12 008693a0  unit: CXTPPropertyGridView  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008693a0
//
// 008693a0  56                   push esi
// 008693a1  8bf1                 mov esi, ecx
// 008693a3  e888aaf8ff           call 0x7f3e30
// 008693a8  8bce                 mov ecx, esi
// 008693aa  e8e1feffff           call 0x869290
// 008693af  8b4620               mov eax, dword ptr [esi + 0x20]
// 008693b2  6a00                 push 0
// 008693b4  6a00                 push 0
// 008693b6  50                   push eax
// 008693b7  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008693bd  5e                   pop esi
// 008693be  c20c00               ret 0xc
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?OnSize@CXTPPropertyGridView@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
