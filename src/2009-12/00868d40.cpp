// from server: 100% by auto
// roc 2009-12 00868d40  unit: CXTPPropertyGridView  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00868d40
//
// 00868d40  56                   push esi
// 00868d41  8bf1                 mov esi, ecx
// 00868d43  8b4620               mov eax, dword ptr [esi + 0x20]
// 00868d46  85c0                 test eax, eax
// 00868d48  741a                 je 0x868d64
// 00868d4a  6a00                 push 0
// 00868d4c  6a00                 push 0
// 00868d4e  6888010000           push 0x188
// 00868d53  50                   push eax
// 00868d54  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00868d5a  50                   push eax
// 00868d5b  8bce                 mov ecx, esi
// 00868d5d  e89efcffff           call 0x868a00
// 00868d62  5e                   pop esi
// 00868d63  c3                   ret 
// 00868d64  33c0                 xor eax, eax
// 00868d66  5e                   pop esi
// 00868d67  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetSelectedItem@CXTPPropertyGridView@@AAEPAVCXTPPropertyGridItem@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
