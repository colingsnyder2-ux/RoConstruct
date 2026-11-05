// from server: 100% by auto
// roc 2009-06 00498ce0  unit: Ogre::RbxArchiveFactory  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00498ce0
//
// 00498ce0  51                   push ecx
// 00498ce1  8b542410             mov edx, dword ptr [esp + 0x10]
// 00498ce5  56                   push esi
// 00498ce6  8b742410             mov esi, dword ptr [esp + 0x10]
// 00498cea  57                   push edi
// 00498ceb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00498cef  c644240800           mov byte ptr [esp + 8], 0
// 00498cf4  8b442408             mov eax, dword ptr [esp + 8]
// 00498cf8  50                   push eax
// 00498cf9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00498cfd  52                   push edx
// 00498cfe  83c108               add ecx, 8
// 00498d01  51                   push ecx
// 00498d02  50                   push eax
// 00498d03  56                   push esi
// 00498d04  57                   push edi
// 00498d05  e8d6feffff           call 0x498be0
// 00498d0a  8d0476               lea eax, [esi + esi*2]
// 00498d0d  83c418               add esp, 0x18
// 00498d10  c1e005               shl eax, 5
// 00498d13  03c7                 add eax, edi
// 00498d15  5f                   pop edi
// 00498d16  5e                   pop esi
// 00498d17  59                   pop ecx
// 00498d18  c20c00               ret 0xc
// library wildmagic-2-core/Intersection\WmlIntrTet3Tet3.cpp (function ?_Ufill@?$vector@V?$Tetrahedron3@N@Wml@@V?$allocator@V?$Tetrahedron3@N@Wml@@@std@@@std@@IAEPAV?$Tetrahedron3@N@Wml@@PAV34@IABV34@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Intersection/WmlIntrTet3Tet3.cpp
