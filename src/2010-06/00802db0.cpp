// from server: 100% by auto
// roc 2010-06 00802db0  unit: CXTPPropertyGrid  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00802db0
//
// 00802db0  83ec10               sub esp, 0x10
// 00802db3  56                   push esi
// 00802db4  8bf1                 mov esi, ecx
// 00802db6  85f6                 test esi, esi
// 00802db8  742e                 je 0x802de8
// 00802dba  837e2000             cmp dword ptr [esi + 0x20], 0
// 00802dbe  7428                 je 0x802de8
// 00802dc0  56                   push esi
// 00802dc1  8d4c2408             lea ecx, [esp + 8]
// 00802dc5  e846c5ffff           call 0x7ff310
// 00802dca  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00802dce  2b4c2408             sub ecx, dword ptr [esp + 8]
// 00802dd2  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00802dd6  2b542404             sub edx, dword ptr [esp + 4]
// 00802dda  8b06                 mov eax, dword ptr [esi]
// 00802ddc  8b8058010000         mov eax, dword ptr [eax + 0x158]
// 00802de2  51                   push ecx
// 00802de3  52                   push edx
// 00802de4  8bce                 mov ecx, esi
// 00802de6  ffd0                 call eax
// 00802de8  5e                   pop esi
// 00802de9  83c410               add esp, 0x10
// 00802dec  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?Reposition@CXTPPropertyGrid@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGrid.cpp
