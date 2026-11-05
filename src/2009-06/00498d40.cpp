// from server: 100% by EspClaude
// roc 2009-06 00498d40  unit: std::D::DU?$char_traits::V?$basic_string::V?$vector::?$SharedPtr  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00498d40
//
// 00498d40  6aff                 push -1
// 00498d42  6878ef8600           push 0x86ef78
// 00498d47  64a100000000         mov eax, dword ptr fs:[0]
// 00498d4d  50                   push eax
// 00498d4e  64892500000000       mov dword ptr fs:[0], esp
// 00498d55  51                   push ecx
// 00498d56  56                   push esi
// 00498d57  57                   push edi
// 00498d58  8bf9                 mov edi, ecx
// 00498d5a  8b7704               mov esi, dword ptr [edi + 4]
// 00498d5d  89742408             mov dword ptr [esp + 8], esi
// 00498d61  85f6                 test esi, esi
// 00498d63  7420                 je 0x498d85
// 00498d65  8bce                 mov ecx, esi
// 00498d67  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00498d6f  e85cf4f7ff           call 0x4181d0
// 00498d74  8b06                 mov eax, dword ptr [esi]
// 00498d76  50                   push eax
// 00498d77  e8b6fc2700           call 0x718a32
// 00498d7c  56                   push esi
// 00498d7d  e8b0fc2700           call 0x718a32
// 00498d82  83c408               add esp, 8
// 00498d85  8b4f08               mov ecx, dword ptr [edi + 8]
// 00498d88  51                   push ecx
// 00498d89  e8a4fc2700           call 0x718a32
// 00498d8e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00498d92  83c404               add esp, 4
// 00498d95  5f                   pop edi
// 00498d96  5e                   pop esi
// 00498d97  64890d00000000       mov dword ptr fs:[0], ecx
// 00498d9e  83c410               add esp, 0x10
// 00498da1  c3                   ret 
// copied from an identical function in another client (function ?destroy@?$SharedPtr@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreResourceGroupManager.cpp