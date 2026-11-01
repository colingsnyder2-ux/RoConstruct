// from server: 100% by auto
// roc 2011-06 0082a7b0  unit: CXTPCommandBarKeyboardTip  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0082a7b0
//
// 0082a7b0  56                   push esi
// 0082a7b1  8bf1                 mov esi, ecx
// 0082a7b3  8d4e5c               lea ecx, [esi + 0x5c]
// 0082a7b6  ff15082ea400         call dword ptr [0xa42e08]
// 0082a7bc  8d4e58               lea ecx, [esi + 0x58]
// 0082a7bf  ff15082ea400         call dword ptr [0xa42e08]
// 0082a7c5  8d4e54               lea ecx, [esi + 0x54]
// 0082a7c8  ff15082ea400         call dword ptr [0xa42e08]
// 0082a7ce  8bce                 mov ecx, esi
// 0082a7d0  e84503feff           call 0x80ab1a
// 0082a7d5  f644240801           test byte ptr [esp + 8], 1
// 0082a7da  7409                 je 0x82a7e5
// 0082a7dc  56                   push esi
// 0082a7dd  e876f8fdff           call 0x80a058
// 0082a7e2  83c404               add esp, 4
// 0082a7e5  8bc6                 mov eax, esi
// 0082a7e7  5e                   pop esi
// 0082a7e8  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPCommandBars.cpp (function ??_GCXTPCommandBarKeyboardTip@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPCommandBars.cpp
