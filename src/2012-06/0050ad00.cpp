// roc 2012-06 0050ad00  unit: Ogre::RbxArchiveFactory  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0050ad00
//
// 0050ad00  51                   push ecx
// 0050ad01  8b542410             mov edx, dword ptr [esp + 0x10]
// 0050ad05  56                   push esi
// 0050ad06  8b742410             mov esi, dword ptr [esp + 0x10]
// 0050ad0a  57                   push edi
// 0050ad0b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0050ad0f  c644240800           mov byte ptr [esp + 8], 0
// 0050ad14  8b442408             mov eax, dword ptr [esp + 8]
// 0050ad18  50                   push eax
// 0050ad19  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0050ad1d  52                   push edx
// 0050ad1e  51                   push ecx
// 0050ad1f  50                   push eax
// 0050ad20  56                   push esi
// 0050ad21  57                   push edi
// 0050ad22  e899fcffff           call 0x50a9c0
// 0050ad27  8d0476               lea eax, [esi + esi*2]
// 0050ad2a  83c418               add esp, 0x18
// 0050ad2d  c1e005               shl eax, 5
// 0050ad30  03c7                 add eax, edi
// 0050ad32  5f                   pop edi
// 0050ad33  5e                   pop esi
// 0050ad34  59                   pop ecx
// 0050ad35  c20c00               ret 0xc
// library wildmagic-2-core/Intersection\WmlIntrTet3Tet3.cpp (function ?_Ufill@?$vector@V?$Tetrahedron3@N@Wml@@V?$allocator@V?$Tetrahedron3@N@Wml@@@std@@@std@@IAEPAV?$Tetrahedron3@N@Wml@@PAV34@IABV34@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Intersection/WmlIntrTet3Tet3.cpp
