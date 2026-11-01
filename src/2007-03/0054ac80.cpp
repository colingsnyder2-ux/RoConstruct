// from server: 100% by colin
// roc 2007-03 0054ac80  unit: seg_00540000  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0054ac80
//
// 0054ac80  8b4158               mov eax, dword ptr [ecx + 0x58]
// 0054ac83  c1e803               shr eax, 3
// 0054ac86  a801                 test al, 1
// 0054ac88  741c                 je 0x54aca6
// 0054ac8a  8b514c               mov edx, dword ptr [ecx + 0x4c]
// 0054ac8d  8b4150               mov eax, dword ptr [ecx + 0x50]
// 0054ac90  56                   push esi
// 0054ac91  8b7114               mov esi, dword ptr [ecx + 0x14]
// 0054ac94  8916                 mov dword ptr [esi], edx
// 0054ac96  8b7124               mov esi, dword ptr [ecx + 0x24]
// 0054ac99  8916                 mov dword ptr [esi], edx
// 0054ac9b  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 0054ac9e  03c2                 add eax, edx
// 0054aca0  2bc2                 sub eax, edx
// 0054aca2  8901                 mov dword ptr [ecx], eax
// 0054aca4  5e                   pop esi
// 0054aca5  c3                   ret 
// 0054aca6  8b5114               mov edx, dword ptr [ecx + 0x14]
// 0054aca9  c70200000000         mov dword ptr [edx], 0
// 0054acaf  8b4124               mov eax, dword ptr [ecx + 0x24]
// 0054acb2  c70000000000         mov dword ptr [eax], 0
// 0054acb8  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 0054acbb  c70100000000         mov dword ptr [ecx], 0
// 0054acc1  c3                   ret 
// copied from an identical function in another client (function ?init_put_area@?$indirect_streambuf@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@U?$char_traits@D@std@@V?$allocator@D@5@Uoutput@23@@detail@iostreams@boost@@EAEXXZ)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp