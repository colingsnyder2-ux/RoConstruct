// from server: 100% by auto
// roc 2010-06 007e7780  unit: CRobloxTreeCtrl  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e7780
//
// 007e7780  8b442408             mov eax, dword ptr [esp + 8]
// 007e7784  56                   push esi
// 007e7785  f7d8                 neg eax
// 007e7787  1bc0                 sbb eax, eax
// 007e7789  6a10                 push 0x10
// 007e778b  8bf1                 mov esi, ecx
// 007e778d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007e7791  83e010               and eax, 0x10
// 007e7794  50                   push eax
// 007e7795  51                   push ecx
// 007e7796  8bce                 mov ecx, esi
// 007e7798  e873ebffff           call 0x7e6310
// 007e779d  8b5634               mov edx, dword ptr [esi + 0x34]
// 007e77a0  8b4220               mov eax, dword ptr [edx + 0x20]
// 007e77a3  6a01                 push 1
// 007e77a5  6a00                 push 0
// 007e77a7  50                   push eax
// 007e77a8  ff1578ba9e00         call dword ptr [0x9eba78]
// 007e77ae  5e                   pop esi
// 007e77af  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?SetItemBold@CXTTreeBase@@UAEXPAU_TREEITEM@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
