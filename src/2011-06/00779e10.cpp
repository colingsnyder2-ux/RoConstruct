// from server: 100% by auto
// roc 2011-06 00779e10  unit: seg_00770000  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00779e10
//
// 00779e10  51                   push ecx
// 00779e11  8b542410             mov edx, dword ptr [esp + 0x10]
// 00779e15  56                   push esi
// 00779e16  8b742410             mov esi, dword ptr [esp + 0x10]
// 00779e1a  57                   push edi
// 00779e1b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00779e1f  c644240800           mov byte ptr [esp + 8], 0
// 00779e24  8b442408             mov eax, dword ptr [esp + 8]
// 00779e28  50                   push eax
// 00779e29  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00779e2d  52                   push edx
// 00779e2e  51                   push ecx
// 00779e2f  50                   push eax
// 00779e30  56                   push esi
// 00779e31  57                   push edi
// 00779e32  e8c9feffff           call 0x779d00
// 00779e37  8d0c76               lea ecx, [esi + esi*2]
// 00779e3a  83c418               add esp, 0x18
// 00779e3d  8d04cf               lea eax, [edi + ecx*8]
// 00779e40  5f                   pop edi
// 00779e41  5e                   pop esi
// 00779e42  59                   pop ecx
// 00779e43  c20c00               ret 0xc
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?_Ufill@?$vector@VSortedVertex@?$ConvexHull2@N@Wml@@V?$allocator@VSortedVertex@?$ConvexHull2@N@Wml@@@std@@@std@@IAEPAVSortedVertex@?$ConvexHull2@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
