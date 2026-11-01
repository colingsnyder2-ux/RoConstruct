// from server: 100% by auto
// roc 2010-06 00740880  unit: seg_00740000  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00740880
//
// 00740880  6a18                 push 0x18
// 00740882  e819710600           call 0x7a79a0
// 00740887  83c404               add esp, 4
// 0074088a  85c0                 test eax, eax
// 0074088c  7406                 je 0x740894
// 0074088e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00740892  8908                 mov dword ptr [eax], ecx
// 00740894  8d4804               lea ecx, [eax + 4]
// 00740897  85c9                 test ecx, ecx
// 00740899  7406                 je 0x7408a1
// 0074089b  8b542408             mov edx, dword ptr [esp + 8]
// 0074089f  8911                 mov dword ptr [ecx], edx
// 007408a1  8d4808               lea ecx, [eax + 8]
// 007408a4  85c9                 test ecx, ecx
// 007408a6  741c                 je 0x7408c4
// 007408a8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007408ac  56                   push esi
// 007408ad  8b32                 mov esi, dword ptr [edx]
// 007408af  8931                 mov dword ptr [ecx], esi
// 007408b1  8b7204               mov esi, dword ptr [edx + 4]
// 007408b4  897104               mov dword ptr [ecx + 4], esi
// 007408b7  8b7208               mov esi, dword ptr [edx + 8]
// 007408ba  897108               mov dword ptr [ecx + 8], esi
// 007408bd  8b520c               mov edx, dword ptr [edx + 0xc]
// 007408c0  89510c               mov dword ptr [ecx + 0xc], edx
// 007408c3  5e                   pop esi
// 007408c4  c20c00               ret 0xc
// library ogre-1.7.0/OgreTangentSpaceCalc.cpp (function ?_Buynode@?$list@UIndexRemap@TangentSpaceCalc@Ogre@@V?$allocator@UIndexRemap@TangentSpaceCalc@Ogre@@@std@@@std@@IAEPAU_Node@?$_List_nod@UIndexRemap@TangentSpaceCalc@Ogre@@V?$allocator@UIndexRemap@TangentSpaceCalc@Ogre@@@std@@@2@PAU342@0ABUIndexRemap@TangentSpaceCalc@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTangentSpaceCalc.cpp
