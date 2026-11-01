// from server: 100% by auto
// roc 2007-03 00715f10  unit: seg_00710000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00715f10
//
// 00715f10  56                   push esi
// 00715f11  8bf1                 mov esi, ecx
// 00715f13  e8ba87f0ff           call 0x61e6d2
// 00715f18  8b4620               mov eax, dword ptr [esi + 0x20]
// 00715f1b  6a00                 push 0
// 00715f1d  6a00                 push 0
// 00715f1f  50                   push eax
// 00715f20  ff1554ee7700         call dword ptr [0x77ee54]
// 00715f26  5e                   pop esi
// 00715f27  c3                   ret 
// library xtp-15.2.1/Source\Controls\Spin\XTPSpinButtonCtrl.cpp (function ?Init@CXTPSpinButtonCtrl@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Spin/XTPSpinButtonCtrl.cpp
