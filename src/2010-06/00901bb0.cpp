// from server: 100% by auto
// roc 2010-06 00901bb0  unit: VThreadLogManager::?$thread_specific_ptr::delete_data  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00901bb0
//
// 00901bb0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00901bb4  85c9                 test ecx, ecx
// 00901bb6  740e                 je 0x901bc6
// 00901bb8  8b01                 mov eax, dword ptr [ecx]
// 00901bba  8b10                 mov edx, dword ptr [eax]
// 00901bbc  c744240401000000     mov dword ptr [esp + 4], 1
// 00901bc4  ffe2                 jmp edx
// 00901bc6  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?destroyInstance@FileSystemArchiveFactory@Ogre@@UAEXPAVArchive@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
