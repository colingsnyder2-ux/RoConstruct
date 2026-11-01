// from server: 100% by auto
// roc 2011-06 0086a460  unit: CXTPPropertyGrid  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086a460
//
// 0086a460  83ec10               sub esp, 0x10
// 0086a463  56                   push esi
// 0086a464  8bf1                 mov esi, ecx
// 0086a466  85f6                 test esi, esi
// 0086a468  742e                 je 0x86a498
// 0086a46a  837e2000             cmp dword ptr [esi + 0x20], 0
// 0086a46e  7428                 je 0x86a498
// 0086a470  56                   push esi
// 0086a471  8d4c2408             lea ecx, [esp + 8]
// 0086a475  e81629ffff           call 0x85cd90
// 0086a47a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0086a47e  2b4c2408             sub ecx, dword ptr [esp + 8]
// 0086a482  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0086a486  2b542404             sub edx, dword ptr [esp + 4]
// 0086a48a  8b06                 mov eax, dword ptr [esi]
// 0086a48c  8b8058010000         mov eax, dword ptr [eax + 0x158]
// 0086a492  51                   push ecx
// 0086a493  52                   push edx
// 0086a494  8bce                 mov ecx, esi
// 0086a496  ffd0                 call eax
// 0086a498  5e                   pop esi
// 0086a499  83c410               add esp, 0x10
// 0086a49c  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?Reposition@CXTPPropertyGrid@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGrid.cpp
