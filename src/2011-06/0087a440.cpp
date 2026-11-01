// from server: 100% by auto
// roc 2011-06 0087a440  unit: CXTPPropertyGridItemConstraint  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0087a440
//
// 0087a440  56                   push esi
// 0087a441  8bf1                 mov esi, ecx
// 0087a443  8d4e20               lea ecx, [esi + 0x20]
// 0087a446  ff15082ea400         call dword ptr [0xa42e08]
// 0087a44c  8bce                 mov ecx, esi
// 0087a44e  e89307f9ff           call 0x80abe6
// 0087a453  f644240801           test byte ptr [esp + 8], 1
// 0087a458  7409                 je 0x87a463
// 0087a45a  56                   push esi
// 0087a45b  e8f8fbf8ff           call 0x80a058
// 0087a460  83c404               add esp, 4
// 0087a463  8bc6                 mov eax, esi
// 0087a465  5e                   pop esi
// 0087a466  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGrid.cpp (function ??_GCXTPPropertyGridVerb@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGrid.cpp
