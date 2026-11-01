// from server: 100% by auto
// roc 2009-12 004b8480  unit: Ogre::RbxArchiveFactory  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b8480
//
// 004b8480  51                   push ecx
// 004b8481  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b8485  56                   push esi
// 004b8486  8b742410             mov esi, dword ptr [esp + 0x10]
// 004b848a  57                   push edi
// 004b848b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004b848f  c644240800           mov byte ptr [esp + 8], 0
// 004b8494  8b442408             mov eax, dword ptr [esp + 8]
// 004b8498  50                   push eax
// 004b8499  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004b849d  52                   push edx
// 004b849e  83c108               add ecx, 8
// 004b84a1  51                   push ecx
// 004b84a2  50                   push eax
// 004b84a3  56                   push esi
// 004b84a4  57                   push edi
// 004b84a5  e876feffff           call 0x4b8320
// 004b84aa  8d0476               lea eax, [esi + esi*2]
// 004b84ad  83c418               add esp, 0x18
// 004b84b0  c1e005               shl eax, 5
// 004b84b3  03c7                 add eax, edi
// 004b84b5  5f                   pop edi
// 004b84b6  5e                   pop esi
// 004b84b7  59                   pop ecx
// 004b84b8  c20c00               ret 0xc
// library wildmagic-2-core/Intersection\WmlIntrTet3Tet3.cpp (function ?_Ufill@?$vector@V?$Tetrahedron3@N@Wml@@V?$allocator@V?$Tetrahedron3@N@Wml@@@std@@@std@@IAEPAV?$Tetrahedron3@N@Wml@@PAV34@IABV34@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Intersection/WmlIntrTet3Tet3.cpp
