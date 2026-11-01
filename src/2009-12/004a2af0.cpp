// from server: 100% by auto
// roc 2009-12 004a2af0  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a2af0
//
// 004a2af0  51                   push ecx
// 004a2af1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004a2af5  56                   push esi
// 004a2af6  8b742410             mov esi, dword ptr [esp + 0x10]
// 004a2afa  57                   push edi
// 004a2afb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004a2aff  c644240800           mov byte ptr [esp + 8], 0
// 004a2b04  8b442408             mov eax, dword ptr [esp + 8]
// 004a2b08  50                   push eax
// 004a2b09  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a2b0d  52                   push edx
// 004a2b0e  83c108               add ecx, 8
// 004a2b11  51                   push ecx
// 004a2b12  50                   push eax
// 004a2b13  56                   push esi
// 004a2b14  57                   push edi
// 004a2b15  e896ceffff           call 0x49f9b0
// 004a2b1a  83c418               add esp, 0x18
// 004a2b1d  8d0cf500000000       lea ecx, [esi*8]
// 004a2b24  2bce                 sub ecx, esi
// 004a2b26  8d04cf               lea eax, [edi + ecx*8]
// 004a2b29  5f                   pop edi
// 004a2b2a  5e                   pop esi
// 004a2b2b  59                   pop ecx
// 004a2b2c  c20c00               ret 0xc
// library wildmagic-2-core/Geometry\WmlConvexPolygon2.cpp (function ?_Ufill@?$vector@V?$Line2@N@Wml@@V?$allocator@V?$Line2@N@Wml@@@std@@@std@@IAEPAV?$Line2@N@Wml@@PAV34@IABV34@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolygon2.cpp
