// from server: 100% by auto
// roc 2007-03 00707440  unit: seg_00700000  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00707440
//
// 00707440  8b442418             mov eax, dword ptr [esp + 0x18]
// 00707444  83f803               cmp eax, 3
// 00707447  0f8786000000         ja 0x7074d3
// 0070744d  ff2485d4747000       jmp dword ptr [eax*4 + 0x7074d4]
// 00707454  8b442404             mov eax, dword ptr [esp + 4]
// 00707458  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0070745c  8b542408             mov edx, dword ptr [esp + 8]
// 00707460  294804               sub dword ptr [eax + 4], ecx
// 00707463  2910                 sub dword ptr [eax], edx
// 00707465  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00707469  8b542410             mov edx, dword ptr [esp + 0x10]
// 0070746d  01480c               add dword ptr [eax + 0xc], ecx
// 00707470  015008               add dword ptr [eax + 8], edx
// 00707473  c3                   ret 
// 00707474  8b442404             mov eax, dword ptr [esp + 4]
// 00707478  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0070747c  8b542410             mov edx, dword ptr [esp + 0x10]
// 00707480  2908                 sub dword ptr [eax], ecx
// 00707482  01500c               add dword ptr [eax + 0xc], edx
// 00707485  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00707489  8b542408             mov edx, dword ptr [esp + 8]
// 0070748d  014808               add dword ptr [eax + 8], ecx
// 00707490  295004               sub dword ptr [eax + 4], edx
// 00707493  c3                   ret 
// 00707494  8b442404             mov eax, dword ptr [esp + 4]
// 00707498  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0070749c  8b542410             mov edx, dword ptr [esp + 0x10]
// 007074a0  01480c               add dword ptr [eax + 0xc], ecx
// 007074a3  015008               add dword ptr [eax + 8], edx
// 007074a6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007074aa  8b542408             mov edx, dword ptr [esp + 8]
// 007074ae  294804               sub dword ptr [eax + 4], ecx
// 007074b1  2910                 sub dword ptr [eax], edx
// 007074b3  c3                   ret 
// 007074b4  8b442404             mov eax, dword ptr [esp + 4]
// 007074b8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007074bc  8b542408             mov edx, dword ptr [esp + 8]
// 007074c0  014808               add dword ptr [eax + 8], ecx
// 007074c3  295004               sub dword ptr [eax + 4], edx
// 007074c6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007074ca  8b542410             mov edx, dword ptr [esp + 0x10]
// 007074ce  2908                 sub dword ptr [eax], ecx
// 007074d0  01500c               add dword ptr [eax + 0xc], edx
// 007074d3  c3                   ret 
// 007074d4  54                   push esp
// 007074d5  7470                 je 0x707547
// 007074d7  00747470             add byte ptr [esp + esi*2 + 0x70], dh
// 007074db  0094747000b474       add byte ptr [esp + esi*2 + 0x74b40070], dl
// 007074e2  7000                 jo 0x7074e4
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?InflateRectEx@CXTPTabPaintManagerAppearanceSet@@SAXAAVCRect@@V2@W4XTPTabPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
