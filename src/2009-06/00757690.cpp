// from server: 100% by auto
// roc 2009-06 00757690  unit: CRobloxTreeCtrl  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00757690
//
// 00757690  8b442404             mov eax, dword ptr [esp + 4]
// 00757694  56                   push esi
// 00757695  57                   push edi
// 00757696  33ff                 xor edi, edi
// 00757698  8bf1                 mov esi, ecx
// 0075769a  85c0                 test eax, eax
// 0075769c  740f                 je 0x7576ad
// 0075769e  6a01                 push 1
// 007576a0  6a01                 push 1
// 007576a2  50                   push eax
// 007576a3  e828fcffff           call 0x7572d0
// 007576a8  5f                   pop edi
// 007576a9  5e                   pop esi
// 007576aa  c20400               ret 4
// 007576ad  8b4634               mov eax, dword ptr [esi + 0x34]
// 007576b0  8b4020               mov eax, dword ptr [eax + 0x20]
// 007576b3  6a00                 push 0
// 007576b5  6a09                 push 9
// 007576b7  680a110000           push 0x110a
// 007576bc  50                   push eax
// 007576bd  ff1590ee8900         call dword ptr [0x89ee90]
// 007576c3  85c0                 test eax, eax
// 007576c5  7411                 je 0x7576d8
// 007576c7  6a01                 push 1
// 007576c9  6a00                 push 0
// 007576cb  50                   push eax
// 007576cc  8bce                 mov ecx, esi
// 007576ce  e8fdfbffff           call 0x7572d0
// 007576d3  5f                   pop edi
// 007576d4  5e                   pop esi
// 007576d5  c20400               ret 4
// 007576d8  8bc7                 mov eax, edi
// 007576da  5f                   pop edi
// 007576db  5e                   pop esi
// 007576dc  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?FocusItem@CXTPTreeBase@@QAEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
