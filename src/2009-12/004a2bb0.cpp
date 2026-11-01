// from server: 100% by auto
// roc 2009-12 004a2bb0  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a2bb0
//
// 004a2bb0  51                   push ecx
// 004a2bb1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2bb5  56                   push esi
// 004a2bb6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004a2bba  57                   push edi
// 004a2bbb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004a2bbf  c644240800           mov byte ptr [esp + 8], 0
// 004a2bc4  8b442408             mov eax, dword ptr [esp + 8]
// 004a2bc8  50                   push eax
// 004a2bc9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a2bcd  52                   push edx
// 004a2bce  83c108               add ecx, 8
// 004a2bd1  51                   push ecx
// 004a2bd2  50                   push eax
// 004a2bd3  56                   push esi
// 004a2bd4  57                   push edi
// 004a2bd5  e806e4ffff           call 0x4a0fe0
// 004a2bda  8d0cf6               lea ecx, [esi + esi*8]
// 004a2bdd  83c418               add esp, 0x18
// 004a2be0  8d04cf               lea eax, [edi + ecx*8]
// 004a2be3  5f                   pop edi
// 004a2be4  5e                   pop esi
// 004a2be5  59                   pop ecx
// 004a2be6  c20c00               ret 0xc
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?_Ufill@?$vector@VFace@?$ConvexClipper@N@Wml@@V?$allocator@VFace@?$ConvexClipper@N@Wml@@@std@@@std@@IAEPAVFace@?$ConvexClipper@N@Wml@@PAV345@IABV345@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
