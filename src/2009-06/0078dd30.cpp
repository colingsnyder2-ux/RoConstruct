// from server: 100% by auto
// roc 2009-06 0078dd30  unit: CXTPPropertyGridView  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078dd30
//
// 0078dd30  56                   push esi
// 0078dd31  8bf1                 mov esi, ecx
// 0078dd33  8b4620               mov eax, dword ptr [esi + 0x20]
// 0078dd36  85c0                 test eax, eax
// 0078dd38  741a                 je 0x78dd54
// 0078dd3a  6a00                 push 0
// 0078dd3c  6a00                 push 0
// 0078dd3e  6888010000           push 0x188
// 0078dd43  50                   push eax
// 0078dd44  ff1590ee8900         call dword ptr [0x89ee90]
// 0078dd4a  50                   push eax
// 0078dd4b  8bce                 mov ecx, esi
// 0078dd4d  e89efcffff           call 0x78d9f0
// 0078dd52  5e                   pop esi
// 0078dd53  c3                   ret 
// 0078dd54  33c0                 xor eax, eax
// 0078dd56  5e                   pop esi
// 0078dd57  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetSelectedItem@CXTPPropertyGridView@@AAEPAVCXTPPropertyGridItem@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
