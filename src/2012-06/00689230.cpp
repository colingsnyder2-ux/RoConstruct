// roc 2012-06 00689230  unit: RBX::VCamera::?$FactoryProduct  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00689230
//
// 00689230  51                   push ecx
// 00689231  8b542410             mov edx, dword ptr [esp + 0x10]
// 00689235  56                   push esi
// 00689236  8b742410             mov esi, dword ptr [esp + 0x10]
// 0068923a  57                   push edi
// 0068923b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0068923f  c644240800           mov byte ptr [esp + 8], 0
// 00689244  8b442408             mov eax, dword ptr [esp + 8]
// 00689248  50                   push eax
// 00689249  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0068924d  52                   push edx
// 0068924e  51                   push ecx
// 0068924f  50                   push eax
// 00689250  56                   push esi
// 00689251  57                   push edi
// 00689252  e829f2ffff           call 0x688480
// 00689257  8d0476               lea eax, [esi + esi*2]
// 0068925a  83c418               add esp, 0x18
// 0068925d  c1e005               shl eax, 5
// 00689260  03c7                 add eax, edi
// 00689262  5f                   pop edi
// 00689263  5e                   pop esi
// 00689264  59                   pop ecx
// 00689265  c20c00               ret 0xc
// library wildmagic-2-core/Intersection\WmlIntrTet3Tet3.cpp (function ?_Ufill@?$vector@V?$Tetrahedron3@N@Wml@@V?$allocator@V?$Tetrahedron3@N@Wml@@@std@@@std@@IAEPAV?$Tetrahedron3@N@Wml@@PAV34@IABV34@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Intersection/WmlIntrTet3Tet3.cpp
