// from server: 100% by auto
// roc 2010-06 007f4050  unit: CXTPCustomizeSheet  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f4050
//
// 007f4050  56                   push esi
// 007f4051  6a01                 push 1
// 007f4053  8bf1                 mov esi, ecx
// 007f4055  e8ce3bfbff           call 0x7a7c28
// 007f405a  8bce                 mov ecx, esi
// 007f405c  e8cffeffff           call 0x7f3f30
// 007f4061  8b8e98000000         mov ecx, dword ptr [esi + 0x98]
// 007f4067  8b4074               mov eax, dword ptr [eax + 0x74]
// 007f406a  89482c               mov dword ptr [eax + 0x2c], ecx
// 007f406d  5e                   pop esi
// 007f406e  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeOptionsPage.cpp (function ?OnCheckShortcuts@CXTPCustomizeOptionsPage@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeOptionsPage.cpp
