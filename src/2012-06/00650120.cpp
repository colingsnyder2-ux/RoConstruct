// roc 2012-06 00650120  unit: seg_00650000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00650120
//
// 00650120  8b442408             mov eax, dword ptr [esp + 8]
// 00650124  8b10                 mov edx, dword ptr [eax]
// 00650126  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0065012a  8911                 mov dword ptr [ecx], edx
// 0065012c  8b4004               mov eax, dword ptr [eax + 4]
// 0065012f  894104               mov dword ptr [ecx + 4], eax
// 00650132  c3                   ret 
// library ogre-1.4.9/OgreGpuProgramManager.cpp (function ??$_Checked_assign_from_base@Vconst_iterator@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@@std@@YAXAAVconst_iterator@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@0@ABV120@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreGpuProgramManager.cpp
