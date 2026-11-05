// from server: 100% by auto
// roc 2010-06 00888060  unit: CXTPTabPaintManager  size: 164 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00888060
//
// 00888060  8b442418             mov eax, dword ptr [esp + 0x18]
// 00888064  83f803               cmp eax, 3
// 00888067  0f8786000000         ja 0x8880f3
// 0088806d  ff2485f4808800       jmp dword ptr [eax*4 + 0x8880f4]
// 00888074  8b442404             mov eax, dword ptr [esp + 4]
// 00888078  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0088807c  8b542408             mov edx, dword ptr [esp + 8]
// 00888080  294804               sub dword ptr [eax + 4], ecx
// 00888083  2910                 sub dword ptr [eax], edx
// 00888085  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00888089  8b542410             mov edx, dword ptr [esp + 0x10]
// 0088808d  01480c               add dword ptr [eax + 0xc], ecx
// 00888090  015008               add dword ptr [eax + 8], edx
// 00888093  c3                   ret 
// 00888094  8b442404             mov eax, dword ptr [esp + 4]
// 00888098  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0088809c  8b542410             mov edx, dword ptr [esp + 0x10]
// 008880a0  2908                 sub dword ptr [eax], ecx
// 008880a2  01500c               add dword ptr [eax + 0xc], edx
// 008880a5  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008880a9  8b542408             mov edx, dword ptr [esp + 8]
// 008880ad  014808               add dword ptr [eax + 8], ecx
// 008880b0  295004               sub dword ptr [eax + 4], edx
// 008880b3  c3                   ret 
// 008880b4  8b442404             mov eax, dword ptr [esp + 4]
// 008880b8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008880bc  8b542410             mov edx, dword ptr [esp + 0x10]
// 008880c0  01480c               add dword ptr [eax + 0xc], ecx
// 008880c3  015008               add dword ptr [eax + 8], edx
// 008880c6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008880ca  8b542408             mov edx, dword ptr [esp + 8]
// 008880ce  294804               sub dword ptr [eax + 4], ecx
// 008880d1  2910                 sub dword ptr [eax], edx
// 008880d3  c3                   ret 
// 008880d4  8b442404             mov eax, dword ptr [esp + 4]
// 008880d8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008880dc  8b542408             mov edx, dword ptr [esp + 8]
// 008880e0  014808               add dword ptr [eax + 8], ecx
// 008880e3  295004               sub dword ptr [eax + 4], edx
// 008880e6  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008880ea  8b542410             mov edx, dword ptr [esp + 0x10]
// 008880ee  2908                 sub dword ptr [eax], ecx
// 008880f0  01500c               add dword ptr [eax + 0xc], edx
// 008880f3  c3                   ret 
// 008880f4  7480                 je 0x888076
// 008880f6  8800                 mov byte ptr [eax], al
// 008880f8  94                   xchg esp, eax
// 008880f9  808800b4808800       or byte ptr [eax - 0x777f4c00], 0
// 00888100  d480                 aam 0x80
// 00888102  8800                 mov byte ptr [eax], al
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?InflateRectEx@CAppearanceSet@CXTPTabPaintManager@@SAXAAVCRect@@V3@W4XTPTabPosition@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
