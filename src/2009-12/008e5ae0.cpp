// from server: 100% by auto
// roc 2009-12 008e5ae0  unit: CXTColorSelectorCtrl  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e5ae0
//
// 008e5ae0  8b442404             mov eax, dword ptr [esp + 4]
// 008e5ae4  56                   push esi
// 008e5ae5  50                   push eax
// 008e5ae6  8bf1                 mov esi, ecx
// 008e5ae8  e8a1ebf0ff           call 0x7f468e
// 008e5aed  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008e5af0  6a00                 push 0
// 008e5af2  6a00                 push 0
// 008e5af4  51                   push ecx
// 008e5af5  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008e5afb  5e                   pop esi
// 008e5afc  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnSetFocus@CXTButton@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
