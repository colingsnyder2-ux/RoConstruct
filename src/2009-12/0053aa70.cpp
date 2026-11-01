// from server: 100% by auto
// roc 2009-12 0053aa70  unit: G3D::VRay::?$holder  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0053aa70
//
// 0053aa70  6a1c                 push 0x1c
// 0053aa72  e8e98d2b00           call 0x7f3860
// 0053aa77  83c404               add esp, 4
// 0053aa7a  85c0                 test eax, eax
// 0053aa7c  7444                 je 0x53aac2
// 0053aa7e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0053aa82  8b542408             mov edx, dword ptr [esp + 8]
// 0053aa86  8908                 mov dword ptr [eax], ecx
// 0053aa88  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0053aa8c  894808               mov dword ptr [eax + 8], ecx
// 0053aa8f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0053aa93  895004               mov dword ptr [eax + 4], edx
// 0053aa96  8b11                 mov edx, dword ptr [ecx]
// 0053aa98  89500c               mov dword ptr [eax + 0xc], edx
// 0053aa9b  8b5104               mov edx, dword ptr [ecx + 4]
// 0053aa9e  895010               mov dword ptr [eax + 0x10], edx
// 0053aaa1  8b4908               mov ecx, dword ptr [ecx + 8]
// 0053aaa4  894814               mov dword ptr [eax + 0x14], ecx
// 0053aaa7  85c9                 test ecx, ecx
// 0053aaa9  740c                 je 0x53aab7
// 0053aaab  83c104               add ecx, 4
// 0053aaae  ba01000000           mov edx, 1
// 0053aab3  f00fc111             lock xadd dword ptr [ecx], edx
// 0053aab7  8a4c2414             mov cl, byte ptr [esp + 0x14]
// 0053aabb  884818               mov byte ptr [eax + 0x18], cl
// 0053aabe  c6401900             mov byte ptr [eax + 0x19], 0
// 0053aac2  c21400               ret 0x14
// library templates-boost-1_34_1/map_int_sp.cpp (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HV?$shared_ptr@UT@@@boost@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$shared_ptr@UT@@@boost@@@std@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$shared_ptr@UT@@@boost@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHV?$shared_ptr@UT@@@boost@@@std@@@4@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHV?$shared_ptr@UT@@@boost@@@2@D@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 map_int_sp.cpp
