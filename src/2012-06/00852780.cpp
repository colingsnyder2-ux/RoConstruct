// roc 2012-06 00852780  unit: RBX::CoreScript  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00852780
//
// 00852780  51                   push ecx
// 00852781  8b542410             mov edx, dword ptr [esp + 0x10]
// 00852785  56                   push esi
// 00852786  8b742410             mov esi, dword ptr [esp + 0x10]
// 0085278a  57                   push edi
// 0085278b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0085278f  c644240800           mov byte ptr [esp + 8], 0
// 00852794  8b442408             mov eax, dword ptr [esp + 8]
// 00852798  50                   push eax
// 00852799  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0085279d  52                   push edx
// 0085279e  51                   push ecx
// 0085279f  50                   push eax
// 008527a0  56                   push esi
// 008527a1  57                   push edi
// 008527a2  e859ffffff           call 0x852700
// 008527a7  8d0c76               lea ecx, [esi + esi*2]
// 008527aa  83c418               add esp, 0x18
// 008527ad  8d04cf               lea eax, [edi + ecx*8]
// 008527b0  5f                   pop edi
// 008527b1  5e                   pop esi
// 008527b2  59                   pop ecx
// 008527b3  c20c00               ret 0xc
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?_Ufill@?$vector@VSortedVertex@?$ConvexHull2@N@Wml@@V?$allocator@VSortedVertex@?$ConvexHull2@N@Wml@@@std@@@std@@IAEPAVSortedVertex@?$ConvexHull2@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
