// from server: 100% by auto
// roc 2010-06 007e66d0  unit: CRobloxTreeCtrl  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e66d0
//
// 007e66d0  8b442404             mov eax, dword ptr [esp + 4]
// 007e66d4  56                   push esi
// 007e66d5  57                   push edi
// 007e66d6  33ff                 xor edi, edi
// 007e66d8  8bf1                 mov esi, ecx
// 007e66da  85c0                 test eax, eax
// 007e66dc  740f                 je 0x7e66ed
// 007e66de  6a01                 push 1
// 007e66e0  6a01                 push 1
// 007e66e2  50                   push eax
// 007e66e3  e828fcffff           call 0x7e6310
// 007e66e8  5f                   pop edi
// 007e66e9  5e                   pop esi
// 007e66ea  c20400               ret 4
// 007e66ed  8b4634               mov eax, dword ptr [esi + 0x34]
// 007e66f0  8b4020               mov eax, dword ptr [eax + 0x20]
// 007e66f3  6a00                 push 0
// 007e66f5  6a09                 push 9
// 007e66f7  680a110000           push 0x110a
// 007e66fc  50                   push eax
// 007e66fd  ff1554ba9e00         call dword ptr [0x9eba54]
// 007e6703  85c0                 test eax, eax
// 007e6705  7411                 je 0x7e6718
// 007e6707  6a01                 push 1
// 007e6709  6a00                 push 0
// 007e670b  50                   push eax
// 007e670c  8bce                 mov ecx, esi
// 007e670e  e8fdfbffff           call 0x7e6310
// 007e6713  5f                   pop edi
// 007e6714  5e                   pop esi
// 007e6715  c20400               ret 4
// 007e6718  8bc7                 mov eax, edi
// 007e671a  5f                   pop edi
// 007e671b  5e                   pop esi
// 007e671c  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?FocusItem@CXTTreeBase@@QAEHPAU_TREEITEM@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
