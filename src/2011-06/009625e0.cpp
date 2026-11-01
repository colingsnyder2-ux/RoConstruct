// from server: 100% by auto
// roc 2011-06 009625e0  unit: VThreadLogManager::?$thread_specific_ptr::delete_data  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009625e0
//
// 009625e0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 009625e4  85c9                 test ecx, ecx
// 009625e6  740e                 je 0x9625f6
// 009625e8  8b01                 mov eax, dword ptr [ecx]
// 009625ea  8b10                 mov edx, dword ptr [eax]
// 009625ec  c744240401000000     mov dword ptr [esp + 4], 1
// 009625f4  ffe2                 jmp edx
// 009625f6  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?destroyInstance@FileSystemArchiveFactory@Ogre@@UAEXPAVArchive@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
