// from server: 100% by auto
// roc 2010-06 007f3fc0  unit: CXTPCustomizeSheet  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f3fc0
//
// 007f3fc0  56                   push esi
// 007f3fc1  6a01                 push 1
// 007f3fc3  8bf1                 mov esi, ecx
// 007f3fc5  e85e3cfbff           call 0x7a7c28
// 007f3fca  8bce                 mov ecx, esi
// 007f3fcc  e85fffffff           call 0x7f3f30
// 007f3fd1  8b8e8c000000         mov ecx, dword ptr [esi + 0x8c]
// 007f3fd7  8b4074               mov eax, dword ptr [eax + 0x74]
// 007f3fda  894824               mov dword ptr [eax + 0x24], ecx
// 007f3fdd  5e                   pop esi
// 007f3fde  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeOptionsPage.cpp (function ?OnCheckAfterdelay@CXTPCustomizeOptionsPage@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeOptionsPage.cpp
