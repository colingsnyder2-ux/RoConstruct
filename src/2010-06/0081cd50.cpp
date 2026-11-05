// from server: 100% by auto
// roc 2010-06 0081cd50  unit: CXTPPropertyGridView  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081cd50
//
// 0081cd50  56                   push esi
// 0081cd51  8bf1                 mov esi, ecx
// 0081cd53  8b4620               mov eax, dword ptr [esi + 0x20]
// 0081cd56  85c0                 test eax, eax
// 0081cd58  741a                 je 0x81cd74
// 0081cd5a  6a00                 push 0
// 0081cd5c  6a00                 push 0
// 0081cd5e  6888010000           push 0x188
// 0081cd63  50                   push eax
// 0081cd64  ff1554ba9e00         call dword ptr [0x9eba54]
// 0081cd6a  50                   push eax
// 0081cd6b  8bce                 mov ecx, esi
// 0081cd6d  e89efcffff           call 0x81ca10
// 0081cd72  5e                   pop esi
// 0081cd73  c3                   ret 
// 0081cd74  33c0                 xor eax, eax
// 0081cd76  5e                   pop esi
// 0081cd77  c3                   ret 
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?GetSelectedItem@CXTPPropertyGridView@@AAEPAVCXTPPropertyGridItem@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
