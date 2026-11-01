// from server: 100% by auto
// roc 2011-06 00963080  unit: Ogre::RbxArchiveFactory  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00963080
//
// 00963080  51                   push ecx
// 00963081  8b542410             mov edx, dword ptr [esp + 0x10]
// 00963085  56                   push esi
// 00963086  8b742410             mov esi, dword ptr [esp + 0x10]
// 0096308a  57                   push edi
// 0096308b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0096308f  c644240800           mov byte ptr [esp + 8], 0
// 00963094  8b442408             mov eax, dword ptr [esp + 8]
// 00963098  50                   push eax
// 00963099  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0096309d  52                   push edx
// 0096309e  51                   push ecx
// 0096309f  50                   push eax
// 009630a0  56                   push esi
// 009630a1  57                   push edi
// 009630a2  e829fdffff           call 0x962dd0
// 009630a7  8d0476               lea eax, [esi + esi*2]
// 009630aa  83c418               add esp, 0x18
// 009630ad  c1e005               shl eax, 5
// 009630b0  03c7                 add eax, edi
// 009630b2  5f                   pop edi
// 009630b3  5e                   pop esi
// 009630b4  59                   pop ecx
// 009630b5  c20c00               ret 0xc
// library wildmagic-2-core/Intersection\WmlIntrTet3Tet3.cpp (function ?_Ufill@?$vector@V?$Tetrahedron3@N@Wml@@V?$allocator@V?$Tetrahedron3@N@Wml@@@std@@@std@@IAEPAV?$Tetrahedron3@N@Wml@@PAV34@IABV34@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Intersection/WmlIntrTet3Tet3.cpp
