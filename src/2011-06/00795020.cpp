// from server: 100% by auto
// roc 2011-06 00795020  unit: seg_00790000  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00795020
//
// 00795020  6a18                 push 0x18
// 00795022  e837500700           call 0x80a05e
// 00795027  83c404               add esp, 4
// 0079502a  85c0                 test eax, eax
// 0079502c  7406                 je 0x795034
// 0079502e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00795032  8908                 mov dword ptr [eax], ecx
// 00795034  8d4804               lea ecx, [eax + 4]
// 00795037  85c9                 test ecx, ecx
// 00795039  7406                 je 0x795041
// 0079503b  8b542408             mov edx, dword ptr [esp + 8]
// 0079503f  8911                 mov dword ptr [ecx], edx
// 00795041  8d4808               lea ecx, [eax + 8]
// 00795044  85c9                 test ecx, ecx
// 00795046  741c                 je 0x795064
// 00795048  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0079504c  56                   push esi
// 0079504d  8b32                 mov esi, dword ptr [edx]
// 0079504f  8931                 mov dword ptr [ecx], esi
// 00795051  8b7204               mov esi, dword ptr [edx + 4]
// 00795054  897104               mov dword ptr [ecx + 4], esi
// 00795057  8b7208               mov esi, dword ptr [edx + 8]
// 0079505a  897108               mov dword ptr [ecx + 8], esi
// 0079505d  8b520c               mov edx, dword ptr [edx + 0xc]
// 00795060  89510c               mov dword ptr [ecx + 0xc], edx
// 00795063  5e                   pop esi
// 00795064  c20c00               ret 0xc
// library ogre-1.7.0/OgreTangentSpaceCalc.cpp (function ?_Buynode@?$list@UIndexRemap@TangentSpaceCalc@Ogre@@V?$allocator@UIndexRemap@TangentSpaceCalc@Ogre@@@std@@@std@@IAEPAU_Node@?$_List_nod@UIndexRemap@TangentSpaceCalc@Ogre@@V?$allocator@UIndexRemap@TangentSpaceCalc@Ogre@@@std@@@2@PAU342@0ABUIndexRemap@TangentSpaceCalc@Ogre@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreTangentSpaceCalc.cpp
