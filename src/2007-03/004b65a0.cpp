// from server: 100% by auto
// roc 2007-03 004b65a0  unit: seg_004b0000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004b65a0
//
// 004b65a0  8b442410             mov eax, dword ptr [esp + 0x10]
// 004b65a4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004b65a8  50                   push eax
// 004b65a9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004b65ad  6a00                 push 0
// 004b65af  52                   push edx
// 004b65b0  8b542410             mov edx, dword ptr [esp + 0x10]
// 004b65b4  50                   push eax
// 004b65b5  52                   push edx
// 004b65b6  e865e4ffff           call 0x4b4a20
// 004b65bb  c21000               ret 0x10
// library ogre-1.6.4/OgreResourceGroupManager.cpp (function ?declareResource@ResourceGroupManager@Ogre@@QAEXABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@00ABV?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@4@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreResourceGroupManager.cpp
