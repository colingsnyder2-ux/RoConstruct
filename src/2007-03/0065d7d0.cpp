// from server: 100% by auto
// roc 2007-03 0065d7d0  unit: seg_00650000  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065d7d0
//
// 0065d7d0  83ec10               sub esp, 0x10
// 0065d7d3  56                   push esi
// 0065d7d4  8bf1                 mov esi, ecx
// 0065d7d6  85f6                 test esi, esi
// 0065d7d8  742e                 je 0x65d808
// 0065d7da  837e2000             cmp dword ptr [esi + 0x20], 0
// 0065d7de  7428                 je 0x65d808
// 0065d7e0  56                   push esi
// 0065d7e1  8d4c2408             lea ecx, [esp + 8]
// 0065d7e5  e876e00000           call 0x66b860
// 0065d7ea  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0065d7ee  2b4c2408             sub ecx, dword ptr [esp + 8]
// 0065d7f2  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0065d7f6  2b542404             sub edx, dword ptr [esp + 4]
// 0065d7fa  8b06                 mov eax, dword ptr [esi]
// 0065d7fc  8b8050010000         mov eax, dword ptr [eax + 0x150]
// 0065d802  51                   push ecx
// 0065d803  52                   push edx
// 0065d804  8bce                 mov ecx, esi
// 0065d806  ffd0                 call eax
// 0065d808  5e                   pop esi
// 0065d809  83c410               add esp, 0x10
// 0065d80c  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?Reposition@CXTPPropertyGrid@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
