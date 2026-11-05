// from server: 100% by EspClaude
// roc 2009-06 00498350  unit: VThreadLogManager::?$thread_specific_ptr::delete_data  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00498350
//
// 00498350  53                   push ebx
// 00498351  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00498355  56                   push esi
// 00498356  8b742410             mov esi, dword ptr [esp + 0x10]
// 0049835a  3bde                 cmp ebx, esi
// 0049835c  744d                 je 0x4983ab
// 0049835e  57                   push edi
// 0049835f  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00498363  8b46a0               mov eax, dword ptr [esi - 0x60]
// 00498366  83ee60               sub esi, 0x60
// 00498369  8d4e04               lea ecx, [esi + 4]
// 0049836c  83ef60               sub edi, 0x60
// 0049836f  51                   push ecx
// 00498370  8d4f04               lea ecx, [edi + 4]
// 00498373  8907                 mov dword ptr [edi], eax
// 00498375  ff1564e48900         call dword ptr [0x89e464]
// 0049837b  8d5620               lea edx, [esi + 0x20]
// 0049837e  52                   push edx
// 0049837f  8d4f20               lea ecx, [edi + 0x20]
// 00498382  ff1564e48900         call dword ptr [0x89e464]
// 00498388  8d463c               lea eax, [esi + 0x3c]
// 0049838b  50                   push eax
// 0049838c  8d4f3c               lea ecx, [edi + 0x3c]
// 0049838f  ff1564e48900         call dword ptr [0x89e464]
// 00498395  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 00498398  894f58               mov dword ptr [edi + 0x58], ecx
// 0049839b  8b565c               mov edx, dword ptr [esi + 0x5c]
// 0049839e  89575c               mov dword ptr [edi + 0x5c], edx
// 004983a1  3bf3                 cmp esi, ebx
// 004983a3  75be                 jne 0x498363
// 004983a5  8bc7                 mov eax, edi
// 004983a7  5f                   pop edi
// 004983a8  5e                   pop esi
// 004983a9  5b                   pop ebx
// 004983aa  c3                   ret 
// 004983ab  8b442414             mov eax, dword ptr [esp + 0x14]
// 004983af  5e                   pop esi
// 004983b0  5b                   pop ebx
// 004983b1  c3                   ret 
// copied from an identical function in another client (function ??$_Copy_backward_opt@PAUFileInfo@Ogre@@PAU12@Uforward_iterator_tag@std@@@std@@YAPAUFileInfo@Ogre@@PAU12@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreFileSystem.cpp