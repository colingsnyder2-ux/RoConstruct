// roc 2012-06 005b3bf0  unit: RBX::Network::ErrorCompPhysicsSender2  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005b3bf0
//
// 005b3bf0  51                   push ecx
// 005b3bf1  8b542410             mov edx, dword ptr [esp + 0x10]
// 005b3bf5  56                   push esi
// 005b3bf6  8b742410             mov esi, dword ptr [esp + 0x10]
// 005b3bfa  57                   push edi
// 005b3bfb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005b3bff  c644240800           mov byte ptr [esp + 8], 0
// 005b3c04  8b442408             mov eax, dword ptr [esp + 8]
// 005b3c08  50                   push eax
// 005b3c09  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005b3c0d  52                   push edx
// 005b3c0e  51                   push ecx
// 005b3c0f  50                   push eax
// 005b3c10  56                   push esi
// 005b3c11  57                   push edi
// 005b3c12  e869fdffff           call 0x5b3980
// 005b3c17  8d0c76               lea ecx, [esi + esi*2]
// 005b3c1a  83c418               add esp, 0x18
// 005b3c1d  8d04cf               lea eax, [edi + ecx*8]
// 005b3c20  5f                   pop edi
// 005b3c21  5e                   pop esi
// 005b3c22  59                   pop ecx
// 005b3c23  c20c00               ret 0xc
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?_Ufill@?$vector@VSortedVertex@?$ConvexHull2@N@Wml@@V?$allocator@VSortedVertex@?$ConvexHull2@N@Wml@@@std@@@std@@IAEPAVSortedVertex@?$ConvexHull2@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
