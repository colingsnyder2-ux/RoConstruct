// roc 2012-06 0081a030  unit: RBX::VTouchTransmitter::?$FactoryProduct  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0081a030
//
// 0081a030  51                   push ecx
// 0081a031  8b542410             mov edx, dword ptr [esp + 0x10]
// 0081a035  56                   push esi
// 0081a036  8b742410             mov esi, dword ptr [esp + 0x10]
// 0081a03a  57                   push edi
// 0081a03b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0081a03f  c644240800           mov byte ptr [esp + 8], 0
// 0081a044  8b442408             mov eax, dword ptr [esp + 8]
// 0081a048  50                   push eax
// 0081a049  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0081a04d  52                   push edx
// 0081a04e  51                   push ecx
// 0081a04f  50                   push eax
// 0081a050  56                   push esi
// 0081a051  57                   push edi
// 0081a052  e839ffffff           call 0x819f90
// 0081a057  8d0c76               lea ecx, [esi + esi*2]
// 0081a05a  83c418               add esp, 0x18
// 0081a05d  8d04cf               lea eax, [edi + ecx*8]
// 0081a060  5f                   pop edi
// 0081a061  5e                   pop esi
// 0081a062  59                   pop ecx
// 0081a063  c20c00               ret 0xc
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?_Ufill@?$vector@VSortedVertex@?$ConvexHull2@N@Wml@@V?$allocator@VSortedVertex@?$ConvexHull2@N@Wml@@@std@@@std@@IAEPAVSortedVertex@?$ConvexHull2@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
