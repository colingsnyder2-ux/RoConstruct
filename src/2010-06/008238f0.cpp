// from server: 100% by auto
// roc 2010-06 008238f0  unit: CXTPNewToolbarDlg  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008238f0
//
// 008238f0  56                   push esi
// 008238f1  8bf1                 mov esi, ecx
// 008238f3  8d4e78               lea ecx, [esi + 0x78]
// 008238f6  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 008238fc  8bce                 mov ecx, esi
// 008238fe  e8cd49f8ff           call 0x7a82d0
// 00823903  f644240801           test byte ptr [esp + 8], 1
// 00823908  7409                 je 0x823913
// 0082390a  56                   push esi
// 0082390b  e88a40f8ff           call 0x7a799a
// 00823910  83c404               add esp, 4
// 00823913  8bc6                 mov eax, esi
// 00823915  5e                   pop esi
// 00823916  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPCustomizeTools.cpp (function ??_GCXTPNewToolbarDlg@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPCustomizeTools.cpp
