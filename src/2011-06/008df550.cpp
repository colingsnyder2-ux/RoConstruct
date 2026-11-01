// from server: 100% by auto
// roc 2011-06 008df550  unit: VCEdit::?$CXTMaskEditT  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008df550
//
// 008df550  56                   push esi
// 008df551  8bf1                 mov esi, ecx
// 008df553  8d8e84000000         lea ecx, [esi + 0x84]
// 008df559  ff15082ea400         call dword ptr [0xa42e08]
// 008df55f  8d8e80000000         lea ecx, [esi + 0x80]
// 008df565  ff15082ea400         call dword ptr [0xa42e08]
// 008df56b  8d4e7c               lea ecx, [esi + 0x7c]
// 008df56e  ff15082ea400         call dword ptr [0xa42e08]
// 008df574  8d4e78               lea ecx, [esi + 0x78]
// 008df577  ff15082ea400         call dword ptr [0xa42e08]
// 008df57d  8d4e74               lea ecx, [esi + 0x74]
// 008df580  ff15082ea400         call dword ptr [0xa42e08]
// 008df586  8d4e70               lea ecx, [esi + 0x70]
// 008df589  ff15082ea400         call dword ptr [0xa42e08]
// 008df58f  8bce                 mov ecx, esi
// 008df591  e864d00e00           call 0x9cc5fa
// 008df596  f644240801           test byte ptr [esp + 8], 1
// 008df59b  7409                 je 0x8df5a6
// 008df59d  56                   push esi
// 008df59e  e8b5aaf2ff           call 0x80a058
// 008df5a3  83c404               add esp, 4
// 008df5a6  8bc6                 mov eax, esi
// 008df5a8  5e                   pop esi
// 008df5a9  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Controls\Edit\XTPEdit.cpp (function ??_G?$CXTPMaskEditT@VCEdit@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Edit/XTPEdit.cpp
