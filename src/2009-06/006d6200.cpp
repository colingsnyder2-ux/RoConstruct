// from server: 100% by auto
// roc 2009-06 006d6200  unit: RBX::Mechanism  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d6200
//
// 006d6200  8b542408             mov edx, dword ptr [esp + 8]
// 006d6204  85d2                 test edx, edx
// 006d6206  763e                 jbe 0x6d6246
// 006d6208  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006d620c  8b442404             mov eax, dword ptr [esp + 4]
// 006d6210  56                   push esi
// 006d6211  85c0                 test eax, eax
// 006d6213  7428                 je 0x6d623d
// 006d6215  d901                 fld dword ptr [ecx]
// 006d6217  d918                 fstp dword ptr [eax]
// 006d6219  d94104               fld dword ptr [ecx + 4]
// 006d621c  d95804               fstp dword ptr [eax + 4]
// 006d621f  d94108               fld dword ptr [ecx + 8]
// 006d6222  d95808               fstp dword ptr [eax + 8]
// 006d6225  8b710c               mov esi, dword ptr [ecx + 0xc]
// 006d6228  89700c               mov dword ptr [eax + 0xc], esi
// 006d622b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 006d622e  897010               mov dword ptr [eax + 0x10], esi
// 006d6231  8b7114               mov esi, dword ptr [ecx + 0x14]
// 006d6234  897014               mov dword ptr [eax + 0x14], esi
// 006d6237  8b7118               mov esi, dword ptr [ecx + 0x18]
// 006d623a  897018               mov dword ptr [eax + 0x18], esi
// 006d623d  4a                   dec edx
// 006d623e  83c01c               add eax, 0x1c
// 006d6241  85d2                 test edx, edx
// 006d6243  77cc                 ja 0x6d6211
// 006d6245  5e                   pop esi
// 006d6246  c3                   ret 
// library ogre-1.4.9/OgreEdgeListBuilder.cpp (function ??$_Uninit_fill_n@PAUCommonVertex@EdgeListBuilder@Ogre@@IU123@V?$allocator@UCommonVertex@EdgeListBuilder@Ogre@@@std@@@std@@YAXPAUCommonVertex@EdgeListBuilder@Ogre@@IABU123@AAV?$allocator@UCommonVertex@EdgeListBuilder@Ogre@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreEdgeListBuilder.cpp
