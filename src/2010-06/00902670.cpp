// from server: 100% by auto
// roc 2010-06 00902670  unit: Ogre::RbxArchiveFactory  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00902670
//
// 00902670  51                   push ecx
// 00902671  8b542410             mov edx, dword ptr [esp + 0x10]
// 00902675  56                   push esi
// 00902676  8b742410             mov esi, dword ptr [esp + 0x10]
// 0090267a  57                   push edi
// 0090267b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0090267f  c644240800           mov byte ptr [esp + 8], 0
// 00902684  8b442408             mov eax, dword ptr [esp + 8]
// 00902688  50                   push eax
// 00902689  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0090268d  52                   push edx
// 0090268e  83c108               add ecx, 8
// 00902691  51                   push ecx
// 00902692  50                   push eax
// 00902693  56                   push esi
// 00902694  57                   push edi
// 00902695  e8d6feffff           call 0x902570
// 0090269a  8d0476               lea eax, [esi + esi*2]
// 0090269d  83c418               add esp, 0x18
// 009026a0  c1e005               shl eax, 5
// 009026a3  03c7                 add eax, edi
// 009026a5  5f                   pop edi
// 009026a6  5e                   pop esi
// 009026a7  59                   pop ecx
// 009026a8  c20c00               ret 0xc
// library wildmagic-2-core/Intersection\WmlIntrTet3Tet3.cpp (function ?_Ufill@?$vector@V?$Tetrahedron3@N@Wml@@V?$allocator@V?$Tetrahedron3@N@Wml@@@std@@@std@@IAEPAV?$Tetrahedron3@N@Wml@@PAV34@IABV34@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Intersection/WmlIntrTet3Tet3.cpp
