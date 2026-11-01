// from server: 100% by auto
// roc 2009-12 00633c10  unit: VAuthoringSettings::?$FactoryProduct  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00633c10
//
// 00633c10  51                   push ecx
// 00633c11  56                   push esi
// 00633c12  8bf1                 mov esi, ecx
// 00633c14  8b4610               mov eax, dword ptr [esi + 0x10]
// 00633c17  8bc8                 mov ecx, eax
// 00633c19  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 00633c1c  f7c1f8ffffff         test ecx, 0xfffffff8
// 00633c22  741a                 je 0x633c3e
// 00633c24  8b542404             mov edx, dword ptr [esp + 4]
// 00633c28  52                   push edx
// 00633c29  8d4e08               lea ecx, [esi + 8]
// 00633c2c  51                   push ecx
// 00633c2d  50                   push eax
// 00633c2e  83c0f8               add eax, -8
// 00633c31  50                   push eax
// 00633c32  e869fae8ff           call 0x4c36a0
// 00633c37  83c410               add esp, 0x10
// 00633c3a  834610f8             add dword ptr [esi + 0x10], -8
// 00633c3e  5e                   pop esi
// 00633c3f  59                   pop ecx
// 00633c40  c3                   ret 
// library templates-boost-1_34_1/vector_sp.cpp (function ?pop_back@?$vector@V?$shared_ptr@UT@@@boost@@V?$allocator@V?$shared_ptr@UT@@@boost@@@std@@@std@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 vector_sp.cpp
