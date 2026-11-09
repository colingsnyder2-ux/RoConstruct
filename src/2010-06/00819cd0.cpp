// from server: 100% by auto
// roc 2010-06 00819cd0  unit: CXTPPropertyGridItemConstraint  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00819cd0
//
// 00819cd0  56                   push esi
// 00819cd1  8bf1                 mov esi, ecx
// 00819cd3  8d4e20               lea ecx, [esi + 0x20]
// 00819cd6  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00819cdc  8bce                 mov ecx, esi
// 00819cde  e83fe8f8ff           call 0x7a8522
// 00819ce3  f644240801           test byte ptr [esp + 8], 1
// 00819ce8  7409                 je 0x819cf3
// 00819cea  56                   push esi
// 00819ceb  e8aadcf8ff           call 0x7a799a
// 00819cf0  83c404               add esp, 4
// 00819cf3  8bc6                 mov eax, esi
// 00819cf5  5e                   pop esi
// 00819cf6  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGrid.cpp (function ??_GCXTPPropertyGridVerb@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGrid.cpp
